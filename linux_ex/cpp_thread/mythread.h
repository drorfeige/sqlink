#ifndef MY_THREAD_H
#define MY_THREAD_H

#include <pthread.h>
#include <iostream>




struct par{
	void* cl;
	void* m_args;
};

class MyThread{
	public:
		virtual ~MyThread(){}
		MyThread(){}
		virtual void run(void* args=NULL)=0;
		int join(){ 
			int retval=pthread_join(thread_id,NULL); 
			if(retval!=0) throw -1;
		}
		int start(void* args=NULL){
			struct par* p1 = (struct par*)malloc(sizeof(struct par));
			p1->cl=(void*)this;
			p1->m_args=args;
			int retval=pthread_create(&thread_id,NULL, secret_c,(void*)p1);
			if(retval!=0) throw -1;
		}
		static void* secret_c(void* myClass){
			std::cout<< "entered secret c" << std::endl;
			struct par* p=(struct par*) myClass;
			MyThread* t=(MyThread*) p->cl; 
			t->run(p->m_args);
			std::cout<< *((int*)(p->m_args)) << std::endl;
		}
	private:
		MyThread(const MyThread& mt){}
		MyThread& operator=(const MyThread& mt){}
		pthread_t thread_id;
};


#endif










