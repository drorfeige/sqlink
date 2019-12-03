#include "mythread.h"
#include <iostream>

using namespace std;

class ChildThread: public MyThread{
	public:
		virtual void run(void* args=NULL){
			cout << "cpp thread number: " << *((int*)args) << endl;
		}

};


int main(){
	ChildThread t1;
	int* ip=(int*)malloc(sizeof(int));
	if(ip){
		*ip=5;
		t1.start((void*)ip);
		t1.join();
	}
	else{
		cout << "failure allocating memory "<< endl;
	}
	return 0;
}
