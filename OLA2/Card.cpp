////Author: Martavious Dorsey
////Project: OLA2
////Due date: September 19, 2016
////Description: The Card.cpp file is where the methods are Implemented

#include <iostream>
#include "Card.h"

using namespace std;

Card::Card(){
	faceValue = 0;
	pointValue = 0;

}
//This constructor assigns the point value to the face value
Card::Card(int faceVal, suite sType){
	faceValue = faceVal;
	type = sType;
	switch (faceVal){
	case 2:
		pointValue = 2;
		break;
	case 3:
		pointValue = 3;
		break;
	case 4:
		pointValue = 4;
		break;
	case 5:
		pointValue = 5;
		break;
	case 6:
		pointValue = 6;
		break;
	case 7:
		pointValue = 7;
		break;
	case 8:
		pointValue = 8;
		break;
	case 9:
		pointValue = 9;
		break;
	case 10:
		pointValue = 10;
		break;
	case 15: 
		pointValue = 15;
		break;
	default:
		faceValue = pointValue;
		break;

	}
}
//Compares the point value of the two cards
//if it has a smaller pointer value it return true
//returns false
bool Card::operator < (const Card& cd) const{
	return faceValue < cd.faceValue;

}
//compares the point value, and if it has a larger point value
//it returns true, otherwise it returns false
bool Card::operator > (const Card& cd) const{
	return faceValue > cd.faceValue;

}

std::ostream& operator << (std::ostream& os, const Card& cd){


	switch (cd.type){
	case clubs:
		os << ((char)0x03);
		break;
	case hearts:
		os << ((char)0x04);
		break;
	case spades:
		os << ((char)0x05);
		break;
	case diamonds:
		os << ((char)0x06);

	}
	switch (cd.faceValue)
	{
	case 1:  os << "A";  break;
	case 11: os << "J"; break;
	case 12: os << "Q"; break;
	case 13: os << "K";  break;
	default: os << cd.faceValue; break;
	}
	/*switch (cd.type)
	{
	case diamonds: os << " of Diamonds"; break;
	case spades: os << " of Spades"; break;
	case hearts: os << " of Hearts"; break;
	case clubs: os << " of Clubs"; break;
	}*/
	return os;

}
//Compare the point value of cards, returns true if the cards 
//are equal, otherwise return false
bool Card::operator== (const Card& cd) const{
	return faceValue == cd.faceValue;
}
//returns the pointvalue of the card that was played
int Card::getPointValue() const{
	return pointValue;


}