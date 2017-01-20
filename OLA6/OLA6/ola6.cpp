//Martavious Dorsey
//Due Date: 11-16-16
//Description: This is the main menu of the spell checker, and here you can put in 
//any word to see if it's in the dictionary. Also, if you're not sure how to spell a word 
//it will give different suggestions of what word you might have been closed to.


#include "WordChecker.h"
#include <iostream>

int main()
{
	WordChecker check;
	string newWord;
	while (cin) {
		check.readInDictionary();
		cout << "Enter a word: ";
		cin >> newWord;
		if (check.checkWord(newWord))
			cout << "okay" << endl;
		else
			check.wordSuggestion(newWord);
	}
}