#include "stdafx.h"
#include <iostream>

using namespace std;

void Merge(int Array[], int workArray[], int begin1, int end1, int begin2, int end2)
{
	int counter1 = begin1, counter2 = begin2;
	for (int counter3 = begin1; counter3 <= end2; counter3++){
		if ((counter1 <= end1) && ((counter2 > end2) || Array[counter1] <= Array[counter2])){
			workArray[counter3] = Array[counter1];
			counter1++;
		}
		else{
			workArray[counter3] = Array[counter2];
			counter2++;
		}
	}
}


void CopyArray(int firstArray[], int iBegin, int iEnd, int secondArray[])
{
	for (int counter = iBegin; counter <= iEnd; counter++){
		firstArray[counter] = secondArray[counter];
	}
}

void NaturalMergeSort(int Array[], int arraySize)
{
	if (arraySize < 2)
		return;

	int *workArray = (int *)malloc(sizeof(int)*(arraySize));
	int isSortedFlag = 0;
	while (isSortedFlag == 0){
		int begin1 = 0, 
			end1 = 0, 
			begin2 = 0, 
			end2 = 0;
		while (end1 < (arraySize - 1)){
			if (Array[end1] <= Array[end1 + 1]){
				end1++;
			}
			else{
				for (begin2 = end2 = (end1 + 1); end2 < (arraySize - 1); end2++){
					if (Array[end2] <= Array[end2 + 1]){
						continue;
					}
					else{
						break;
					}
				}
				Merge(Array, workArray, begin1, end1, begin2, end2);
				CopyArray(Array, begin1, end2, workArray);
				begin1 = end1 = (end2 + 1);
			}
			
		}
		if ((begin2 == 0) && (end2 == 0)){
			isSortedFlag = 1;
		}
	}
}
