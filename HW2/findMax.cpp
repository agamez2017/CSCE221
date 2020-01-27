#include <iostream>
#include <cstdlib>

using namespace std;

int findMax(int a[], int lastIndex, int max)
{
	if(lastIndex == 0) //has reached the base case
	{	
		if(a[lastIndex]> max)
		{
			max = a[lastIndex];
		}
		return max;
	}
	else
	{
		if(a[lastIndex]> max)
		{
			max = a[lastIndex];
		}
		return findMax(a,lastIndex-1,max);
	}
}

int main()
{
	int a1[] = {1,2,3,4,5,6,7,8};
	int sizea1 = sizeof(a1)/sizeof(*a1);
	cout<<"a1: ";
	for(int i=0; i<sizea1;i++)
	{
		cout<<a1[i]<<" ";
	}
	cout<<endl;
	cout<<"a1's max: ";
	cout<<findMax(a1,7,a1[0])<<endl;
	
	int a2[] = {32,3453,25,634,2,23,245,643,24,67,79};
	int sizea2 = sizeof(a2)/sizeof(*a2);
	cout<<"a2: ";
	for(int i=0; i<sizea2; i++)
	{
		cout<<a2[i]<<" ";
	}
	cout<<endl;
	cout<<"a2's max: ";
	cout<<findMax(a2,10,a2[0]);
	
	
}