#ifndef ANALYZER_H
#define ANALYZER_H

#include <set>
#include <string>
#include <queue>



class analyzer_t{
	public:
		virtual ~analyzer_t(){}
		analyzer_t();
		virtual void analyze(std::queue<std::string>& tokens);
		virtual void endAndresetAnalyzer();
		inline void addPredef(const std::set<std::string>& newpredef){ 
			predefinedV=newpredef;
		}
		inline const std::set<std::string>& getPredef() const{return predefinedV;}
		inline void addOPerator(const std::set<std::string>& newoperators){ 
			operators=newoperators; 
		}
		inline const std::set<std::string>& getOperator() const{return operators;}
		inline void addKeyWord(const std::set<std::string>& newkeyWords){ 
			keyWords=newkeyWords;
		}
		inline const std::set<std::string>& getKeyWord() const{return keyWords;}
		inline const std::string& setDelimiters(const std::string& newDel){ 
			delimiters=newDel; return delimiters;
		}
		inline const std::string& getDelimiters() const{return delimiters;}
	protected:
		bool main;//check
		unsigned int lineNum;//check
		bool predefinedF;//needs attention in analyze, cotinue after function and check at end for others
		unsigned int ifCount;//check
		std::set<std::string> variables;
		unsigned char plus; //needs attention in analyze
		unsigned char minus;//needs attention in analyze
		unsigned int curlyBraces;//check
		unsigned int squareBraces;//check
		unsigned int circleBraces;//check
		std::set<std::string> predefinedV;
		std::set<std::string> operators;
		std::set<std::string> keyWords;
		std::string delimiters;
		virtual void predefinedHandler();
		virtual void ifHandler(const std::string& kw);
		virtual void operatorsHandler(const std::string& o);
		virtual void variableHandler(const std::string& var);
		virtual void bracesHandler(const std::string& isBraces);
	private:
		analyzer_t(const analyzer_t& newA);
		analyzer_t& operator=(const analyzer_t& newA);

		
			
};

#endif
















