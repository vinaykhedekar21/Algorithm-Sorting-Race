/*  
  * Author:VinayKhedekar, Email: vinay.khedekar@csu.fullerton.edu
  *
  * This file holds the class defination for Bubble Sort algorithm. 
  * It accepts input array and initialize the required variables including prefix, suffix, count, length etc.
*/

#pragma once
#include <iostream>
#ifndef BUBBLESORT_H
#define BUBBLESORT_H
using namespace std;

class BubbleSort {
	int inputArray[12] = { 0 };
	int* bArray = new int[12];

public:
	int count = 0,
		complete = 0,
		currentSuffix = 1,
		currentPrefix = 0,
		prefixLength = 1,
		length = 0;
	BubbleSort(int[], int);
	int* bubbleStep();
};

#endif