//Martavious Dorsey
//Due Date: 11-16-16
//Description: These are the impelemented methods from the class "WordChecker"

#include "WordChecker.h"
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

WordChecker::WordChecker()
{

}

//Reads in the dictionary and stores them in an unordered map
void WordChecker::readInDictionary()
{
	ifstream myIn;
	myIn.open("dict.txt");
	string word1;
	pair<string, bool> temp;
	while (myIn) {
		myIn >> word1;

		temp = {word1, false};
		dictionary.insert(temp);
	}
}
//Checks to see if the word is in the dictionary
bool WordChecker::checkWord(string word)
{
	//check the word the user entered against all the word in the dictionary
	for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
		if (it->first == word)
			return true;
	return false;
}
//After the user has entered a word close to what's in the dcitionary
//it gives the user suggestions of what word they might've been looking for
void WordChecker::wordSuggestion(string word)
{
	//Goes through the lenght of the wo
	for (int i = 0; i < word.length(); i++) {
		word[i] = tolower(word[i]);
	}
	string modword = "";
	for (int i = 0; i < word.length(); i++)
	{
		modword = deleteLetter(word, i);
		findWords(modword, word.length());	
	}
	//Gooes through the legnth of the word
	//Then inserts an letter
	for (int i = 0; i <= word.length(); i++)
	{
		modword = word;
		modword.insert(i, " ");
		insertLetter(modword, i);
	}
	swapLetters(word);
	for (int i = 0; i < word.length(); i++) {
		replaceLetter(word, i);
	}

	insertSpace(word);

	list<string> dictwords;
	for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
	{	
		if (it->second == true) {
			dictwords.push_back(it->first);
		}
	}
	//Sorts the word in Alphabetical order
	dictwords.sort();
	for (auto it = dictwords.begin(); it != dictwords.end(); ++it) {
		cout << *it << endl;
	}
	//Clears for the next word
	dictionary.clear();
}
//
void WordChecker::findWords(string word, int wordsize)
{
	string dictword = "";
	int pos = 0;
	if (dictionary.find(word.c_str()) != dictionary.end())
		dictionary[word] = true;
}

//This function Constructs every string that can be made by deleting one letter from the word. 
//n possibilities, where n is the length of the word) 
string WordChecker::deleteLetter(string word, int pos)
{ 
	if (pos != word.length())
		for (int i = pos; i < word.length(); i++) 
		{
			word[i] = word[i + 1];
		};
	//cout << word << endl;
	return word;
}
//This function Constructs every string that can be made by inserting any letter of the 
//alphabet at any position in the string. (26*(n+1) possibilities)
void WordChecker::insertLetter(string word, int pos){
	if (pos != word.length())
		//Goes through the ASCII Code(Alphabets a-z)
		//and inserts letters throughout the string
		for (char ch = 97;ch < 123;ch++) {
			word[pos] = ch;
			if (dictionary.find(word.c_str()) != dictionary.end()  )
			{
				dictionary[word] = true;
			}
		}
}

//This function constructs every string that can be made by swapping 
//two neighboring characters in the string. (n-1 possibilities)
void WordChecker::swapLetters(string word)
{
	    //Goes through the length of the word
		for (int i = 0; i < word.length(); i++)
		{
			//swaps the neighboring characters as it goes through the string
			swap(word[i], word[i + 1]);
			if (dictionary.find(word.c_str()) != dictionary.end()) {
				dictionary[word] = true;
			}
			swap(word[i], word[i + 1]);
		}
}
//This function constructs  every string that can be made 
//by replacing each letter in the word with some letter of the alphabet. 
//(26*n possibilities (including the original word n times, 
//is probably easier than avoiding it))  
void WordChecker::replaceLetter(string word, int pos)
{
	
	for (char ch = 97;ch < 123;ch++) {
			word[pos] = ch;
			if (dictionary.find(word.c_str()) != dictionary.end())
			{
				dictionary[word] = true;
			}
		}
}
//Construct every pair of strings that can be made by inserting a space into the word. (n-1 pairs of words; 
//you have to check separately in the dictionary for each word in the pair)
void WordChecker::insertSpace(string word)
{
	string words[2];
	//Goes through the length of the word
	for (int x = 0;x < word.length();x++) {
		//These two lines break the word into two, and inserts an space
		words[0] = word.substr(0, x);
		words[1] = word.substr(x + 1);
		//Checks the first half of the word to if its in the dictionary
		if (dictionary.find(words[0].c_str()) != dictionary.end())
		{
			dictionary[words[0]] = true;
		}
		//checks the second half of the word tp see if its in the dictionary
		if (dictionary.find(words[1].c_str()) != dictionary.end())
		{
			dictionary[words[1]] = true;
		}
	}

}