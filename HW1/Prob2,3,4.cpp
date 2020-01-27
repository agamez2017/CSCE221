/* Use the STL class vector<double> to write a C++ function that takes two vectors, a
and b, of the same size and returns a vector c such that c[i] = a[i]·b[i]. How many scalar multiplications
are used to create elements of the vector c of size n? What is the classification of this algorithm in
terms of the Big-O notation?
*/
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

struct invalid_input : public exception {
  virtual const char* what() const throw()
  { return "Invalid input"; }
};
vector<double> multiply(vector<double>& a, vector<double>&  b)
{
	double ci;
	vector<double> c;
	if(a.size()!=b.size())
	{
		throw invalid_input();
	}
	else{
		for(int i=0; i<a.size();i++)
		{
			ci= a[i]*b[i];
			c.push_back(ci);
		}
	}
	return c;
}

bool found_odd_product(vector<int>& a)
{
	bool found_odd =false;
	while(!found_odd)
	{
	for(int i=0;i<a.size();i++)
	{
		for(int j=a.size()-1; j>i; j--)
		{
			if((a[i]*a[j])%2==1)
			{
				found_odd = true;
				break;
			}
		}
	}
	}
	return found_odd;
}

template <class T> 
int BinarySearch(vector<T>& a, T x)
{
	if(a.size()<=0)
	{
		throw invalid_input();
	}
	else
	{
		int index_start =0;
		int index_end=a.size()-1;
		while(index_start < index_end)
		{
			int middle_index = (index_start+index_end)/2;
			if(a[middle_index]==x)
			{
				return middle_index; break;
			}
			else if(x>a[middle_index])
			{
				index_start= middle_index+1;
			}
			else
			{
				index_end= middle_index;
			}
		}
		return index_start;
	}
}
int main()
{
	
	cout<<"Prob 2\n";
	vector<double> a1 = {4, 4, 3, 4, 32, 3};
	vector<double> b1 = {1, 2, 7, 12, 3, 5};
	vector<double> c1 = multiply(a1,b1);
	for(int i=0; i<c1.size();i++) //print out resulting vector 
	{
		cout<<c1[i]<<" ";
	}
	cout<<endl;
	cout<<"------------------------------------------------\n";
	cout<<"Prob 3\n";
	vector<int> a2 = {2,4,6,10,1,11};
	cout<<"Vector: "<<endl;
	for(int i=0;i<a2.size();i++)
	{
		cout<<a2[i]<<" ";
	}
	cout<<endl;
	cout<<"Odd product found (0 =no) (1=yes) : "<<found_odd_product(a2)<<endl;
	cout<<"-------------------------------------------------\n";
	cout<<"Prob 4\n";
	vector<int> a3 = {1, 3, 7, 15, 20, 22};
	int x =7;
	cout<<"Index of target: ";
	cout<<endl;
	cout<<BinarySearch(a3,x);
	
}