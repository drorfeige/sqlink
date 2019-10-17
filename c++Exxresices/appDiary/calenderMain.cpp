#include "calender.h"
#include <iostream>

int menu(){
	cout << "0.exit\n" <<
		"1.insert new meeting\n" <<
		"2.remove meeting\n" <<
		"3.find meeting\n" <<
		"4.clean diary\n" <<
		"5.test copy constructr\n" <<
		"6.test assignment operator\n";
	int s1;
	cin >> s1;
	return s1;
}

meeting_t* newMeeting(float* forTesting){
	float start;
	float finish;
	cout << "choose start time\n";
	cin >> start;
	*forTesting=start;
	cout << "choose finish time\n";
	cin >> finish;
	try{
		meeting_t* nm=new meeting_t(start,finish);
		string s1;
		cout << "add description\n";
		cin >> s1;
		nm->setSubject(s1);
		return nm;
	}catch(int c){
		cout << "wrong input  " << c << "\n";
		return 0;
	}
}

int main(){
	calender_t c1;
	int sel;
	float lastStart=0;
	float* lSp=&lastStart;
	do{
		sel=menu();
		switch (sel){
			case 1:
				{
					meeting_t* m1=newMeeting(lSp);
					if(m1==0) break;
					if(c1.insertApp(m1)){
						cout<< "insertion succesfull\n";
					}else{
						cout << "insertion failed";
					}
					break;
				}
			case 2:
				{
					float start;
					cout << "time of meeting:\n";
					cin >> start;
					meeting_t* m2=c1.removeApp(start);
					if(m2==0){
						cout << "appoinment not found\n";
					}
					else{
						cout << "appointment removed succesfully\n";
						delete m2;
					}
					break;
				}
			case 3:
				{
					float start;
					cout << "time of meeting:\n";
					cin >> start;
					const meeting_t* m3=c1.findApp(start);
					if(m3==0){
						cout << "appoinment not found\n";
					}
					else{
						cout << m3->getSubject() << "\n";
					}
					break;
				}
			case 4:
				c1.cleanAD();
				break;
			case 5:{
					calender_t c5(c1);
					const meeting_t* m5=c5.findApp(*lSp);
					if(m5==0){
						cout << "appoinment not found" << *lSp <<"\n";
					}
					else{
						cout << m5->getSubject() << "\n";
					}
					break;
				}
			case 6:{
					calender_t c6;
					c6=c1;
					const meeting_t* m6=c6.findApp(*lSp);
					if(m6==0){
						cout << "appoinment not found\n";
					}
					else{
						cout << m6->getSubject() << "\n";
					}
					break;
				}
			default:
				break;
		}
	}while(sel>0);
	return 0;
}
