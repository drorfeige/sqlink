#include <stdio.h>
#include <stdlib.h>

struct Node{
	int m_val;
	struct Node* m_next;
}; 

typedef struct Node node;

int isLoop(node* nd){
	node* nd1=nd;
	node* nd2=nd;	
	while(nd2!=NULL){
		nd1=nd1->m_next;
		if(nd2->m_next==NULL){
			break;
		}
		nd2=nd2->m_next->m_next;
		if(nd2==nd1){
			return 1;
		}
	}
	return 0;
}

node* middleNode(node* nd){
	node* nd1=nd;
	node* nd2=nd;
	while(nd2!=NULL){
		nd1=nd1->m_next;
		if(nd2->m_next==NULL){
			break;
		}
		nd2=nd2->m_next->m_next;
	}
	return nd1;
}

node* flipList(node* nd){
	node* former=0;
	node* Next=0;
	node* temp=0;
	if(nd==NULL){
		return nd;
	}
	if(nd->m_next==NULL){
		return nd;
	}
	if(nd->m_next->m_next==NULL){
		temp=nd->m_next;
		nd->m_next->m_next=nd;
		nd->m_next=NULL;
		return temp;
	}
	Next=nd->m_next->m_next;
	nd->m_next->m_next=nd;
	former=nd->m_next;
	nd->m_next=NULL;
	while(Next->m_next!=NULL){
		temp=Next->m_next;
		Next->m_next=former;
		former=Next;
		Next=temp;
	}
	Next->m_next=former;
	return Next;
}

node* commonNode(node* nd1, node* nd2){
	int counter1=0;
	int counter2=0;
	int i=0;
	node* ndp1=nd1;
	node* ndp2=nd2;
	while(ndp1!=NULL){
		ndp1=ndp1->m_next;
		counter1++;
	}
	while(ndp2!=NULL){
		ndp2=ndp2->m_next;
		counter2++;
	}
	if(counter1>counter2){
		for(i=0;i<counter1-counter2;i++){
			nd1=nd1->m_next;
		}
	}
	else if (counter2>counter1){
		for(i=0;i<counter2-counter1;i++){
			nd2=nd2->m_next;
		}
	}
	while(nd1!=nd2){
		nd1=nd1->m_next;
		nd2=nd2->m_next;
	}
	return nd1;
}

node* createList(int size){
	node* header=0;
	node* nextNode=0;
	node* newNode=0;
	int i=0;
	if((header=(node*)malloc(sizeof(node)))==NULL){
		return NULL;
	}
	header->m_val=1;
	header->m_next=NULL;
	nextNode=header;
	for(i=2;i<=size;i++){
		if((newNode=(node*)malloc(sizeof(node)))==NULL){
			return header;
		}
		newNode->m_val=i;
		newNode->m_next=NULL;
		nextNode->m_next=newNode;
		nextNode=newNode;
	}
	return header;
}

void printList(node* head){
	while(head!=NULL){
		printf("%d\n",head->m_val);
		head=head->m_next;
	}
}

void destroyList(node* head){
	node* temp=0; 
	while(head!=NULL){
		temp=head->m_next;
		free(head);
		head=temp;
	}
}

int getSize(){
	int size=0;
	do{
		printf("choose list length:\n");
		scanf("%d",&size);
	}while(size<1);
	return size;
}

int connectNode(node* head, node* target){
	if(head==NULL){
		return 0;
	}
	while(head->m_next!=NULL){
		head=head->m_next;
	}
	head->m_next=target;
	return 1;
}


int main(int argc,char** argv){
	node* head=NULL;
	node* head2=NULL;
	node* nd=NULL;
	int size;
	int ans;
	size=getSize();
	head=createList(size);
	printf("original list\n");
	printList(head);
	nd=middleNode(head);
	printf("half of list\n");
	printList(nd);
	if((isLoop(head))==0){
		printf("no loop in list\n");
	}
	/***uncomment code below to create loop*******/
	/*if((connectNode(head, nd))!=0){
		if((isLoop(head))==0){
			printf("no loop in list\n");
		}
		else{
			printf("there is loop in list\n");
		}
	}*/
	/*************uncomment code below to flip list********************/
	/*head=flipList(head);
	printf("fliped list\n");
	printList(head);*/
	/***************uncomment code below to create a second connected list******************************/
	size=getSize();
	head2=createList(size);
	if((ans=connectNode(head2, nd))!=0){
		printf("new list\n");
		printList(head2);
		nd=commonNode(head2, head);
		printList(nd);
	}
	/**************************************************/
	destroyList(head);
	destroyList(head2);
	return 0;
}



















