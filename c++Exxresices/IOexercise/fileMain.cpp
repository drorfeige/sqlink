#include "asciiIO.h"
#include "binIO.h"
#include <string>
#include <iostream>

using namespace std;

template <class T>
void writeTest(virtlIO_t* f1){
	T i;	
	char c=' ';
	cin >> i;
	(*f1)<< i << c;
}

template <class T>
void readTest(virtlIO_t* f1){
	T i;	
	(*f1) >> i;
	cout << i << " ";
}

void vpTestWrite(virtlIO_t* f1){
	binIO_t* fp=dynamic_cast<binIO_t*>(f1);
	if(fp!=0){
		char arr[10]={'a','b','c','d','e','f','g','h','i','j'};		
		(*fp)<<arr,sizeof(arr);
	}
	else{
		cout << "wrong operation" << endl;
	}
}

void vpTestRead(virtlIO_t* f1){
	binIO_t* fp=dynamic_cast<binIO_t*>(f1);
	if(fp!=0){	
		char arr[10];
		(*fp)>>arr,sizeof(arr);
		for (unsigned int i=0; i<sizeof(arr);i++){
			cout << arr[i];
		}
	}
	else{
		cout << "wrong operation";
	}
	cout << endl;
}

int chooseVar(){ 
	cout << "0.exit" << endl;
	cout << "1.int" << endl; 
	cout << "2.long" << endl; 
	cout << "3.float" << endl; 
	cout << "4.char" << endl; 
	cout << "5.double" << endl; 
	cout << "6.pointer" << endl;
	int i; 
	cin >> i;
	return i;
}

void readToFile(virtlIO_t* f1){	
	int i;	
	do{
		i=chooseVar();
		switch (i){
			case 1: readTest<int>(f1); break;
			case 2: readTest<long>(f1); break;
			case 3: readTest<float>(f1); break;
			case 4: readTest<char>(f1); break;
			case 5: readTest<double>(f1); break;
			case 6: vpTestRead(f1); break;
			default: break;
		}
	}while(i);
}

void writeToFile(virtlIO_t* f1){	
	int i;	
	do{
		i=chooseVar();
		switch (i){
			case 1: writeTest<int>(f1); break;
			case 2: writeTest<long>(f1); break;
			case 3: writeTest<float>(f1); break;
			case 4: writeTest<char>(f1); break;
			case 5: writeTest<double>(f1); break;
			case 6: vpTestWrite(f1); break;
			default: break;
		}
	}while(i);
}


void fileTest(virtlIO_t* f1){
	string fname;
	string faccess;
	cout << "enter filename" << endl;
	cin >> fname;
	cout << "enter access" << endl;
	cin >> faccess;
	f1->open(fname.c_str(),faccess.c_str());
	if (f1->getStatus()!=virtlIO_t::ok_e){
		cout << "wrong name or access" << endl;
		f1->close();
		return;
	}
	char c;
	while(1){
		cout << "read(r) || write(w) || get pos(g) || set pos(s) || get length(l) || back(b)? " << endl;
		cin >> c;
		bool f=0;
		try{
			switch (c){
				case 'r': readToFile(f1); break;
				case 'w': writeToFile(f1); break;
				case 'g': cout << f1->getPos() << endl; break;
				case 's': size_t s; cin >> s; f1->setPos(s); break;
				case 'l': cout << f1->getLength() << endl; break;
				default: f=1; break;
			}
		}catch(int ex){
				cout << "bad access" << endl;
			}
		if(f) break;
	}
	f1->close();	
}
int main(){
	while(1){
		cout << "ascii or binary?(a/b/e)" << endl;
		char choice;
		cin >> choice;
		if(choice=='a'){
			asciiIO_t a1;
			fileTest(&a1);
		}
		else if(choice=='b'){
			binIO_t b1;
			fileTest(&b1);
		}
		else{
			break;
		}
	}
	return 0;
}












