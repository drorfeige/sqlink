#ifndef BUILDING_H
#define BUILDING_H

template <class TB>
class Building_t{
	public:
		~Building_t(){}
		Building_t(){}
		Building_t(const Building_t& oldT);
		Building_t& operator=(const Building_t& oldT);
		inline void setBuidingID(const TB& newT);
		inline const TB& getBuildingID() const;
	private:
		TB m_BID;
};

template <class TB>
Building_t<TB>& Building_t<TB>::operator=(const Building_t<TB>& oldT){
	m_BID=oldT.getBuildingID();
	return *this;
}

template <class TB>
Building_t<TB>::Building_t(const Building_t<TB>& oldT){
	m_BID=oldT.getBuildingID();
}

template <class TB>
inline void Building_t<TB>::setBuidingID(const TB& newT){
	m_BID=newT;
}

template <class TB>
inline const TB& Building_t<TB>::getBuildingID() const{
	return m_BID;
}

#endif
















