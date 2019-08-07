#include <stdio.h>
int getNum();
void func1();
void func2();
void func3();

int main(){
	func1();
	func2();
	func3();
	return 0;
}

int getNum(){
	int N=0; 
	/*while(N<=0 || N>10){*/
	while(1){
		printf("choose an integer(>0 and <10):\n");
		scanf("%d",&N);
		if(N>0 && N<=10){
			printf("you chose %d\n",N);
			break;
		}
		else {
			printf("wrong entry\n");
		}
	}
	return N;
}
void func1(){
	int N=0,i=1,j=0;
	N=getNum();
	for (i=1; i<=N; i++){
		for (j=0;j<i;j++){
			printf("*");
		}
		printf("\n");			
	}
}
void func2(){
	int N=0,i=1,j=0;
	N=getNum();
	for (i=1; i<=N; i++){
		for (j=0;j<i;j++){
			printf("*");
		}
		printf("\n");			
	}
	for (i-=2; i>0; i--){
		for (j=0;j<i;j++){
			printf("*");
		}
		printf("\n");			
	}	
}
void func3(){
	int N=0,i=1,j=0;
	N=getNum();
	for (i=1; i<=N; i++){
		for (j=0;j<N-i;j++){
			printf(" ");
		}
		for (j=1;j<i*2;j++){
		printf("*");
		}
		printf("\n");			
	}
}
