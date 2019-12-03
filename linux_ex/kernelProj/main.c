#include <linux/module.h> /* for MODULE_*, module_* */
#include <linux/fs.h> /* for fops */
#include <linux/device.h> /* for device_create */
#include <linux/moduleparam.h> /* for module_param, MODULE_PARM_DESC... */
#include <linux/init.h> /* for __init, __exit */
#include <linux/kfifo.h>/* for fifo */
#include <linux/cdev.h> /* for cdev_* */
#include <linux/slab.h> /* for kmalloc, kfree */
#include "msgq.h" /* for msg struct*/
#include <linux/wait.h> /* for wait_queue_head_t and ops on it */
#include <linux/uaccess.h> /* for copy_to_user, access_ok */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Dror Feige");
MODULE_DESCRIPTION("A simple implementation of a mesage queue");

#define Q_SIZE	128
#define Q_COUNT 8

/*this is declarations for the queue*/
static struct my_q_t* q;


typedef struct my_kmsg_t {
	int m_size;
	char* m_data;
}my_kmsg_t;


struct my_q_t{
	struct kfifo q_t;
	/* some kind of mutex or condition variable*/
	struct device *q_device;
};

static my_q_t_ctor(struct my_q_t* p) {
	// initalize
}

static my_q_t_dtor(struct my_q_t* p) {
	// tear down
}

static dev_t first_dev;

static int open_msgq(struct inode* inode,struct file* file){
	/* hide the pipe in the private_data of the struct file... */
	int the_q_number = iminor(inode)-MINOR(first_dev);
	struct my_q_t* m_q = q+the_q_number;
	file->private_data = m_q;
	return 0;
}

static long MRead(struct file* f,unsigned long message_t){
	int err;
	struct my_q_t* mq;
	my_kmsg_t* toRead;
	pr_info("%s: entered read\n", THIS_MODULE->name);
	mq=(struct my_q_t*)f->private_data;
	pr_info("%s: got private_data\n", THIS_MODULE->name);
	if(kfifo_get(&mq->q_t,&toRead)==0) {
		pr_err("%s: problems with kfifo_get\n",THIS_MODULE->name);
		return -ENOTTY;
	}
	pr_info("%s: got got data from fifo\n", THIS_MODULE->name);
	if((err = copy_to_user((void*)message_t, toRead->m_data, toRead->m_size))){
		goto err_copy;
	}	
	pr_info("%s: first copy successfull\n", THIS_MODULE->name);
	err=toRead->m_size;
	pr_info("%s: address of element %p\n", THIS_MODULE->name,toRead);
err_copy:
	kfree(toRead->m_data);
	pr_info("%s: freed data\n", THIS_MODULE->name);
	kfree(toRead);
	pr_info("%s: freed fifo element\n", THIS_MODULE->name);
	return (long)err;
}

static long MWrite(struct file* f,unsigned long message_t){
	int err;
	my_msg_t toWrite;
	my_kmsg_t* kw;
	struct my_q_t* mq= (struct my_q_t*)f->private_data;
	pr_info("entered write\n");
	if((err = copy_from_user((void*)&toWrite,(void*)message_t, sizeof(my_msg_t)))){
		goto err_nothing;
	}
	pr_info("first copy success\n");
	kw=(my_kmsg_t*)kmalloc(sizeof(my_kmsg_t),GFP_KERNEL);
	if(!kw){
		err=-ENOBUFS;
		goto err_nothing;
	}
	pr_info("firrst malloc success\n");
	kw->m_data=(char*)kmalloc(toWrite.m_size,GFP_KERNEL);
	if(IS_ERR(kw->m_data)){
		pr_err("%s: problems with kmalloc\n", THIS_MODULE->name);
		err=PTR_ERR(kw->m_data);
		goto err_alloc;
	}
	pr_info("second malloc success\n");
	if((err = copy_from_user(kw->m_data, toWrite.m_data, toWrite.m_size))){
		goto err_copy;
	}
	pr_info("second copy success\n");
	pr_info("%s: address of element %p\n", THIS_MODULE->name,kw);
	kw->m_size=toWrite.m_size;
	kfifo_put(&mq->q_t, (unsigned long)kw);
	err_copy:
		kfree(kw->m_data);
	err_alloc:
		kfree(kw);
	err_nothing:
		return err;
}

