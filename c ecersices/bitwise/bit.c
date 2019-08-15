#include "bit.h"
#include <stdlib.h>
#include <stdio.h>

int bitOn(bitMap* features,int index){
	int i=1;
	if(features==NULL){
		return 0;
	}
	if(index>=features->m_nf || features->m_features==NULL || index<0){
		return 0;
	}
	features->m_features[index/8]=features->m_features[index/8]|(i<<index%8);
	return 1;	
}  

int bitOff(bitMap* features,int index){
	int i=1;
	if(features==NULL){
		return 0;
	}
	if(index>=features->m_nf || features->m_features==NULL || index<0){
		return 0;
	}
	features->m_features[index/8]=features->m_features[index/8]&(~(i<<index%8));
}

int bitCheck(bitMap* features,int index){
	int i=1;
	if(features==NULL){
		return -1;
	}
	if(index>=features->m_nf || features->m_features==NULL || index<0){
		return -1;
	}
	return features->m_features[index/8]&(i<<index%8);
}


int destroy(bitMap* bt){
	if(bt){
		if(bt->m_features){
			free(bt->m_features);
		}
		free(bt);
	}
}

bitMap* createBM(int nf){
	bitMap* BM;
	BM=(bitMap*)malloc(sizeof(bitMap));
	if(BM==NULL){
		return NULL;
	}
	BM->m_features=(char*)calloc((nf/8)+1,sizeof(char));
	if(BM->m_features==NULL){
		return NULL;
	}
	BM->m_nf=nf;
	return BM;
}

void printBM(bitMap* features){
	int i=0,on;
	if(features==NULL){
		return;
	}
	if(features->m_features==NULL){
		return;
	}
	for(i=features->m_nf-1;i>=0;i--){
		on=bitCheck( features, i);	
		if(on==0){
			printf("0");
		}
		else if(on>0){
			printf("1");
		}
	}
	printf("\n");
}		
















