////Author: Martavious Dorsey
////Project: OLA3
////Due date: October 14, 2016
////Description:The implementation of the store Item class


#include <iostream>
#include "StoreItem.h"
using namespace std;


StoreItem::StoreItem(std::string barcode,double price,int copy,int demand)
{
	m_barcode = barcode;
	m_price=price;
	m_copy=copy;
	m_demand=demand;
}

//Returns the information for the barcode
string StoreItem::getBarcode(void) const {
	return m_barcode;

}
//Returns the information for the price
double StoreItem::getPrice(void) const {
	return m_price;

}
//Returns the information for the copies
int StoreItem::getCopy(void) const {
	return m_copy;
}
//returns the number of copies to be ordered
int StoreItem::getDemand(void) const {
	return m_demand;
}

//Increase # of copies by 1
//precondition: m_copy >= 0
void StoreItem::increaseCopy(void) {
	++m_copy;
}

//Decrease # of copies by 1
//precondition: m_copy > 0
void StoreItem::decreaseCopy(void) {
	--m_copy;
}

//Increase # of copies to be ordered by 1
//precondition: m_copy == 0
void StoreItem::increaseDemand(void) {
	++m_demand;
}

//Decrease # of copies to be ordered by 1
//precondition: m_demand > 0
void StoreItem::decreaseDemand(void) {
	--m_demand;
}

//Compare two store items. Return true if they have the same barcode,
//otherwise false.
bool StoreItem::operator==(const StoreItem& rhs) const {
	return(m_barcode == rhs.getBarcode());
}

//Compare two store items by barcode
bool StoreItem::operator<(const StoreItem& rhs) const {
	return (m_barcode < rhs.getBarcode());
}






