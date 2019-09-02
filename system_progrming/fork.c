#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

int splitInput(char* Input,char** argv,int size );
void removeNL(char* str);

int main(){
	pid_t cpid=0;
	char command[32]="s";
	char exit[5]="exit";
	char arg[16]="";
	char arg1[16]="";
	char arg2[16]="";
	char*  argv[]={NULL,NULL,NULL,NULL};
	int ans=0;
	while((ans=strcmp(command,exit))!=0){
		printf(">> ");			
		if( fgets (command, 60, stdin)==NULL) {
			break;
   		}
		removeNL(command);
		argv[0]=arg;
		argv[1]=arg1;
		argv[2]=arg2;
		splitInput(command,argv,3);
		cpid=fork();
		if(cpid>0){
			waitpid(cpid,NULL,0);
		}
		else{
			printf("%s",argv[0]);	
			printf("%s",argv[1]);
			printf("%s",argv[2]);
			execv(command,argv);
			break;
		}
	}
	return 0;
}

int splitInput(char* Input,char** argv,int size ){
	int i=0;
	int j=0;
	int k=0;
	if(Input==NULL){
		return -1;
	}
	while(Input[i]!='\0'){
		if(Input[i]==' '){
			argv[j][k]='\0';
			k=0;
			j++;
			if(j>=size){
				argv[j]=NULL;
				return j;
			}
		}
		else{
			argv[j][k]=Input[i];	
			k++;
		}
		i++;
	}
	argv[j][k]='\0';
	j++;
	argv[j]=NULL;
	return j;
}

void removeNL(char* str){
	int i=0;
	for(i=0;str[i]!='\0';i++){
		if(str[i]=='\n'){
			str[i]='\0';
			return;
		}
	}
}













