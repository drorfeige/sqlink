#ifndef WQUEUE_H
#define WQUEUE_H

typedef struct queue;

queue* createQueue();
int readMsg(queue* q,void** msg);
int writeMsg(queue* q, void** msg);

void destroyQueue(queue* q);




#endif











