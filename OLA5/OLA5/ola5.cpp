//Martavious Dorsey

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <cmath>

using namespace std;

#include "BST.h"

//The name of the file containing binary search trees
const string    FileName = "bst.dat";

//The value indicating the end of a binary search tree
// in the file FileName
const int       SentinelValue = -1;


void iprint(int & x) {
	cout << x << endl;
}

void sprint(string & x) {
	cout << x << endl;
}

//If you need to count the number of nodes in a Binary 
//Search Tree of integers, please traverse the tree by passing
//the following function as the parameter.
//Remember, every time you count the number of nodes,
//you have to initialize nodeCount by 0
int nodeCount = 0;
void nodeNum(int& nodeValue)
{
	nodeCount++;
}

BinarySearchTree<string> insertFile() {
	BinarySearchTree<string>	tree;


	ifstream	ifs;	//open this file
	string		value;

	ifs.open(FileName);

	cout << "inserted words: ";
	while (ifs >> value) {
		/*if (!isalpha(value[0]))
			continue;*/
		if (!tree.searchTreeRetrieve(value)) {
			tree.searchTreeInsert(value);
			cout << value << " ";
		}
	}
	ifs.close();

	return tree;
}


int main(void)
{
	//construct a BST of ints
	BinarySearchTree<int>	tree;
	int						value;


	cout << "inserted integers: ";
	for (int i = 0; i < 20; ++i) {
		//value = rand() % 100 + 1;
		if (!tree.searchTreeRetrieve(value)) {
			tree.searchTreeInsert(value);
			cout << value << " ";
		}

		cout << endl << " in order traverse: " << endl;
		tree.inorderTraverse(iprint);

		BinarySearchTree<string>	words = insertFile();
		cout << endl << " in order traverse: " << endl;
		words.inorderTraverse(sprint);

		return 0;
	}
}

