////Author: Martavious Dorsey
////Project: OLA3
////Due date: October 14, 2016
////Description: The implementation of the Book class


#include "StoreItem.h"
#include "Book.h"
#include "Movie.h"
#include <string>
#include <sstream>

using namespace std;
//default constructor
Book::Book(std::string title, std::string author, std::string date, std::string barcode,
	double price, int copy, int demand)
{

}
//Gets the Title of book
string Book::getTitle() const  {
	return m_title;
}
//Gets the name of author
string Book::getAuthor() const  {
	return m_author;
}

//This function returns a dynamically created StoreItem object
//which is created from a string.
//The string info must be of the line format specificed in
//inventory.txt
Book* Book::createFromString(const std::string info)  {
	string price1;
	string copy1;
	string demand1;
	char trash;
	string title, author, date, barcode;
	string aVariable;
	double price;
	int copy, demand;

	stringstream	size1(info);
	
	size1 >> trash;
	//Reads information fromt the Inventory.txt file
	getline(size1, aVariable, DELIMITER);
	getline(size1, barcode, DELIMITER);
	getline(size1, title, DELIMITER);
	getline(size1, author, DELIMITER);
	getline(size1, date, DELIMITER);
	getline(size1, price1, DELIMITER);
	getline(size1, copy1, DELIMITER);
	getline(size1, demand1, DELIMITER);
	price = stof(price1);
	copy = stoi(copy1);
	demand = stoi(demand1);

	Book *theBook = new Book();
	theBook->m_barcode = barcode;
	theBook->m_title = title;
	theBook->m_author = author;
	theBook->m_date = date;
	theBook->m_demand = demand;
	theBook->m_copy = copy;
	theBook->m_price = price;

	return theBook;
}

//Print current item to the screen
//Prints each book information, with the title, author, publish date, price, copies, and demand
void Book::printItem(){
	cout << "************************* Book with barcode " << m_barcode << "*****************" << endl;
	cout << "Title:		   " << m_title << endl;
	cout << "Author:	   "<< m_author << endl;
	cout << "Publish Date: " << m_date << endl;
	cout << "Price:		   " << m_price << endl;
	cout << "# of copy:	   " << m_copy << endl;
	cout << "# of demand:       " << m_demand << endl;
}