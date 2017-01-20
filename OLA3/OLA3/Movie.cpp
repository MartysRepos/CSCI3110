////Author: Martavious Dorsey
////Project: OLA3
////Due date: October 14, 2016
////Description:The implementation of the book class

#include <iostream>
#include "Movie.h"
#include "Book.h"
#include "StoreItem.h"
#include <string>
#include <sstream>

using namespace std;

//default constructor
Movie::Movie(std::string title, std::string director, std::string barcode, double price, int copy, int demand) {

}
//returns the title of the movie in movie class
string Movie::getTitle() const {
	return m_title;

}
//Reeturn the director name from the movie class
string Movie::getDirector() const {
	return m_director;

}

//Prints each book information, with the barcode at the top, director, 
//price of the movie, copies, and demand
void Movie::printItem(){
	cout << "************** Movie with Barcode " << m_barcode << "**************" << endl;
	cout << "Director:	" << m_director << endl;
	cout << "Price:		" << m_price << endl;
	cout << "# of copy:	" << m_copy << endl;
	cout << "# of demand:    " << m_demand << endl;
}

//This function returns a dynamically created StoreItem object
//which is created from a string.
//The string info must be of the line format specificed in
//inventory.txt
 Movie* Movie::createFromString(const std::string info ){
	string price1;
	string copy1;
	string demand1;
	char trash;
	string barcode;
	string title, director;
	string aVariable;
	double price;
	int copy, demand;

	stringstream	size1(info);
	size1 >> trash;
	//reads the Movie class information line by line 
	getline(size1, aVariable, DELIMITER);
	getline(size1, barcode, DELIMITER);
	getline(size1, title, DELIMITER);
	getline(size1, director, DELIMITER);
	getline(size1, price1, DELIMITER);
	getline(size1, copy1, DELIMITER);
	getline(size1, demand1, DELIMITER);
	price = stof(price1);
	copy = stoi(copy1);
	demand = stoi(demand1);

	Movie *theMovie = new Movie();
	theMovie->m_title = title;
	theMovie->m_director = director;
	theMovie->m_price = price;
	theMovie->m_demand = demand;
	theMovie->m_barcode = barcode;
	theMovie->m_copy = copy;
	return theMovie;

	
}