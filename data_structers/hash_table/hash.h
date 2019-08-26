#ifndef HASH_H
#define HASH_H

typedef struct Hash* hash;
typedef int (*compareFunc)(void*,void*);
typedef unsigned long (*hashFunc)(void*); 
typedef void (*destroyFunc)(void* element);
typedef enum{OK, ALLOCATION_FAILED, NOT_IN_TABLE, ALREADY_IN_TABLE, NO_TABLE}hashStatus;

hash hashtableCreate(int size,compareFunc comp,hashFunc hf);
void hashtableDestroy(hash hashP,destroyFunc des, destroyFunc des2);
hashStatus hashtableInsert(hash hashP,void* val, void* key);
hashStatus hashtableUpdate(hash hashP,void* val, void* key);
hashStatus hashtableDelete(hash hashP, void* key,destroyFunc des,destroyFunc des2);
hashStatus hashtableFind(hash hashP, void* key, void** item);
hashStatus hashtableForEach(hash hashP, compareFunc someFunc);

#endif
