#ifndef DA_H
#define DA_H

typedef int* intPtr;
typedef struct{
	int capacity;
	int index;
	intPtr* arr;
}DA_t;

DA_t* createDA(int capacity);
int insert(DA_t* array,intPtr Num);
void printDA(DA_t* array);
void destroyDA(DA_t* array);

#endif
