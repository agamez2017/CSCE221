//============================================================================
// Name        : shell-sort.cpp
// Author      : Adrian Gamez-Rodriguez
// Date        : 2/16/2019
// Description : Implementation of shell sort in C++
//============================================================================
#include <vector>
#include "sort.h"
#include <iostream>
void
ShellSort::sort(vector<int>& A, int size)
{
	int tmp;
	for (int gap = size/2; gap > 0; gap = gap/2) 
	{
		for (int j = gap; j < size; j++)
		{
			tmp = A[j];
			int k = j;
			while((num_cmps++, k>=gap && tmp < A[k-gap]))
			{
				A[k]= A[k-gap];
				k-=gap;
			}
			A[k] = tmp;
		}
	}
}
