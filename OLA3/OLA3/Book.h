#pragma once

////Author: Martavious Dorsey
////Project: OLA3
////Due date: October 14, 2016
////Description:The Book class, with member data and member functions
#include <iostream>
#include "StoreItem.h"




class Book : public StoreItem
{
public:
	//default Constructor
	Book(std::string title="", std::string author="", 
		std::string date="", std::string barcode="", double price = 0, int copy = 0, int demand = 0);

	std::string getTitle() const;
	std::string getAuthor() const;


	//This function returns a dynamically created StoreItem object
	//which is created from a string.
	//The string info must be of the line format specificed in
	//inventory.txt
	Book* createFromString(const std::string info) override;
	//Print current item to the screen
	void printItem() override;

	private:
		std::string m_title;
		std::string m_author;
		std::string m_date;

};
