/*
* File:	Roster.h
* Author:	Zhijiang Dong
* Course:	CSCI 3110
* Instructor:	Zhijiang Dong
* Date:	Oct. 06 2006
*
* Purpose: This file is a part of the 1st open lab assignment, which
* includes Student.h, Student.cpp, Roster.h, Roster.cpp,
* and main.cpp. This file gives the full definition
* of the class Roster.
*/

#ifndef __CSCI3110_ROSTER__
#define __CSCI3110_ROSTER__

#include <string>
#include <stdexcept>
#include "Student.h"

class Roster
{
public:

	// constructor, the parameter is the course name
	// Create an empty roster, i.e. m_studentNum = 0 for
	// a specific course
	Roster(std::string courseName);

	// This function reads student infeormation from a file
	// The parameter is a file name
	// post-condition: 
	//		m_students contains student information read from the file
	//		m_studentNum is the number of students read from the file	
	void readStudentRecord(std::string);
	//Prints all student info in the file
	void printAllStudentInfo();
	//Finds specific ID entered from the user 
	//if not found, therer will be an error message
	void findID(std::string cNumber);

	//*****************************************
	//Add your functions here if necessary
	//*****************************************

private:
	static const int	MAX_NUM = 25;	// The maximum # of students of a class
	// Class constant. All objects share the same copy
	std::string			m_courseName;	// THe name of the course
	int					  m_studentNum;	// Actual Student #
	Student				m_students[MAX_NUM]; // The array of student objects
};
#endif