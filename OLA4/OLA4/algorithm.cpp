//Martavious Dorsey
//Due Date: 10/24/16
//Description: Implementation of the different sorting algorithms 
#include "algorithm.h"
#include <iostream>

using namespace std;


// ---------------------------------------------------
// Sorts the items in an array into ascending order.
// Precondition: theArray is an array of n items.
// Postcondition: theArray is sorted into ascending
// order; n is unchanged.
// Calls: swap.
// ---------------------------------------------------
void bubbleSort(DataType theArray[], int n) {
	bool sorted = false;  // false when swaps occur

	for (int pass = 1; (pass < n) && !sorted; ++pass)
	{  // Invariant: theArray[n+1-pass..n-1] is sorted
	   //            and > theArray[0..n-pass]
		sorted = true;  // assume sorted
		for (int index = 0; index < n - pass; ++index)
		{  // Invariant: theArray[0..index-1] <= 
		   // theArray[index]
			int nextIndex = index + 1;
			if (theArray[index] > theArray[nextIndex])
			{  // exchange items
				swap(theArray[index], theArray[nextIndex]);
				sorted = false;  // signal exchange
			}  // end if
		}  // end for

		   // Assertion: theArray[0..n-pass-1] < 
		   // theArray[n-pass]
	}  // end for
}  // end bubbleSort
   
// ---------------------------------------------------
// Swaps two items.
// Precondition: x and y are the items to be swapped.
// Postcondition: Contents of actual locations that x 
// and y represent are swapped.
 // ---------------------------------------------------
void swap(DataType& x, DataType& y)
{
	DataType temp = x;
	x = y;
	y = temp;
}  // end swap


// unsorted = first index of the unsorted region, 
// loc = index of insertion in the sorted region, 
// nextItem = next item in the unsorted region

// initially, sorted region is theArray[0], 
//            unsorted region is theArray[1..n-1];
// in general, sorted region is 
//             theArray[0..unsorted-1], 
// unsorted region is theArray[unsorted..n-1]
void insertionSort(DataType theArray[], int n)
{
	for (int unsorted = 1; unsorted < n; ++unsorted)
	{  // Invariant: theArray[0..unsorted-1] is sorted

	   // find the right position (loc) in 
	   // theArray[0..unsorted] for theArray[unsorted], 
	   // which is the first item in the unsorted 
	   // region; shift, if necessary, to make room
		DataType nextItem = theArray[unsorted];
		int loc = unsorted;

		for (;(loc > 0) && (theArray[loc - 1]> nextItem);
			--loc)
			// shift theArray[loc-1] to the right
			theArray[loc] = theArray[loc - 1];

		// Assertion: theArray[loc] is where nextItem 
		// belongs

		// insert nextItem into Sorted region
		theArray[loc] = nextItem;
	}  // end for

}
void merge(int theArray[], int first, int last, int *tempArray) {
	int mid = (first + last) / 2;
	int first1 = first;
	int last1 = mid;
	int first2 = mid + 1;
	int last2 = last;

	int index = first1;

	for (; (first1 <= last1) && (first2 <= last2); ++index) {
		if (theArray[first1] < theArray[first2]) {
			tempArray[index] = theArray[first1];
			++first1;
		}
		else {
			tempArray[index] = theArray[first2];
			++first2;
		}
	}
	// finish off the first subarray, if necessary
	for (; first1 <= last1; ++first1, ++index) {
	// Invariant: tempArray[first1..index-1] is in order
	tempArray[index] = theArray[first1];
}
	// finish off the second subarray, if necessary
	for (; first2 <= last2; ++first2, ++index)
		// Invariant: tempArray[first1..index-1] is in order
		tempArray[index] = theArray[first2];

	// copy the result back into the original array
	for (index = first; index <= last; ++index)
		theArray[index] = tempArray[index];
}
void mergesort(DataType theArray[], int first, int last, int *tempArray)
{
	if (first < last) {
		int mid = (first + last) / 2; //index of mid-point
		//sort left half theArray[first.mid]
		mergesort(theArray, first, mid,  tempArray);
		//sort right half theArray[mid+1..last]
		mergesort(theArray, mid + 1, last, tempArray);
		//merge the two halves
		merge(theArray, first, last, tempArray);
	}

}
void choosePivot(int theArray[], int first, int last) {
	int mid = (first + last) / 2;
	if ((theArray[first] <= theArray[mid] &&
		theArray[mid] <= theArray[last]) ||
		(theArray[last] <= theArray[mid] && 
		theArray[mid] <= theArray[first])) {
		swap(theArray[first], theArray[mid]);
	}
else if ((theArray[first] <= theArray[last] &&
		theArray[last] <= theArray[mid]) ||
		(theArray[mid] <= theArray[last] &&
			theArray[last] <= theArray[first])) {
		swap(theArray[first], theArray[last]);
	}
}

// ---------------------------------------------------------
// Partitions an array for quicksort.
// Precondition: theArray[first..last] is an array; 
// first <= last.
// Postcondition: Partitions theArray[first..last] such 
// that:
//    S1 = theArray[first..pivotIndex-1] <  pivot
//         theArray[pivotIndex]          == pivot
//    S2 = theArray[pivotIndex+1..last]  >= pivot
// Calls: choosePivot and swap.
// ---------------------------------------------------------
void partition(int theArray[],
	int first, int last, int& pivotIndex)
	
{
	// place pivot in theArray[first]
	choosePivot(theArray, first, last);
	int pivot = theArray[first];     // copy pivot

										  // initially, everything but pivot is in unknown
	int lastS1 = first;           // index of last item in S1
	int firstUnknown = first + 1; // index of first item in 
								  // unknown

								  // move one item at a time until unknown region is empty
	for (; firstUnknown <= last; ++firstUnknown)
	{  // Invariant: theArray[first+1..lastS1] < pivot
	   //         theArray[lastS1+1..firstUnknown-1] >= pivot

	   // move item from unknown to proper region
		if (theArray[firstUnknown] < pivot)
		{  // item from unknown belongs in S1
			++lastS1;
			swap(theArray[firstUnknown], theArray[lastS1]);
		}  // end if

		   // else item from unknown belongs in S2
	}  // end for
	//place the pivot in the proper position and mark its location
	swap(theArray[first], theArray[lastS1]);
	pivotIndex = lastS1;
	
}
void quicksort(DataType theArray[], int first, int last)
{
	int pivotIndex;

	if (first < last)
	{  // create the partition: S1, pivot, S2
	      partition(theArray, first, last, pivotIndex);

		// sort regions S1 and S2
		quicksort(theArray, first, pivotIndex - 1);
		quicksort(theArray, pivotIndex + 1, last);
	}  // end if
}  // end quicksort





