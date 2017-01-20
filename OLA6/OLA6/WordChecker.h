#pragma once
//Martavious Dorsey
//Due Date: 11-16-16
//Description: The Header file wherer the methods and members stored
#include <string>
#include <unordered_map>

using namespace std;


class WordChecker {

public:
	WordChecker();
	string deleteLetter(string word, int pos);
    void insertLetter(string word, int pos);
	void swapLetters(string word);
	void replaceLetter(string word, int pos);
	void insertSpace(string word);
	void readInDictionary();
	bool checkWord(string word);
	void wordSuggestion(string word);
	void findWords(string word, int wordsize);

private:
	unordered_map < string, bool > dictionary;
	vector <string> s;

};
