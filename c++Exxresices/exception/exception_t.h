#ifndef EXCEPTION_T_H
#define EXCEPTION_T_H

#include <string>

using namespace std;

template <class T>
class TException_t{
	public:
		~TException_t(){}
		TException_t(const string sourceName, const int lineNum, const string textDescript, T thrownObject):m_sourceName(sourceName),m_lineNum(lineNum),m_textDescript(textDescript),m_thrownObject(thrownObject){}
		inline const string getSource() const{return m_sourceName;}
		inline const unsigned int getLine() const{return m_lineNum;}
		inline const string getDescript() const{return m_textDescript;}
		inline const T& getObject() const{return m_thrownObject;}
	private:
		const string m_sourceName;
		const unsigned int m_lineNum;
		const string m_textDescript;
		T& m_thrownObject; 	
};

#endif































