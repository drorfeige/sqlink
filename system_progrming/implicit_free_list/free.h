#ifndef FREE_H
#define FREE_H 





void* memInit(void* buffer,unsigned int size);
void* memAlloc(void* buffer,unsigned int size);
void memFree(void* buffer);

#endif
