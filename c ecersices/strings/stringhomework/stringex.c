#include <stdio.h>
#include <string.h>

int Bin2Int(char* bin);
void Int2Bin(int n,char* bin);
int Location(char* s1, char* s2);
void squeeze(char* s1,char* s2);
void reverseprint(char* str);
void reverseStr(char* str);
void swap(char* x, char* y);
int menu(); 

int main(){
	int func=0;
	char str1[64];
	char str2[32];
	int ans=0;
	unsigned int ans2=0;
	func=menu();
	while(func){
		switch (func){
			case 1:
				printf("enter an int to convert into bin:\n");
				scanf("%u",&ans2);
				Int2Bin(ans2,str1);
				printf("the binary representaion is:\n");
				/*reverseprint(str1); if we just need to print the binary representation without saving in memory*/
				printf("%s\n",str1);
				break;
			case 2: 
				printf("enter a binary number to convert to int:\n");
				scanf("%s",str1);
				ans2=Bin2Int(str1);
				printf("the int representation of the binary nember is %d\n",ans2);
				break;
			case 3:
				printf("enter string to squeeze:\n");
				scanf("%s",str1);
				printf("enter characters to eliminate from first string:\n");
				scanf("%s",str2);
				squeeze(str1,str2);
				printf("%s\n",str1);
				break;
			case 4: 
				printf("enter the string to search locaton in:\n");
				scanf("%s",str1);
				printf("enter the string to search location of:\n");
				scanf("%s",str2);
				ans=Location(str1,str2);
				printf("the out put of location function is %d\n",ans);
				break;
			default:
				break;
		}
		func=menu();
	
	}
	return 0;
}

int menu(){
	int choice=0;
	printf("press\n0 to exit\n1 for Int2Bin\n2 for Bin to Int\n3 for squeeze\n4 for Location\n");
	scanf("%d",&choice);
	return choice;	
}

int Bin2Int(char* bin){
	int out=0;
	int i=0;
	if(bin==NULL){
		return out;
	}
	while(bin[i]!='\0'){
		/*if(bin[i]=='1'){
			out=out*2+1;
		}
		else if(bin[i]=='0'){
			out=out*2;
		}*/
		if (bin[i]=='1' || bin[i]=='0'){
			out=out*2+ bin[i++]-'0';
		}
		else{
			return 0;
		}
		/*i++;*/
	}
	return out;
}

void Int2Bin(int n, char* bin){
		int res=0;
		int i=0;
		if(bin==NULL){
			return;
		}
		/*while(n!=0){
			bin[i++]=(n%2)?'1':'0';
			n=n/2;
		}*/
		do{
			bin[i++]=(n%2)?'1':'0';
			n=n/2;
		}while(n!=0);
		bin[i]='\0';
		reverseStr(bin); 
}

void squeeze(char* s1,char* s2){
	int is1=0,is2=0,iswap=0;
	if(s1==NULL || s2==NULL){
		return;
	}	
	for(is2=0;s2[is2]!='\0';is2++){
		iswap=0;
		for(is1=0;s1[is1]!='\0';is1++){
			if(s1[is1]!=s2[is2]){
				s1[iswap++]=s1[is1];
			}
			
		}
		s1[iswap]='\0';
	}
}

int Location(char* s1, char* s2){
	int s1len=0,s2len=0;
	int i=0,j=0;
	if(s1==NULL || s2 ==NULL ){
		return -1;
	}
	s1len=strlen(s1);
	s2len=strlen(s2);
	for(i=0; i<=s1len-s2len; i++){
		if (s1[i]==s2[0]){
			for(j=0;j<s2len;j++){
				if(s1[i+j]!=s2[j]){
					break;
				}
			}
			if (j==s2len){
				return i;
			}
		}
	}
	return -1;
} 

void reverseprint(char* str){
	int i=0;
	for (i=strlen(str);i>=0;i--){
	printf("%c",str[i]);
	}
	printf("\n");
}

void reverseStr(char* str){
	int i=0,size=0;
	if (str==NULL){
		return;
	}
	size=strlen(str);
	for(i=0;i<size/2;i++){
		swap(str+i,str+size-1-i);
	}
}

void swap(char* x, char* y){
	char temp;
	if(x==NULL || y==NULL){
		return;
	}
	temp =*x;
	*x=*y;
	*y=temp;

}






