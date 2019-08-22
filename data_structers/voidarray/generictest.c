#include "darray_generic.h"
#include <stdio.h>
#include <stdlib.h>

int menu();
struct points{
	int x;
	int y;
};
int addPoint(struct points** pt);
int ptComp(void *PT1,void *PT2);
void ptDestroy(void *PT,  void *FP);

int main(int argc,char* argv[]){
	int option=0; 
	int ans=0;
	int status=0;
	darray* dA;
	FILE* fp;
	struct points* pt;
 	elementDestroy des;
	elementCompare comp;
	des=ptDestroy;
	comp=ptComp;
	fp=fopen("generic.txt","w");
	if(fp==NULL){
		return 0;
	}
	do{
	printf("choose initial size of array:\n");
	scanf("%d",&ans);
	}while(ans<4);	
	status=darrayCreate(&dA, ans);
	if(status==AllocationError){
		printf("allocation failed\n"); 
		return 0;
	}		
	do{
		option=menu();
		switch (option){
			case 1:
				status=addPoint(&pt);
				if(!ans){
					printf("allocation failed\n"); 
				}
				status=darrayAdd(dA, (void*)pt);
				if(status==AllocationError){
					printf("allocation failed\n");
					ptDestroy(pt,fp);
					free(pt); 
					return 0;
				}
				break;		
			case 2:
				status=darrayDelete(dA,(void**) &pt);
				if(ans==OK){
					ptDestroy(pt,fp);
				}
				break;
			case 3:
				printf("choose index to get\n");
				scanf("%d",&ans);
				status=darrayGet(dA, ans, (void**)&pt);
				if(status==OK){
					printf("the value of x is %d ",pt->x);
					printf("the value of y is %d\n",pt->y);
				}
				break;
			case 4:
				status=addPoint(&pt);
				if(!status){
					printf("allocation failed\n"); 
				}
				printf("choose index to set\n");
				scanf("%d",&ans);
				status=darraySet(dA, ans, (void*) pt);
				break;
			case 5:
				status=darraySort(dA, comp); 
				break;
			case 6:
				status=darrayItemsNum(dA, &ans);
				printf("the number of items is %d.",ans);
				break;
			default:
				break;
		}
	}while(option);
	ans=darrayDestroy(dA, des, fp);
	fclose(fp);
	return 0;
}

int menu(){
	int option=0;
	do{
	printf("choose option:\n");
	printf("for exit choose 0\n");
	printf("to add item choose 1\n");
	printf("to delete item choose 2\n");
	printf("to get item choose 3\n");
	printf("to set item choose 4\n");
	printf("to sort array choose 5\n");
	printf("to count items choose 6\n");
	scanf("%d",&option);
	}while(option<0);
	return option;
}


int addPoint(struct points** pt){
	struct points* Pt;
	int recieve;
	Pt=(struct points*)malloc(sizeof(struct points));
	if(Pt==NULL){
		return 0;
	}
	printf("choose x coordinate:\n");
	scanf("%d",&recieve);	
	Pt->x=recieve;
	printf("choose y coordinate:\n");
	scanf("%d",&recieve);	
	Pt->y=recieve;
	*pt=Pt;
	return 1;
}

int ptComp(void *PT1,void *PT2){
	struct points *pt1;
	struct points *pt2;
	pt1 = (struct points*)PT2;
	pt2 = (struct points*)PT2;
	if(pt1==NULL || pt2==NULL){
		return 0;
	}
	return (pt1->x)*(pt1->x)+(pt1->y)*(pt1->y)-(pt2->x)*(pt2->x)+(pt2->y)*(pt2->y);
}

void ptDestroy(void *PT,  void *FP){
	struct points *pt;
	FILE *fp;

	pt = (struct points*)PT;
	fp = (FILE*)FP;
	if(pt==NULL || fp==NULL){
		return;
	}
	if(pt){
		fprintf(fp,"delted point: x=%d y=%d\n",pt->x,pt->y);
	}
	free(pt);
}




