////Author: Martavious Dorsey
////Project: OLA3
////Due date: October 14, 2016
////Description: The main function is where the menu will be performed
////In the menu you will be able to find A Movie by searching for the Title of the movie,
////The next option will be to Search for a book by enterinfg the author name
////Option 2 will let you return a movie/book back into the inventory using a barcode
////THe next option will be to list the entire inventory
////The last option will be to checkout a movie/book from the inventory using a barcode


#include <iostream>
#include "StoreItem.h"
#include "Movie.h"
#include "Book.h"
#include <list>
#include <string>
#include <fstream>
#include <sstream>
#include <typeinfo>
using namespace std;


void searchTheTitle(list<StoreItem *> items);
void searchbyAuthor(list<StoreItem*> items);
void returnbyBarcode(list<StoreItem *> items);
void listByBarcode(list<StoreItem *> items);
void CheckOut(list<StoreItem *> items);


int main()
{
	list<StoreItem *> theInventory;//The list container
	Movie	amovie;
	Book	abook;
	string  name;
	string  line;
	Movie   mTemp;
	Book    bTemp;
	char cmd = ' ';
	ifstream myIn;
	string getTheLine;
	char trash;
	stringstream theString(getTheLine);
	myIn.open("inventory.txt");

	while (myIn)
	{
		myIn >> trash;

		getline(myIn, line, DELIMITER);
//		theString >> getTheLine;
		

		if (line == "Movie")
		{
			string mystr ="";
			getline(myIn, mystr);
			Movie*amovie = mTemp.createFromString(DELIMITER+line+DELIMITER+mystr);//stores the line into the object of movie class
			if (theInventory.empty())//Checks to see if the list is empty
				theInventory.push_front(amovie);//if the list is empty, movie information is pushed onto the list
			else
				theInventory.push_back(amovie);
			
		}
		else if (line == "Book") {
			string mystr = "";
			getline(myIn, mystr);
			Book *abook = bTemp.createFromString(DELIMITER+line+DELIMITER+mystr);//Stores the line into object of the book class
			if (theInventory.empty())//Checks to see if the list is empty
				theInventory.push_front(abook);//if list is empty, book information pushed onto the list
			else
				theInventory.push_back(abook);
			
		}
		
		line = "";
	}
	
	do {
		cout << "*********************************************" << endl;
		cout << "*Command   Description                       *" << endl;
		cout << "*M  "  "   Inquire a movie by title		     *" << endl;
		cout << "*B  " "   Inquire a book by author              *" << endl;
		cout << "*L  " "   List Inventory                        *" << endl;
		cout << "*R  " "   Return one movie                      *" << endl;
		cout << "*C  " "   Check out                             *" << endl;
		cout << "*Q  " "   Quit the main menu                    *" << endl;
		cout << "*********************************************" << endl;
		cout << "Please enter yout command (M, B, L, R, C, Q):" << endl;

		cin >> cmd;

		switch (cmd)
		{
		case 'M':
			searchTheTitle(theInventory);
			break;
		case 'B':
			searchbyAuthor(theInventory);
			break;
		case 'R':
			returnbyBarcode(theInventory);
			break;
		case 'L':
			listByBarcode(theInventory);
			break;
		case 'C':
		CheckOut(theInventory);
		    break;
		case 'Q':
			break;
		
		default:
			cout << "An invalid entry was made please try again " << endl;
			break;
		}
	} while (cmd != 'Q');
}

void searchTheTitle(list<StoreItem*> items)
{
	string name;
	string var1;
	cout << "Enter the Movie Title:";
	cin >> name;
	Movie	defaultMovie;	// a movie object

	for (std::list<StoreItem*> ::iterator it = items.begin(); it != items.end(); ++it) {
		if (typeid(*(*it)) == typeid(defaultMovie)) {
			//if((*it)->getTitle()==name)
			//Can you explain how it works
		}

		cout << "Name not found, Please try again" << endl;
	}
}

