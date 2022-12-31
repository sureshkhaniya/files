/*
Name:- Suresh Khaniya
Professor Name:- Michael Thompson
file:- 01
Date :- 11/1/2022 A.D.
Subject :-  L.CSC 225 (Data Structures and Algorithim)
Description :- C++ program that analyzes the following sorts by keeping track of how long they the take to sort arrays of ints of size 5000, 10000, and 100000,
as well as the number of swaps and comparisons amonst Insertion Sort, Selection Sort, Quick Sort, and shell Sort.
*/

#include <iostream> 
#include <ctime>  // for time.
#include <cstdlib> //for rand.
#include <iomanip>


using namespace std;

struct swapcomp {      //Declaring structure swapcomp for every sorting Algorithm.

	long long swap;
	long long comp;
};

const int MAX_SIZE = 100000; // Global variable.
const int GAP = 20;

//Function Porotypes for Sorting Algorithm from zybooks

void selectionSort(int[], int);
void insertionSort(int[], int);
void shellSort(int[], int, int[], int);
void quicksort(int[], int, int);


void StructIni(swapcomp& suresh) {

	suresh.comp = 0;
	suresh.swap = 0;
}

//SelectionSort function from zybooks.
void selectionSort(int COPYARRAY[], int& sizeofarray,swapcomp& suresh) {
	int     indexSmallest = 0;
	int  temp = 0;// Temporary variable for swap
	for (int i = 0; i < sizeofarray - 1; ++i) {
	
		// Find index of smallest remaining element
		indexSmallest = i;
		for (int j = i + 1; j < sizeofarray; ++j) {
			suresh.comp++;
			if (COPYARRAY[j] < COPYARRAY[indexSmallest]) {
				indexSmallest = j;
			}
		}
// Swap 
		suresh.swap++;
		temp = COPYARRAY[i];
		COPYARRAY[i] = COPYARRAY[indexSmallest];
		COPYARRAY[indexSmallest] = temp;

	}
}
void Structsecond(swapcomp& sureshkhaniya) {  //insertion Sort

sureshkhaniya.comp = 0;
	sureshkhaniya.swap = 0;
}


//zybooks.
void insertionSort(int COPYARRAY[], int sizeofarray,swapcomp& sureshkhaniya) {
	int i = 0;
	int j = 0;
	int temp = 0; // Temporary variable for swap

	for (i = 1; i < sizeofarray; ++i) {
		j = i;
		
		sureshkhaniya.comp++;
		sureshkhaniya.swap++;
		while (j > 0 && COPYARRAY[j] < COPYARRAY[j - 1]) {

			
			
			// Swap numbers[j] and numbers[j - 1]
			

			temp = COPYARRAY[j];
			
			COPYARRAY[j] = COPYARRAY[j - 1];
			COPYARRAY[j - 1] = temp;
			--j;
		}
	}
}

void Structthird(swapcomp& suresh1) {  //quicksort

	suresh1.comp = 0;
	suresh1.swap = 0;
}

//QuickSort from zybooks


int partition(int  COPYARRAY[], int lowIndex, int highIndex, swapcomp& suresh1) {

	int midPoint = lowIndex + (highIndex - lowIndex) / 2;
	int pivot = COPYARRAY[midPoint];

	bool done = false;

	while (!done) {
		// Increment lowIndex while numbers[lowIndex] < pivot
		suresh1.comp++;
		while (COPYARRAY[lowIndex] < pivot) {
			lowIndex += 1;
			suresh1.comp++;

		}

		// Decrement highIndex while pivot < numbers[highIndex]
		suresh1.comp++;
		while (pivot < COPYARRAY[highIndex]) {
			highIndex -= 1;
			suresh1.comp++;
		}

		// If zero or one elements remain, then all numbers are
		// partitioned and return highIndex

		if (lowIndex >= highIndex) {
			done = true;
		}
		else {

			// Swap numbers[lowIndex] and numbers[highIndex]
		
			int temp = COPYARRAY[lowIndex];

			COPYARRAY[lowIndex] = COPYARRAY[highIndex];
			COPYARRAY[highIndex] = temp;
			suresh1.swap++;

			lowIndex += 1; // Increment lowIndex pointer
			highIndex -= 1; // Increment highIndex pointer
		}

	}

	return highIndex;
}

