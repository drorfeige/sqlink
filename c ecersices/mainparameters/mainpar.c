#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc,char *argv[]){
	char str[32]="";
	int i=0;
	if(argc==3){
		strcpy(str,argv[1]);
		if (isdigit(str[0])){
			for(i=0; str[i]!='\0';i++){
				if(isdigit(str[i])==0){
					printf("wrong input\n");
					return 0;
				}
			}
			strcpy(str,argv[2]);
			for(i=0; str[i]!='\0';i++){
				if(isalpha(str[i])==0){
					printf("wrong input\n");
						return 0;
				}
			}
			printf("%s is %s years old\n",argv[2],argv[1]);
		}
		else{
			for(i=0; str[i]!='\0';i++){
				if(isalpha(str[i])==0){
					printf("wrong input\n");
					return 0;
				}
			}
			strcpy(str,argv[2]);
			for(i=0; str[i]!='\0';i++){
				if(isdigit(str[i])==0){
					printf("wrong input\n");
						return 0;
				}
			}
			printf("%s is %s years old\n",argv[1],argv[2]);
		}
	}	
	;
	return;
}
