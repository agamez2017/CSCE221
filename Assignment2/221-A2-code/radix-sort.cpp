//============================================================================
// Name        : radix-sort.cpp
// Author      : Phillip Wong
// Date        : 2/16/2019
// Description : Implementation of radix sort in C++
//============================================================================

#include "sort.h"
#include <iostream>
void countSort(vector<int>& B, int size, int digit)
{
	vector<int> output(size);
	int i;
	vector<int> count(10);
	for(i=0;i<size;i++)
	{
		count[(B[i]/digit)%10]++;
	}
	for(i=1;i<10;i++)
	{
		count[i] += count[i-1];
	}
	for(i =size-1; i>=0;i--)
	{
		output[count[(B[i]/digit)%10]-1]=B[i];
		count[(B[i]/digit)%10]--;
	}
	for(i=0;i<size;i++)
	{
		B[i]= output[i];
	}
}
void shiftInput(vector<int>& C, int size, int min)
{
	for(int i=0;i<size;i++)
	{
		C[i]=C[i]+(-1*min);
	}
}
void backToOriginal(vector<int>& D, int size, int min)
{
	for(int i=0;i<size;i++)
	{
		D[i]=D[i]+min;
	}
}
void
RadixSort::sort(vector<int>& A, int size)
{
	int min=A[0];
	int max= A[0];
	for(int i=1;i<size;i++)
	{
		if(A[i]>max)
		{
			max = A[i];
		}
		if(A[i]<min)
		{
			min =A[i];
		}
	}
	if(min<0)
	{
		shiftInput(A,size,min);
		for(int digit=1;max/digit>0;digit*=10)
		{
			countSort(A,size,digit);
		}
		backToOriginal(A,size,min);
	}
	else
	{
		for(int digit=1;max/digit>0;digit*=10)
		{
			countSort(A,size,digit);
		}
	}
}
