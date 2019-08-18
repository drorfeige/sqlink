#include <stdio.h>
#include "pack.h"


int main(){
	unsigned char word[32]="";
	int size=0;
	printf("enter a word in small letters from a to p\n");
	scanf("%s",word);
	size=bitPack( word);
	printPack(word, size);
	printf("enter a word in small letters from a to p\n");
	scanf("%s",word);
	size=unionPack(word);
	printPack(word, size);

	return 0;
}
