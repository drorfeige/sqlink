#ifndef TCONTAINER_T
#define TCONTAINER_T

#include <algorithm>
#include <list>
#include <vector>
#include <typeinfo>

using namespace std;

template <class T,class Container >
class tContainer_t{
	public:
		virtual ~tContainer_t(){ deleteAll();}
		tContainer_t(){}	
		inline bool isEmpty() const{return pCont.empty();}
		inline size_t numOfElements() const{return pCont.size();}
		inline void insertEl(const T* newE){pCont.push_back((T*)newE);}
		const inline T* getFirst() const{return pCont.empty()?0:pCont.front();}	
		const inline T* getLast() const{return pCont.empty()?0:pCont.back();}
		const T* getByVal(const T& toFind) const{
			c_iter_t it=find_if(pCont.begin(),pCont.end(),isEqual(toFind));
			if(it==pCont.end()) return 0;
			return *it;
		}
		T* removeByVal(const T& toFind){
			iter_t it=find_if(pCont.begin(),pCont.end(),isEqual(toFind));
			if(it==pCont.end()) return 0;
			T* temp=*it;
			pCont.erase(it);
			return temp;
		}
		bool deleteByVal(const T& toFind){
			iter_t it=find_if(pCont.begin(),pCont.end(),isEqual(toFind));
			if(it==pCont.end()) return 0;
			delete *it;
			pCont.erase(it);
			return 1;
		}
		inline void removeAll(){pCont.clear();}
		void deleteAll(){
			r_iter_t it;
			while(!pCont.empty()){
				it=pCont.rbegin();
				delete *it;
				pCont.pop_back();
			}
		}
		// because the program didn't compile and after a little search on google i used ovrloadi instead of typeid
		const T* operator[](size_t index) const{
			if(index>=pCont.size()) throw 2;
				if(typeid(pCont)==typeid(vector<T*>) || typeid(pCont)==typeid(list<T*>)){
					return subscript2(index,pCont);
				}	
				throw 3;
		}
		T*& operator[](size_t index){
				if(index>=pCont.size()) throw 2;
				if(typeid(pCont)==typeid(vector<T*>) || typeid(pCont)==typeid(list<T*>)){
					return subscript(index,pCont);
				}	
				throw 3;
		}
	private:
		typedef typename Container::reverse_iterator r_iter_t; 
		typedef typename Container::iterator iter_t; 
		typedef typename Container::const_iterator c_iter_t; 
		tContainer_t(const tContainer_t& ct){}
		tContainer_t& operator=(const tContainer_t& ct){}
		Container pCont;
		class isEqual{
			public:
				~isEqual(){;}
				isEqual(const T& val): m_val(val){}
				bool operator()(const T* t_val) const{return *t_val==m_val;}
			private:
				T m_val;
		};
		T*& subscript(size_t index,vector<T*> type){return type[index];}
		T*& subscript(size_t index,list<T*> type){
			iter_t it=type.begin();
			for(size_t i=0;i<index; i++){
				it++;
			}
			return *it;
		}
		const T* subscript2(size_t index,vector<T*> type) const{return type[index];}
		const T* subscript2(size_t index,list<T*> type) const{
			c_iter_t it=type.begin();
			for(size_t i=0;i<index; i++){
				it++;
			}
			return *it;
		}
};



#endif




























