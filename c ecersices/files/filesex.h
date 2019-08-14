#ifndef FILESEX_H
#define	FILESEX_H

typedef struct{
	int num;
	char m_word[32];
}Word;

typedef struct{
	int m_capacity;
	int index;
	char** wordArr;
}wordsInFile;

wordsInFile* extractWords(char* filename);
void printWords(wordsInFile* wordPtr);
int insertWord(wordsInFile* wordPtr,char* newWord);

void printNLines(char* filename,unsigned int N);
void countChars(char* filename);

#endif