void searchbyAuthor(list<StoreItem*> items)
{
	Book defaultBook;
	string name;
	string var2;
	cout << "Please enter the Authors name";
	cin >> name;
	for (std::list<StoreItem*> ::iterator it = items.begin(); it != items.end(); ++it) {
		if (typeid(*(*it)) == typeid(defaultBook)){
			//if((*it)->getAuthor()==name)
			//can you explain how it works
			
	}
}

//Return a movie / book to the inventory.The user should be asked to input the bar code.
//If the movie / book is in the inventory, 
//the number of copies of the item should be increased by 1 if the number of copies to be ordered is 0, 
//or decrease the number of copies to be ordered by 1 if it is greater than 0.
void returnbyBarcode(list<StoreItem*> items)
{
		string name;
		Movie defaultMovie;
		Book defaultBook;
		cout << "Enter the Barcode:";
		cin >> name;
		bool found = false;

		for (std::list<StoreItem*> ::iterator it = items.begin(); it != items.end(); ++it) {
			if ((*it)->getBarcode() == name) {
				found = true;
				//(*it)->printItem();
				if (typeid(*(*it)) == typeid(defaultMovie)) {
					if ((*it)->getDemand() > 0)//Checks to see if the demand is greater than 0
						((*it))->decreaseDemand();//If so, the demand is decresed by 1
					else
						(*it)->increaseCopy();//If that conditions fails then the number of copies are increased
					cout << "one more movie is added to the inventory";
					break;
				}

				if (typeid(*(*it)) == typeid(defaultBook)) {
					if ((*it)->getDemand() > 0)//Checks to see if the demand is greater than 0
						((*it))->decreaseDemand();//If so, the demand is decresed by 1
					else
						(*it)->increaseCopy();//If that conditions fails then the number of copies are increased
					cout << "one more book is added to the inventory";
				break;
				}
			}
		}
		//if (found == false)
			//cout << "Invalid Barcode, Please enter another barcode:";
}
//This function Lists the entire inventory in alphabetical order by barcode
void listByBarcode(list<StoreItem*> items)
{
	
	items.sort([](const StoreItem *f, const StoreItem *s) { return f->getBarcode() < s->getBarcode(); });

	for (std::list<StoreItem*> ::iterator it = items.begin(); it != items.end(); ++it) {
		(*it)->printItem();
	}
}

//Check out a movie / book.The user should be asked to input a barcode.
//If the item is in the inventory and the number of copies of the item is >0, 
//your program should decrease the number of copies on hand by one.
//If the item is in the inventory but there are no copies available, 
//the number of copies to be ordered should be increased by 1. 
//If the item is not in the inventory, an error message should be printed.
void CheckOut(list<StoreItem*> items) {
	string name;
	Movie defaultMovie;
	Book defaultBook;
	cout << "Enter the Barcode:";
	cin >> name;
	bool found = false;

	for (std::list<StoreItem*> ::iterator it = items.begin(); it != items.end(); ++it) {
		if ((*it)->getBarcode() == name) {
			found = true;
			//(*it)->printItem();
			if (typeid(*(*it)) == typeid(defaultMovie)) {
				if ((*it)->getCopy() > 0) {//Checks to see if the number of copies os greater than 0
					((*it))->decreaseCopy();//If so decrease the number of copies by 1
					cout << "The movie has been checked out!";
				}
				else
					(*it)->increaseDemand();//if those conditions fail, the demand will be increased by 1
				break;
			}

			if (typeid(*(*it)) == typeid(defaultBook)) {
				if ((*it)->getCopy() > 0) {//Checks to see if the number of copies os greater than 0
					((*it))->decreaseCopy();//If so decrease the number of copies by 1
					cout << "The book has been checked out!";
				}
				else
					(*it)->increaseDemand();//if those conditions fail, the demand will be increased by 1
				break;
			}
		}
	}
	//Checks to see if the correct barcode was entered by the user
	if (found == false)
		cout << "Invalid Barcode, Please enter another barcode:";
}



