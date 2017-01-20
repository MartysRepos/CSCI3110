////Author: Martavious Dorsey
////Project: OLA1
////Due date: September 7, 2016
////Description: The Student.cpp file is where the methods are Implemented
#include <iostream>

#include "Student.h"
#include <string>

using namespace std;
//The default constructor
Student::Student() {


}
//This funciton is used to access the IDs in the file
string Student::getID(void)const {
	return m_id;

}

//This function is used when the user enters an ID
void Student::setID(std::string Id) {
	m_id = Id;
	return;
}
//This function indicates what scoreType you want to access
void Student::changeScore(const ScoreType scores, const int scores1) {
	m_score[scores] = scores1;
	return;

}

int Student::getScore(const ScoreType theScores) const{
	return m_score[theScores];

}
//This function is designed to print an students individual scores
//So basically when the user types in a certain ID, then this print function will print the individual scores 
//just from that ID that was entered.
void Student::printIndividualStudentInfo(){
	cout << getID() << "\t \t" << getScore(CLA) << "\t" 
	<< getScore(OLA) << "\t" << getScore(QUIZ) << "\t"
	<< getScore(HOMEWORK) << "\t" << getScore(EXAM) << "\t" 
	<< getScore(BONUS) << endl;
	
}

