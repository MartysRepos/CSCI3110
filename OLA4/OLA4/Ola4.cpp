//Martavious Dorsey
//Due Date: 10/24/16
//Description:In this assignment, you will examine the efficiencies of several different sorting algorithms 
//– bubble sort, insertion sort, mergesort, and quicksort, 
//and empirically test their running times on random data, sorted data ( in ascending order ) 
//and inverse sorted data (in descending order).




#include <iostream>
#include <time.h>
#include "algorithm.h"
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <ostream>
#include <fstream>

using namespace std;


int diffclock(clock_t clock1, clock_t clock2);
int main() {
	unsigned int myarray[15] = { 10,50,100,300,400,500,1000,2000,3000,4000,5000,10000,50000,100000 };
	ofstream myOut;
	myOut.open("results.dat");
	myOut << "ArraySize\tBubble\t\tInsertion\tMergeSort\tQuicksort\n";
	for (int x = 0;x <14;x++){
		int *arr = new int[myarray[x]];
		int *orig = new int[myarray[x]];
		for (int j = 0; j < myarray[x]; j++) {
			arr[j] = rand()%myarray[x];
			orig[j] = arr[j];
		}
		myOut << fixed << setw(3) << myarray[x] << '\t';
		clock_t begin, end;
		begin = clock();
		bubbleSort(arr, myarray[x]);
		end = clock();
		myOut << fixed << diffclock(begin, end) << '\t';

		for (int y = 0; y < myarray[x];y++)
			arr[y] = orig[y];

		begin = clock();
		insertionSort(arr,myarray[x]);
		end = clock();
		myOut << fixed <<  diffclock(begin, end) << '\t';

		for (int y = 0; y < myarray[x];y++)
			arr[y] = orig[y];

		begin = clock();
		int*temp = new int[myarray[x]];
		mergesort(arr, 0, myarray[x]- 1,temp);
		delete[] temp;
		end = clock();
		myOut << fixed <<  diffclock(begin, end) << '\t';


		for (int y = 0; y < myarray[x];y++) 
			arr[y] = orig[y];

			begin = clock();
			quicksort(arr, 0, myarray[x] - 1);
			end = clock();
		    myOut << fixed << diffclock(begin, end) << '\n';
		
		   	delete[] arr;
	}
	myOut.close();
}
int diffclock(clock_t clock1, clock_t clock2) {
	int diffticks = clock2 - clock1;
	int diffms = (diffticks) / CLOCKS_PER_SEC;
	return diffms;
}