static long msgq_ioctl(struct file *f,unsigned int cmd,unsigned long arg){
	struct kfifo my_fifo;
	int err;
	long int val;
	long int back_val;
	switch(cmd) {
		case SEND_MESSAGE:
			return MWrite(f,arg);
		case RECIEVE_MESSAGE:
			return MRead(f,arg);
		case FIFO_DEBUG:
			err=kfifo_alloc(&my_fifo, Q_SIZE, GFP_KERNEL);
			if(err) {
				pr_err("%s: problems with kfifo_alloc\n", THIS_MODULE->name);
				return err;
			}
			val=67;
			kfifo_put(&my_fifo, val);
			kfifo_get(&my_fifo, &back_val);
			pr_info("%s: back_val is %ld\n", THIS_MODULE->name, back_val);
			return 0;
		default:
			return -ENOTTY;
	}
	return -ENOTTY;
}

/*static int msgq_release(struct inode *inode, struct file *file){
	return 0;
}*/
/* this is the operations table */
static const struct file_operations q_fops = {
	.owner = THIS_MODULE,
	.open = open_msgq,
	/*.release = msgq_release,*/
	.unlocked_ioctl = msgq_ioctl,
};

/* this variable will store the class */
static struct class *my_class;

static int first_minor;

static struct cdev cdev;

static int __init msgq_init(void){
	int err;
	unsigned int i,j;

	q = kmalloc(sizeof(struct my_q_t)*Q_COUNT, GFP_KERNEL);	
	if (IS_ERR(q)) {
		pr_err("kmalloc\n");
		err = PTR_ERR(q);
		goto err_nothing;
	}
	/* initialize all queues */
	for (i = 0; i < Q_COUNT; i++){
		err = kfifo_alloc(&q[i].q_t, Q_SIZE, GFP_KERNEL);
		if(err){
			goto err_alloc;
		}
	}
	/* allocate our own range of devices */
	err = alloc_chrdev_region(&first_dev, first_minor, Q_COUNT,
			THIS_MODULE->name);
	if (err) {
		pr_err("cannot alloc_chrdev_region\n");
		goto err_final;
	}
	pr_info("allocated the region\n");
	/* add the cdev structure */
	cdev_init(&cdev, &q_fops);
	err = cdev_add(&cdev, first_dev, Q_COUNT);
	if (err) {
		pr_err("cannot cdev_add\n");
		goto err_register;
	}
	pr_info("added the cdev\n");
	/* this is creating a new class (/proc/devices) */
	my_class = class_create(THIS_MODULE, THIS_MODULE->name);
	if (IS_ERR(my_class)) {
		pr_err("class_create\n");
		err = PTR_ERR(my_class);
		goto err_cdev_del;
	}
	pr_info("created the class\n");
	for (j = 0; j < Q_COUNT; j++) {
		/* and now lets auto-create a /dev/ node */
		q[j].q_device = device_create(my_class, NULL,
			MKDEV(MAJOR(first_dev), MINOR(first_dev)+j),
			NULL, "%s%d", THIS_MODULE->name, j);
		if (IS_ERR(q[j].q_device)) {
			pr_err("device_create\n");
			err = PTR_ERR(q[j].q_device);
			goto err_class;
		}
	}
	pr_info(KBUILD_MODNAME " loaded successfully\n");
	return 0;


	err_class:
		class_destroy(my_class);
	err_cdev_del:
		cdev_del(&cdev);
	err_register:
		unregister_chrdev_region(first_dev, Q_COUNT);
	err_final:
		kfifo_free(&(q[i].q_t));
	err_alloc:
		for(j=0;j<i;j++){
			kfifo_free(&(q[j].q_t));
		}
		kfree(q);
	err_nothing:
		return err;
}




static void __exit msgq_exit(void){
	int i;
	my_msg_t* toErase;
	for (i = 0; i < Q_COUNT; i++){
		device_destroy(my_class, MKDEV(MAJOR(first_dev),MINOR(first_dev)+i));
	}
	class_destroy(my_class);
	cdev_del(&cdev);
	unregister_chrdev_region(first_dev, Q_COUNT);
	for (i = 0; i < Q_COUNT; i++){
		/* free individual messages in each queue */
		while(!kfifo_is_empty (&(q[i].q_t))){
			kfifo_get(&q[i].q_t,&toErase);
			kfree(toErase->m_data);
			kfree(toErase);
		}
		kfifo_free(&(q[i].q_t));
	}
	kfree(q);
	pr_info(KBUILD_MODNAME " unloaded successfully\n");
}


module_init(msgq_init);
module_exit(msgq_exit);







































