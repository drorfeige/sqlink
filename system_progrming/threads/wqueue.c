#include "wqueue.h"
#include <semaphore.h>
#include <mutex.h>



struct queue{
	void* line[8];
	int m_head;
	int m_tail;
};

sem_t se;
sem_t sf;

static void semaphoreInit(){
	

}
queue* createQueue(){
	queue* q;
	q=(queue*)malloc(sizeof(q));
	return q;
}














