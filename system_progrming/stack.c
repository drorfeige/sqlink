#include <stdio.h>

int a(int hack);
int b();

int main(int c,char** argv){
	int n=7;
	n=a(n);
	printf("here\n");
	return 0;

}

int a(int hack){ 
	int hack2=8;
	/*(&hack2+2)=b;*/
	*(&hack-1)=b;
	printf("this is a. will attempt to return to b\n");		
	return 0;
}

int b(){
	printf("this is b\n");
	return 0;
}


































































