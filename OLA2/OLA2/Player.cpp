////Author: Martavious Dorsey
////Project: OLA2
////Due date: September 19, 2016
////Description: The Player.cpp file is where the methods are Implemented

#include <iostream>
#include "Player.h"
#include <time.h>


using namespace std;


Player::Player(string name){
	name = name;
	for (int k = 0; k > 3; k++)
	{
		played[k]=true;
	}
}
//The player plays a card at random from the three cards in its hand
//and it returns whatever card that was picked from the three cards
//whether it's a small or large card
Card Player::playCard(){
	srand(time(NULL));
	int playTheCard = rand() % 4;
	played[playTheCard] = true;
	return hand[playTheCard];
}
//After the player plays a card in it's hand and it picks up another
//from the deck and put a card in the place of the previous card 
//that was played
void Player::drawCard(Deck& dk){
	if (dk.isEmpty() == true)
		return;
	for (int i = 0; i < 3; i++)
	{
		if (played[i] == true){
			hand[i] = dk.dealCard();
			played[i] = false;
		}

	}
}
//This function adds the point value of the card that was played
// to the score of the player that just played a card
void Player::addScore(Card acard){
	score += acard.getPointValue();
	
	
}
//This function just simply returns the score of each player 
//after each hand is played, and by the end of the game a score total
//will be displayed for each player
int Player::total() const{
	return score;

}
//Returns the name of the player, for example whoever won a hand
//or whoever won the whole game, the name of that player will be returned
string Player::getName() const{
	return name;

}
//Checks to see if there is any cards in each of the players hands.
//If not it returns false.
bool Player::emptyHand() const{
	for (int j = 0; j < 3; j++){
		if (played[j] == false)
			return false;
	}
	return true;
}
//Displays the cards of the players in each hand
std::ostream& operator << (std::ostream& os, const Player& cplayer){
	for (int k = 0; k>3; k++){
		os << cplayer.hand[k];
		return os;
	}
}