/*
The Function that calls partition function recursively and sorts the input array
*/
void quicksort(int COPYARRAY[], int lowIndex, int highIndex,swapcomp& suresh1) {
	// Base Case: If partition size is zero or 1 elements, then the partition is already sorted
	if (lowIndex >= highIndex) {
		return;
	}
	else {

		// Partition the input array around pivot
		int lowEndIndex = partition(COPYARRAY, lowIndex, highIndex, suresh1);


		// Recursively call quickSort on left half and right half
		quicksort(COPYARRAY, lowIndex, lowEndIndex, suresh1);
		quicksort(COPYARRAY, lowEndIndex + 1, highIndex,suresh1);
	}
}

int main(void) {
	
	int ARRAY[MAX_SIZE];
	int COPYARRAY[MAX_SIZE];
	int sizeofarray;

	int count = 0;
	double start2;
	double end2;
	double start;
	double end;
	 double time;
	 double start3;
	  double end3;
	


	
	swapcomp suresh;    // for selection sort
	swapcomp sureshkhaniya; // forinsertion sort
	swapcomp suresh1;      //for QuickSort.
	//asking Input from User.

	cout << "Size ?  " << endl;
	cin >> sizeofarray;

	

	//Data Validation for size of array.

	while (sizeofarray > 100000) {
		cout << "Please enter the number of array for size  < 100000 : ";
		cin >> sizeofarray;

	}

	for (int i = 0; i < sizeofarray; i++) {
		ARRAY[i] = rand();
		COPYARRAY[i] = ARRAY[i];    //Duplicate ARRAY.
	}
	cout << endl;

	//Declaration of gaparray1 and gaparray2 for shell short.
	int gaparray1[GAP];
	int gaparray2[GAP];

	int temp = sizeofarray;

	//	Shell sort (using gaps of n/2, n/4, n/8, ..., 1)


	do {
		temp = temp / 2;
		gaparray1[count] = temp;
		count = count + 1;


	} while (count < 20 && temp > 1);

	cout << "Divide by 2 has " << count << " gaps." << endl;
	cout << "Gap Values :  ";
	for (int i = 0; i < count; i++) {
		cout << gaparray1[i] << " ";
	}


	cout << endl;

	//	 FOR Shell sort (using gaps based on 2k - 1)


	int base = 1;
	count = 0;
	cout << endl;


	while ((base * 2 < sizeofarray) && (count < 20)) {
		base = base * 2;
		gaparray2[count] = base - 1;



		//	cout << gaparray2[count] << " ";
		count++;


	}
	cout << endl;
	cout << "(2k - 1) has " << count << " gaps." << endl;

	cout << "Gap Values :";
	for (int i = 0; i < count; i++) {
		cout << gaparray2[i] << " ";
	}

	

	//Reversing the array by Swapping. 
	for (int i = 0; i < count / 2; i++) {     //sizeofarray2 for swapping half from either side.

		temp = gaparray2[i];
		gaparray2[i] = gaparray2[count - 1 - i];
		gaparray2[count - 1 - i] = temp;
	}
	cout << endl;
	cout << endl;

	//printing Reverse array                                                              
	cout << "The Reverse order of array  for 2k-1 is  :" << endl;
	for (int i = 0; i < count; i++) {
		cout << gaparray2[i] << " ";
	}
	cout << endl;

	cout << endl;

	cout << setw(13) << left << "Sort" << setw(13) << left << "Time" << setw(13) << left << "Comps" << setw(13) << left << "Swaps" << endl;


	//Time period for  SelectionSort.
	StructIni(suresh);
	start = clock();
	selectionSort(COPYARRAY, sizeofarray, suresh);
	end = clock();
	
	time = (end - start) / CLOCKS_PER_SEC;
	
	cout << setw(13) << left << "Selection" << setw(13) << left << time << setw(13) << left << suresh.comp << setw(13) << left <<  suresh.swap << endl;

	//Time period for Insertion Sort.
	Structsecond(sureshkhaniya);
	start2 = clock();
	insertionSort(COPYARRAY, sizeofarray, sureshkhaniya);
	end2 = clock();
	time = (end2 - start2) / CLOCKS_PER_SEC;
	cout << setw(13) << left << "Insertion" << setw(13) << left << time << setw(13) << left << sureshkhaniya.comp << setw(13) << left << sureshkhaniya.swap << endl;

 //time period for QuickSort.
	Structthird(suresh1);
	start3 = clock();
	 quicksort(COPYARRAY,0,sizeofarray-1,suresh1);
	end3 = clock();
	time = (end3 - start3) / CLOCKS_PER_SEC;
	cout << setw(13) << left << "Quick Sort" << setw(13) << left << time<< setw(13) << left << suresh1.comp << setw(13) << left << suresh1.swap << endl;

	return 0;
}

