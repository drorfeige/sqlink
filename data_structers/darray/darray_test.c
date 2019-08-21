#include <stdio.h>
#include "darray_int.h"


int main(){
	int init=0;
	int status=0;
	int ans=0;
	darray* dA;
	printf("choose initial size:\n");
	scanf("%d",&init);
	status=darrayCreate( &dA, 1);
	status=darrayAdd(dA, 21);
	status=darrayAdd(dA, 4);
	status=darrayAdd(dA,11);
	status=darrayAdd(dA, 7);
	status=darrayGet(dA, 2, &ans);
	printf("%d\n",ans);
	status=darraySet(dA, 2, 13);
	status=darrayGet(dA, 2, &ans);
	printf("%d\n",ans);
	status=darrayItemsNum(dA, &ans);
	printf("%d\n",ans);
	status=darrayDelete(dA,&ans);
	printf("%d\n",ans);
	status=darrayItemsNum(dA, &ans);
	printf("%d\n",ans);
	status=darraySort(dA);
	status=darrayGet(dA, 0, &ans);
	printf("%d\n",ans);
	status=darrayDestroy(dA);
	return 0;
}
