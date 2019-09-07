#ifndef FILES_H
#define FILES_H

int isDir(char* pathname);
void scanDir(char *basePath,void* hashT);
void isDup(char* key, char* path, void* hp);

#endif
