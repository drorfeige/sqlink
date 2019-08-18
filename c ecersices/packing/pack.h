#ifndef PACK_H 
#define	PACK_H

struct compressed{
		unsigned int m_l : 4;
		unsigned int m_r : 4; 
};

union un{
	struct compressed lr;
	unsigned char c; 
}; 

int bitPack(unsigned char* str);
void printPack(unsigned char* str, int num);
int unionPack(unsigned char* str);

#endif
