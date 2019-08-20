 #include <stdio.h> 		


unsigned int factorial(unsigned int N){
		if(N==1 || N==0){
			return N;
		}
		return N*factorial(N-1);
}


int main(){
	unsigned int ans=0;
	ans=factorial(10);
	printf("%u\n",ans);
	return 0;	

}