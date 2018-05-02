/*  
  * Author:VinayKhedekar, Email: vinay.khedekar@csu.fullerton.edu
  *
  * This is the main file as we called it Race Manager (RaceMgr) for Bubble Sort and Merge Sort algorithms. 
  * This file contains below logic-
  * 1.  It accepts the user input string elements and stores them into the integer array.
  * 2.  It consist of objects for the sorting alogorithms, in our case Bubble sort object and Merge Sort object.
  * 3. It gives each algorithm a turn to execute a comparision operation alternatively. 
  * 4. It keeps track of which algorithm is still running and count of how many turn it took to complete the race. 
  * 5. Race Manager checks below conditions-
  *  a. Sorting Algorith has just made a step, not finished sorting
  *  b. Sorting Algorithm has only made a comparison
  *  c. Sorting Algorithm has just made it's last switch, Algorithm has completed 
  *  d. Sorting Algorith has just made a step, not finished sorting
  * 6. Also, it print out three main items-
  * a. The current step call count
  * b. The algorithm's ID letter (I, B, M, H, or Q)
  * c. The current state of the algorithm's integer array inside brackets and final output as  #12, B: [2, 4, 3, 6, 14, 10, 9, 1]
  * 
*/

# include <iostream>
#include "BubbleSort.h"
#include "MergeSort.h"
using namespace std;

int main(){
	int size;
	cout << "\n Enter number of elements you want to sort:";
	cin >> size;

	int elementArray[12];
	int* bubbleArray = new int[12];
	int* mergeArray = new int[12];

	for (int i = 0; i < size; i++) {
		cout << "Enter Element " << i + 1 << ": ";
		cin >> elementArray[i];
	}
	//quickArray = elementArray;
	cout << "Initial Array Elements are: [ ";
	for (int i = 0; i < size; i++) {

		cout << elementArray[i] << " ";
	}
	cout << ']' << endl;

	//Create instance of BubbleSort Class and MergeSort Class and invoke step methode.
	BubbleSort bubbleSort(elementArray, size);
	MergeSort mergeSort(elementArray, size);

	while (bubbleSort.complete != 2 && mergeSort.complete != 2)//Need to add merge sort parameter
	{	

		if (bubbleSort.complete != 2)
		{
			bubbleArray = bubbleSort.bubbleStep();
			if (bubbleSort.complete == 0)
			{//Sorting Algorith has just made a step, not finished sorting
				cout << "\n #" << bubbleSort.count << ", B: [ ";
				for (int i = 0; i < size; i++) {

					cout << bubbleArray[i] << " ";
				}
				cout << "] " << endl;
			}
			else if (bubbleSort.complete == 1)
			{//Sorting Algorithm has only made a comparison
				cout << "\n #" << bubbleSort.count << ", B: [ ";
				for (int i = 0; i < size; i++) {

					cout << bubbleArray[i] << " ";
				}
				cout << "] " << endl;
			}
			else if (bubbleSort.complete == 2)
			{//Sorting Algorithm has just made it's last switch, Algorithm has completed 
				cout << "\n #" << bubbleSort.count << ", B: [ ";
				for (int i = 0; i < size; i++) {

					cout << bubbleArray[i] << " ";
				}
				cout << "] " << endl;
			};
		};

		if (mergeSort.complete != 2)
		{
			mergeArray = mergeSort.mergeStep();
			if (mergeSort.complete == 0)
			{//Sorting Algorith has just made a step, not finished sorting
				cout << "\n #" << mergeSort.count << ", M: [ ";
				for (int i = 0; i < size; i++) {

					cout << mergeArray[i] << " ";
				}
				cout << "]" << endl;
			}
			else if (mergeSort.complete == 1)
			{//Sorting Algorithm has only made a comparison
				cout << "\n #" << mergeSort.count << ", M: [ ";
				for (int i = 0; i < size; i++) {

					cout << mergeArray[i] << " ";
				}
				cout << "]" << endl;
			}
			else if (mergeSort.complete == 2)
			{//Sorting Algorithm has just made it's last switch, Algorithm has completed 
				cout << "\n #" << mergeSort.count << ", M: [ ";
				for (int i = 0; i < size; i++) {

					cout << mergeArray[i] << " ";
				}
				cout << "]" << endl;
			};
		};
	}

	// Final Printout of Sorting
	cout << "Bubble Sort completed sorting the array in " << bubbleSort.count << " steps.\n";
	cout << "Merge Sort completed sorting the array in " << mergeSort.count << " steps.\n";
	system("pause");
	return 0;
}