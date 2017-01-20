////Author: Martavious Dorsey
////Project: OLA2
////Due date: September 19, 2016
////Description: The Deck.cpp file is where the methods are Implemented

#include <iostream>
#include "Deck.h"
//This constructor builds the deck of cards which amounts to 52 cards
Deck::Deck(){
	topCard = 51;
	int j = 0;
	if(j<12)
	{
		//Goes through the clubs(2-14) and assigns them to the deck
		for (int n = 2; n < 14; n++)
		{
			theDeck[j] = Card(n, clubs);
			j++;
		}
		//Assigns the last card of the suite 
		//which would be the Ace of clubs
		theDeck[j] = Card(15, clubs);
	}
	j = j + 1;
	//Goes through the hearts(2-14) and assigns them to the deck
	for (int k = 2; k < 14; k++){
		theDeck[j] = Card(k, hearts);
		j++;
	}
	//Assigns the last card which would be the Ace of hearts
	theDeck[j] = Card(15, hearts);

	j = j + 1;
	//Goes through the spades(2-14) and assigns them to the deck
	for (int a = 2; a < 14; a++){
		theDeck[j] = Card(a, spades);
		j++;
	}
	//Assigns the last card of that suite to the deck which would be the 
	//the ace of spades
	theDeck[j] = Card(15, spades);

	j = j + 1;//goes to the next position in the array
	//Goes through the diamonds(2-14) and assigns them to the deck
	for (int b = 2; b < 14; b++){
		theDeck[j] = Card(b, diamonds);
		j++;
	}
	//Assigns the last card of the suite which would be the Ace of diamonds
	theDeck[j] = Card(15, diamonds);
}
//After a card is played, 
//then another card is picked from the top of the deck
Card Deck::dealCard(){
	Card temporary = theDeck[topCard];
		topCard--;
		return temporary;
}
//Shuffles the cards in the deck after a game is done
void Deck::Shuffle(){
	int index;
	for (int i = 0; i<52; i++)
	{
		index = rand() % 52;
		Card holder = theDeck[index];
		theDeck[index] = theDeck[i];
		theDeck[i] = holder;
	}
}
//checks to if there anymore cards in the deck, if not the game is over
bool Deck::isEmpty(){
	return topCard < 0;
}
//Displays all the cards in the deck before the game starts
ostream& operator << (ostream& os, const Deck& cDeck){
	for (int j = 0; j < 51 ; j++){
		os << cDeck.theDeck[j];
		return os;
	}

}

