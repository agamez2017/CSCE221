//============================================================================
// Name        : insertion-sort.cpp
// Author      : Jessica Lefkowitz
// Date        : 2/16/2019
// Description : Implementation of insertion sort in C++
//============================================================================

#include "sort.h"
#include <vector>
void 
InsertionSort::sort(vector<int>& A, int size)				// main entry point
{
  for (int k = 1; k< size; k++)
	{
		int temp = A[k];
		int j = k-1;
		while((num_cmps++, j>=0 && A[j] > temp))
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = temp;
	}
}
