/* 
  * Author:VinayKhedekar, Email: vinay.khedekar@csu.fullerton.edu
  *
  * This file contains the logic for Bubble Sort algorithm. 
  * The logic is implemented in such a way that it will process one comparision at a time.
  * The bubbleStep() method checks the conditions including-
  * 1.  When the swap needed
  * 2.  comparision made its last move and array is sorted and completed
  * 3. Only comparision made and array has not finished sorting
*/
#include <iostream>
#include "BubbleSort.h"
using namespace std;

int* BubbleSort::bubbleStep()
{
	if (inputArray[currentSuffix] < inputArray[currentPrefix])
	{//SWAP NEEDS TO BE MADE
		inputArray[currentSuffix] = inputArray[currentSuffix] + inputArray[currentPrefix];
		inputArray[currentPrefix] = inputArray[currentSuffix] - inputArray[currentPrefix];
		inputArray[currentSuffix] = inputArray[currentSuffix] - inputArray[currentPrefix];
		
		if (currentPrefix > 0)
		{//MORE COMPARISONS IN PREFIX NEEDED
			complete = 0;
			currentPrefix--;
			currentSuffix--;
		}
		else
		{//PREFIX HAS NO REMAINING COMPARISONS
			complete = 0;
			prefixLength++;
			currentPrefix = prefixLength-1;
			currentSuffix = currentPrefix + 1;
		};

		if (prefixLength == length && currentSuffix == length)
		{//SWAP MADE IS LAST SWAP AND bArray IS SORTED
			complete = 2;
		};
		count++;
		return bArray;
	}
	else if (inputArray[currentSuffix] > inputArray[currentPrefix])
	{//COMPARISON ONLY, not finished sorting
		prefixLength++;
		currentPrefix++;
		currentSuffix = currentPrefix + 1;
		if (currentPrefix == length)
		{//Array is finished sorting after comparison
			count++;
			complete = 2;
			return bArray;
		}
		else if (currentPrefix < currentSuffix && currentSuffix < length)
		{//Array is not finished sorting after comparison
			count++;
			complete = 1;
			return bArray;
		}
		else if (currentPrefix < currentSuffix && currentSuffix == length)
		{
			count++;
			complete = 2;
			return bArray;
		};
	};

}

BubbleSort::BubbleSort(int receivedArray[], int receivedLength)
{
	memcpy(inputArray, receivedArray, sizeof(int) * 12);
	bArray = inputArray;
	length = receivedLength;
}