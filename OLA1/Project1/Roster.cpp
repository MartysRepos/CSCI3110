////Author: Martavious Dorsey
////Project: OLA1
////Due date: September 7, 2016
////Description: The Roster.cpp file is where the methods from Roster.h files are being implemented

#include <iostream>
#include <string>
#include <fstream>
#include "Roster.h"

using namespace std;

//Creates an empty roster before the file is being read in
Roster::Roster(std::string cName) {
	m_studentNum = 0;
	m_courseName = cName;

}
//This function reads the student information from the file
void Roster::readStudentRecord(std::string info) {
	ifstream myIn;
	string topLine;
	myIn.open(info);
	getline(myIn, topLine);
	int count = 0;
	string  Id;
	int num;
	
	myIn >> Id;
	while (myIn) {
		m_students[m_studentNum].setID(Id);
		myIn >> num;
		m_students[m_studentNum].changeScore(Student::ScoreType::CLA, num);
		myIn >> num;
		m_students[m_studentNum].changeScore(Student::ScoreType::OLA, num);
		myIn >> num;
		m_students[m_studentNum].changeScore(Student::ScoreType::QUIZ, num);
		myIn >> num;
		m_students[m_studentNum].changeScore(Student::ScoreType::HOMEWORK, num);
		myIn >> num;
		m_students[m_studentNum].changeScore(Student::ScoreType::EXAM, num);
		myIn >> num;
		m_students[m_studentNum].changeScore(Student::ScoreType::BONUS, num);
		m_studentNum++;
		myIn >> Id;
		
	}
}
//This function finds a particular ID from the file and 
//prints all the different scores associated with that student
void Roster::findID(std::string cNumber){
	for (int i = 0; i < m_studentNum; i++){
		//compares the ID enter the from the user to the ID thats inside the file
		if (cNumber == m_students[i].getID()){
			//If found the student ID along with the scores of that student is printed 
			m_students[i].printIndividualStudentInfo();
			return;
		}
	}
	cout << "not found";
	return;
}
//This function prints out all the student information that is contained in the file
void Roster::printAllStudentInfo(){
	//The for loop keeps up with all the student information
	//read from the file and stores it
	for (int j = 0; j < m_studentNum; j++){
		//once the for loop gets done storing them, 
		//then this line below prints all information stored in that array
		m_students[j].printIndividualStudentInfo();
	}
}




