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
		const T* operator[](size_t index) const{
				if(index>=pCont.size()) throw 2;
				if(typeid(pCont)==typeid(vector<T*>)){
					return pCont[index];
				}	
				else if(typeid(pCont)==typeid(list<T*>)){
					c_iter_t it=pCont.begin();
					for(size_t i=0;i<index; i++){
						it++;
					}
					return *it;
				}
				return 0;
		}
		T*& operator[](size_t index){
				if(index>=pCont.size()) throw 2;
				if(typeid(pCont)==typeid(vector<T*>)){
					//return pCont[index];
					return *pCont.begin(); // i get an error for the line above. i don't uderstand how rtti works
				}	
				else if(typeid(pCont)==typeid(list<T*>)){
					iter_t it=pCont.begin();
					for(size_t i=0;i<index; i++){
						it++;
					}
					return *it;
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
};



#endif




























