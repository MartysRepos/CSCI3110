////Author: Martavious Dorsey
////Project: OLA2
////Due date: September 19, 2016
////Description: The ola2.cpp Displays how the game is played
////The game should proceed as follows.  
////The 52 cards in a deck of cards are shuffled and 
////each player draws three cards from the top of the deck.  
////The remaining cards are placed in a pile face-down between the two players.  
////Players then select one of the three cards in hand and simultaneously place the chosen card face-up on the game table.  
////The player who placed the highest ranking card on the table retrieves both cards and sets the cards aside.  
////If both cards have the same rank, each player retrieves his/her card and sets the one card aside.  
////Then, each player selects the top card from the deck (and adds this card to his/her hand of cards.  
////Play continues until all cards have been played.  
////The winner is the player with the most points at the end of the game.


#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
using namespace std;

int main(){
	int num;

	Deck theDeck;
	cout << "This is the deck before its shuffled" << endl;
	cout << theDeck;
	theDeck.Shuffle();
	cout << theDeck;
	Player player1("Computer");
	Player player2("Martavious");
	Card card1;
	Card card2;
	for (int i = 0; i > 3; i++)
	{
		player1.drawCard(theDeck);
		player2.drawCard(theDeck);
	}
	while (!theDeck.isEmpty())
	{
		card1=player1.playCard();
		card2=player2.playCard();

		if (card1 == card2){
			player1.addScore(card1);
			player2.addScore(card2);
		}
		else if (card1 > card2)
		{
			player1.addScore(card1);
		}
		else{
			player2.addScore(card2);
		}
		player1.drawCard(theDeck);
		player2.drawCard(theDeck);
	
	}
	cout << "Player 1 score" << player1.total();
	cout << "Player 2 score" << player2.total();

	cin >> num;

	

	


}