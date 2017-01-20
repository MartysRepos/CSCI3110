////Author: Martavious Dorsey
////Project: OLA1
////Due date: September 7, 2016
////Description: This is the main file of the program and it is where the menu is set up for the user to use////The user will be able to go throught the menu and find a specific and ID and get the scores for the particular ID number////THe next option would be for the user to choose the option too print out all the information within the file////The third and final option would be to just quit and the program will close

#include <iostream>

using namespace std;
#include "Student.h"
#include "Roster.h"

int main() {
	string header = "Id" "\t" "\t" "OLA" "\t"  "CLA" " " " " "QUIZ" "\t" "HOMEWORK" " " "Exam" "\t" "Bonus" "\t" "Total"
		"\t" "FinalGrade";
	char val = ' ';//Initialized for the switch statement, which contains the menu
	string className = "Class Name";

	//this variable is to find the string in of the class ID
	string cID;

	Roster roster(className);//The object of the roster class
	roster.readStudentRecord("point.dat");//This function sends the information 
	
	do{
		cout << "Welcome to the student information screen, Please select which option you are trying to access?" << endl;
		cout << "1.If you are looking for a particular student, enter the Cnumber of the student please?" << endl;
		cout << "2.If you just want to print all the student information just press 2." << endl;
		cout << "3.If you are done looking up student information, press 3 to quit." << endl;

		cin >> val;
	
		switch (val){
			case '1':
				cout << "Please enter the class number you are looking for?" << endl;
				cin >> cID;
				cout << header << endl;
				roster.findID(cID);
				break;

			case '2':
				cout << header << endl;
				roster.printAllStudentInfo();
				break;
			case '3':
				break;
			default :
				cout << "An invalid entry was made please try again " << endl;
				break;

		}
	} while (val != '3');




}










