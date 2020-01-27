/* Classes ArithmeticProgression and GeometricProgression
derived from the class Progression
*/
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class Progression{
	protected:
	long double initial_val;
	long double current_val;
	vector<long double> container;
	public:
	virtual long double getNext()=0;
	virtual long double sum()=0;
	void printProg()
	{
		for(int i=0; i<container.size();i++)
		{
			cout<<container[i]<<" ";
		}
		cout<<endl;
	}
};

class ArithmeticProgression: public Progression {
	private:
	long double diff;
	public:
	ArithmeticProgression(){initial_val =0; current_val=0; diff =0; };
	ArithmeticProgression(long a, long double d, int n)
	{
		diff = d;
		initial_val = a;
		current_val = initial_val;
		container.push_back(initial_val);
		for(int i =0; i<n-1;i++)
		{
			getNext();
		}
	}
	long double getNext()
	{
		current_val += diff;
		container.push_back(current_val);
		return current_val;
	}
	long double sum()
	{
		double sum=0;
		for(int i=0; i<container.size();i++)
		{
			sum+=container[i];
		}
		return sum;
	}
}; 

class GeometricProgression: public Progression {
	private:
	long double ratio;
	public:
	GeometricProgression(){initial_val =0; current_val =0; ratio=0;};
	GeometricProgression(long a, long double r, int n)
	{
		ratio = r;
		initial_val =a;
		current_val = initial_val;
		container.push_back(initial_val);
		for(int i=0; i<n-1;i++)
		{
			getNext();
		}
	}
	long double getNext()
	{
		current_val*=ratio;
		container.push_back(current_val);
		return current_val;
	}
	long double sum()
	{
		double sum=0;
		for(int i=0;i<container.size();i++)
		{
			sum+=container[i];
		}
		return sum;
	}
};

int main()
{
	ArithmeticProgression ar1(1,3,10);
	cout<<"Arithmetic Progression: ";
	cout<<endl;
	ar1.printProg();
	cout<<"Sum of sequence: "<<ar1.sum();
	cout<<endl;
	cout<<"Next term of sequence: "<<ar1.getNext();
	cout<<endl;
	cout<<"-------------------------------------------------\n";
	GeometricProgression mr1(1,3,10);
	cout<<"Geometric Progression: ";
	cout<<endl;
	mr1.printProg();
	cout<<"Sum of sequence: "<<mr1.sum();
	cout<<endl;
	cout<<"Next term of sequence: "<<mr1.getNext();
}