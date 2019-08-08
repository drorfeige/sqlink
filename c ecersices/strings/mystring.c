#include <stdio.h>

void mystrcat(char* str1,char* str2);
int mystrcmp(char* str1,char* str2);
void mystrcpy(char* str1,char*str2);
void getstring(char* str);
void printstring(char* str);

int main(){
	int bigger;
	char str1[32];
	char str2[32];
	char space[2]=" ";
	getstring(str1);
	getstring(str2);
	bigger=mystrcmp(str1,str2);
	if(bigger){
		printf("string %d is bigger\n",bigger);/* 0 is equal. 1 is str1 is bigger. logic that function was written by is A is bigger than B */
	}
	else{
		printf("the strings are equal\n");
	}
	mystrcat(str1,space);
	mystrcat(str1,str2);
	printf("string1 after strcat+space between\n");
	printstring(str1);
	mystrcpy(str1,str2);
	printf("string1 after string2 is copied\n");
	printstring(str1);
	return 0;
}

void mystrcat(char* str1,char* str2){
	int i=0;
	int j=0;
	while(str1[i]!='\0'){
		i++;
	}
	while(str2[j]!='\0'){
		str1[i]=str2[j];
		j++;
		i++;
	}
	str1[i]='\0';
}

void printstring(char *str){
	printf("%s\n",str);
}

void getstring(char* str){
	/*do {*/
		printf("enter string:\n");
		scanf("%s",str);
	/*}while(strlen(str)==1);*/

}

int mystrcmp(char* str1,char* str2){
	int i=0;
	while(str1[i]==str2[i]){
		if (str1[i]=='\0'){
			return 0;
		}
		i++;
	}
	/*if (str1[i]=='\0'){
		return 1;
	}
	else if(str2[i]=='\0'){
		return 2;
	}*/
	return (str1[i]>str2[i])?2:1;
}

void mystrcpy(char* str1,char*str2){
	int i=0;
	while(str2[i]!='\0'){
		str1[i]=str2[i];
		i++;
	}
	str1[i]='\0';
}







