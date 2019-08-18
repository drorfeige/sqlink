#include "bit.h"
#include <stdio.h>

int main(){
	int ans=0;
	unsigned char c=invertBits(97);
	ans=rotateLeft(97,5);
	ans=rotateRight(97,3);
	ans=setbits4(116 , 13, 20, 1);
	ans=setbits3(31, 5, 3, 4);
	return 0;
}
















