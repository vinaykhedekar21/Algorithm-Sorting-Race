/*  Author:VinayKhedekar, Email: vinay.khedekar@csu.fullerton.edu 
  * 
  * This file contains the logic for Merge Sort algorithm. 
  * The logic is implemented in such a way that it will process one comparision at a time.
  * The MergeStep() method checks the conditions including-
  * 1. Whether left and right sublist have finished sorting?
  * 2. If both sublists have finished at their length, do not double the  sublist as array is sorted.
  * 3. Whether left sublist have finished sorting but right sublist still not finished?
*/

#include <iostream>
#include "MergeSort.h"
using namespace std;

int* MergeSort::mergeStep()
{
	if (sublistLength < length)
	{
		if (inputArray[leftStart] > inputArray[rightStart])
		{//left sublist won comparison
			inputArray[rightStart] = inputArray[rightStart] + inputArray[leftStart];
			inputArray[leftStart] = inputArray[rightStart] - inputArray[leftStart];
			inputArray[rightStart] = inputArray[rightStart] - inputArray[leftStart];

			if (leftStart < leftEnd)
			{//sublist on leftside is not finished after left sublist won
				leftStart++;
				complete = 0;//swap has happened
				count++;
				return mArray;
			}
			else if (leftStart == leftEnd && rightStart == rightEnd && rightEnd != (length-1))
			{//both sublists are finished at their length
			 //incrementing both sublists up one sublist length to next sublist position
				if (leftStart == leftEnd && rightStart == rightEnd && rightEnd + 1 == length-1)
				{
					leftStart = rightEnd;
					leftEnd = leftStart;
					rightStart = leftStart + 1;
					rightEnd = rightStart;
					complete = 0;
					count++;
					return mArray;
				}
				else{
					leftStart = rightEnd + 1;
					leftEnd = leftStart + (sublistLength - 1);
					rightStart = leftEnd + 1;
					rightEnd = rightStart + (sublistLength - 1);
					complete = 0;
					count++;
					return mArray;
				};

			}
			else if (leftStart == leftEnd && rightStart == rightEnd && rightEnd == (length-1))
			{//both sublists are finished at their length 
			 //additionally, the right sublist end is the end of the array, sublist can be doubled
				//Check if arbitrary call was made with a sorted array state
				if (sublistLength*2 >= length)
				{
					//no need for incrementing count as this test means the comparison was made post-fix and was unnecessary in terms of step count.
					count++;
					complete = 2;
					return mArray;
				};
				sublistLength *= 2;
				leftStart = 0;
				leftEnd = leftStart + (sublistLength-1);
				rightStart = leftEnd + 1;

				if (rightStart < (length-1))
				{//right sublist doesn't reach over end
					rightEnd = rightStart + (sublistLength - 1);
					complete = 0;
					count++;
					return mArray;
				}
				else if ((rightStart+(sublistLength-1)) > (length-1))
				{
					rightEnd = (length - 1);
					complete = 0;
					count++;
					return mArray;
				};

			}
			else if (leftStart == leftEnd && rightStart == rightEnd && rightEnd == (length-1) && (sublistLength * 2) > length)
			{//both sublists are finished at their length, but sublist cannot be doubled (meaning array is sorted)
				complete = 2;
				count++;
				return mArray;
			}
			else if(leftStart == leftEnd && rightStart < rightEnd)
			{//right sublist is not finished, left sublist is at last value
				leftStart++;
				leftEnd = leftStart;
				rightStart = leftStart + 1;
				rightEnd = length - 1;
				complete = 0;//swap has happened
				count++;
				return mArray;
			};
		}
		else if (inputArray[leftStart] < inputArray[rightStart])
		{//right sublist won comparison // these numbers are sorted
			if (leftStart < leftEnd)
			{//sublist on leftside is not finished after right sublist won
				leftStart++;
				complete = 0;
				count++;
				return mArray;
			}
			else if (leftStart == leftEnd && rightStart == rightEnd && rightEnd != length - 1)
			{//both sublists are finished at their length
			 //incrementing both sublists up one sublist length to next sublist position
				leftStart = rightEnd + 1;
				leftEnd = leftStart + (sublistLength - 1);
				rightStart = leftEnd + 1;
				rightEnd = rightStart + (sublistLength - 1);
				complete = 0;
				count++;
				return mArray;
			}
			else if (leftStart == leftEnd && rightStart == rightEnd && rightEnd == length-1 && (sublistLength * 2) <= length)
			{//both sublists are finished at their length 
			 //additionally, the right sublist end is the end of the array, sublist can be doubled
				if (sublistLength * 2 >= length)
				{
					//no need for incrementing count as this test means the comparison was made post-fix and was unnecessary in terms of step count.
					count++;
					complete = 2;
					return mArray;
				};
				
				//prepare for resetting to beginning of array
				sublistLength *= 2;
				leftStart = 0;
				leftEnd = leftStart + (sublistLength - 1);
				rightStart = leftEnd + 1;

				if ((rightStart + (sublistLength - 1)) < (length - 1))
				{//right sublist doesn't reach over end
					rightEnd = rightStart + (sublistLength - 1);
					complete = 0;
					count++;
					return mArray;
				}
				else if ((rightStart + (sublistLength - 1)) > (length - 1))
				{//right sublist would reach over end
					rightEnd = (length - 1);
					complete = 0;
					count++;
					return mArray;
				};

			}
			else if (leftStart == leftEnd && rightStart == rightEnd && rightEnd == length && (sublistLength * 2) > length)
			{//both sublists are finished at their length, but sublist cannot be doubled (meaning array is sorted)
				complete = 2;
				count++;
				return mArray;
			}
			else if (leftStart == leftEnd && rightStart < rightEnd)
			{//left sublist is finished, but right sublist is not finished
				leftStart++;
				leftEnd = leftStart;
				rightStart = leftStart + 1;
				rightEnd = length - 1;
				complete = 1;//swap has not happened
				count++;
				return mArray;
			};
		};
	};
}

MergeSort::MergeSort(int receivedArray[], int receivedLength)
{
	memcpy(inputArray, receivedArray, sizeof(int) * 12);
	mArray = inputArray;
	length = receivedLength;
}