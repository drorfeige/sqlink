#include "files.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "MD5.h"


int isDir(char* pathname){
	struct stat sb;

	if(stat(pathname, &sb) == 0 && S_ISDIR(sb.st_mode)){
		return 1;
	}
	return 0;
}


void scanDir(char *basePath,void* hashT){
	char path[1000];
	struct dirent *dp;
	char* key;
	char* Path;
	DIR *dir = opendir(basePath);
	if (!dir){
		return;
	}
	while ((dp = readdir(dir)) != NULL){
		if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0){
		strcpy(path, basePath);
		strcat(path, "/");
		strcat(path, dp->d_name);
		key=(void*)malloc(64*sizeof(char));
		Path=(void*)malloc(128*sizeof(char));
		if(key==NULL || Path==NULL){
			free(key);
			free(Path);
			printf("allocation error\n");
			return;
		}
		strcpy(Path, path);
		if((MD5Create(path,key)==1)){
			isDup(key, Path,(hash)hashT);
		}	
		scanDir(path,hashT);
		}
	}
	closedir(dir);
}


void isDup(char* key, char* path, void* hp){
	hashStatus status;
	char dup[64];
	if((status=hashtableInsert((hash)hp,(void*) path, (void*) key))==ALREADY_IN_TABLE){
		if((status=hashtableFind((hash)hp, (void*) key, (void**) &dup))==OK){
			printf("found duplicate at:  %s  and  ",path);
			printf("%s\n",dup);	
		}	
	}
}


