#ifndef DA_H
#define DA_H

typedef struct {
	int* arr;
	int capacity;
	int index;
}DA;

DA* createDA(int Capacity);
void destroyDA(DA* array);
int insert(DA* arr,int num);
void printDA(DA* array);

#endif
