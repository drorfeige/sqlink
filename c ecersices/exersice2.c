#include <stdio.h>

int getNum();

int Palindrome();
int ascending();
int Perfect();
int reverse();
int prime();


int main(){
	int rev;
	if(Palindrome()){
		printf("The number is palindrome\n");
	}
	else{
		printf("The number is not palindrome\n");
	}
	if(ascending()){
		printf("The number is ascending\n");
	}
	else{
		printf("The number is not ascending\n");
	}
	if(Perfect()){
		printf("The number is perfect\n");
	}
	else{
		printf("The number is not perfect\n");
	}
	rev=reverse();
	printf("%d\n",rev);
	if(prime()){
		printf("The number is prime\n");
	}
	else{
		printf("The number is not prime\n");
	}
	return 0;
}

int getNum(){
	int N=-1; 
	while(1){
		printf("choose an integer:\n");
		scanf("%d",&N);
		if (N>0){
		printf("you chose %d\n",N);
		break;
		}		
	}
	return N;
}
int Palindrome(){
	int N,a,b=0,retval;
	N=getNum();
	a=N;
	while(a!=0){
		b=b*10+a%10;
		a=a/10;			
	}
	if (N==b){
		retval=1;
	}else{
		retval=0;
	}
	return retval;	
}
int ascending(){
	int N,a,b,retval=1;
	N=getNum();
	if (N>9){
		a=N%10;
		N=N/10;
		b=N%10;
		N=N/10;
		if (b>a){
				retval=0;
			}
		while (N!=0){
			a=b;
			b=N%10;
			N=N/10;
			if (b>a){
				retval=0;
			}
		}
	}
	return retval;

}
int Perfect(){
	int N,a=1,b=2,retval=0;
	N=getNum();
	while(b*b<=N && a<=N){
		if (N%b==0){
			a=a+b;
			a=a+N/b;
		}
	b++;
	}
	if (a==N){
		retval=1;
	}
	return retval;
}
int reverse (){
		int N,retval=0;
	N=getNum();
	while(N!=0){
		retval=retval*10+N%10;
		N=N/10;			
	}
	return retval;	
}
int prime(){
	int N,b=2,retval=1;
	N=getNum();
	while(b*b<=N){
		if (N%b==0){
		retval=0;
		}
		b++;
	}
	return retval;	
}

