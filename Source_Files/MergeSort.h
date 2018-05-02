
/*  Author:VinayKhedekar, Email: vinay.khedekar@csu.fullerton.edu  
  *
  * This file holds the class defination for Merge Sort algorithm. 
  * It accepts input array and initialize the required variables including count, length, leftStart, rightStart, leftEnd etc.
*/

#pragma once
#include <iostream>
#ifndef MERGESORT_H
#define MERGESORT_H
using namespace std;

class MergeSort {
	int inputArray[12] = { 0 };
	int* mArray = new int[12];

public:
	int count = 0,
		leftStart = 0,
		leftEnd = 0,
		leftNext = 0,
		rightStart = 1,
		rightNext = 1,
		rightEnd = 1,
		length = 0,
		sublistLength = 1,
		complete = 0;
	MergeSort(int[], int);
	int* mergeStep();
};


#endif