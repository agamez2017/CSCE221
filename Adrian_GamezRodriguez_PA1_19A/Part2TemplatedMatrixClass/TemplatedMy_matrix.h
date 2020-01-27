/* Templated My_matrix.h
Header file for the class Templated class My_matrix
Function also defined here
Adrian Gamez-Rodriguez	126009409
*/
#include <iostream>
#include <exception>
#include <stdexcept>
#include <vector>
using namespace std;
// Definitions of user defined type exceptions 
struct invalid_input : public exception {
  virtual const char* what() const throw()
  { return "Invalid matrix input"; }
};

struct incompatible_matrices : public exception {
  virtual const char* what() const throw()
  { return "Incompatible matrices"; }
};

template<class T> 
class TemplatedMy_matrix{
  //member variables
  int n, m;
  T **ptr;
  void allocate_memory(); 
public:	
  //member functions
  TemplatedMy_matrix();  // default constructor
  TemplatedMy_matrix(int n1, int m1); // parameter constructor
  ~TemplatedMy_matrix(); // destructor
  TemplatedMy_matrix(const TemplatedMy_matrix<T>& mat); // copy constructor
  TemplatedMy_matrix(TemplatedMy_matrix<T>&& mat);  // move constructor (optional)
  TemplatedMy_matrix& operator=(const TemplatedMy_matrix<T>& mat); //copy assignment operator
  TemplatedMy_matrix& operator=(TemplatedMy_matrix<T>&& mat); // move assignment operator (optional)
  int number_of_rows() const; 
  int number_of_columns() const;
  void set_rows(int n1){n=n1;}//sets rows
  void set_columns(int m1){m =m1;}//sets columns
  void call_allocate_memory(){ allocate_memory();};//calls allocate memory 
  T* operator()(int i) const; // overloaded to access to ith row
  T& operator()(int i, int j); // overloaded to access (i,j) element
  T operator()(int i, int j) const; // overloaded to access (i,j) element
  T elem(int i, int j) const; // overloaded to access (i,j) element
  T& elem(int i, int j); // overloaded to access (i,j) element
};

template<typename T>
ostream& operator<<(ostream& out, const TemplatedMy_matrix<T>& mat);

template<typename T>
istream& operator>>(istream& in, TemplatedMy_matrix<T>& mat);

template<typename T>
TemplatedMy_matrix<T> operator+(const TemplatedMy_matrix<T>& mat1, const TemplatedMy_matrix<T>& mat2);

template<typename T>
TemplatedMy_matrix<T> operator*(const TemplatedMy_matrix<T>& mat1, const TemplatedMy_matrix<T>& mat2);

template<typename T>
TemplatedMy_matrix<T>::TemplatedMy_matrix()//default constructor
{
  n=0;
  m=0;
  ptr=nullptr;
}

template<typename T>
void TemplatedMy_matrix<T>::allocate_memory()//member variables
{
  ptr = new T*[n];
  for(int r=0; r<n; r++)
  {
	ptr[r] = new T[m];
  }
}

template<typename T>
TemplatedMy_matrix<T>::TemplatedMy_matrix(int n1, int m1) //parameter constructor
{
	if(n1<0||m1<0)
	{
		throw invalid_input();
	}
	n=n1;
	m=m1;
	this->allocate_memory();
}

template<typename T>
TemplatedMy_matrix<T>::TemplatedMy_matrix(const TemplatedMy_matrix& mat)//copy constructor
{
  n=mat.n;
  m=mat.m;
  if(mat.ptr)
  {
  ptr = new T*[n];
  for(int i=0;i<n;i++)
  {
	  ptr[i]=new T[m];
  }
  for(int i=0; i<n;i++)
  {
    for (int j=0;j<m; j++)
    {
      ptr[i][j]= mat.ptr[i][j];
    }
  }
  }
}

template<typename T>
TemplatedMy_matrix<T>::TemplatedMy_matrix(TemplatedMy_matrix&& mat)// move constructor
{
  n=mat.n;
  m=mat.m;
  ptr= mat.ptr;
  mat.n=0;
  mat.m=0;
  mat.ptr=nullptr;
}

template<typename T>
TemplatedMy_matrix<T>::~TemplatedMy_matrix()//destructor
{
	if(ptr)
  {
	for(int i=0;i<n;i++)
	{
	  delete [] ptr[i];
	}
  delete []ptr;
  }	
}

template<typename T>
TemplatedMy_matrix<T>& TemplatedMy_matrix<T>::operator=(const TemplatedMy_matrix& mat)//copy assignment operator
{
  int** q = new T*[mat.n];
   for(int r=0; r<mat.n; r++)
  {
	ptr[r] = new T[mat.m];
  }
  for(int r=0;r<mat.n;r++)
  {
	  for(int c=0;c<mat.m;c++)
	  {
		q[r][c]=mat(r,c);
	  }
  }
  for(int i=0;i<this->n;i++)
	{
	  delete [] ptr[i];
	}
  delete []ptr;
  n=mat.n;
  m=mat.m;
  ptr=q;
  return *this;
}

template<typename T>
TemplatedMy_matrix<T>& TemplatedMy_matrix<T>::operator=(TemplatedMy_matrix&& mat)// move assignment operator 
{
 for(int i=0;i<n;i++)
	{
	  delete [] ptr[i];
	}
  delete []ptr;
  ptr=mat.ptr;
  n=mat.n;
  m=mat.m;
  mat.n=0;
  mat.m=0;
  mat.ptr=nullptr;
  return *this;
}

template<typename T>
int TemplatedMy_matrix<T>::number_of_rows() const
{
  return n;
}

template<typename T>
int TemplatedMy_matrix<T>::number_of_columns() const
{
  return m;
}

template<typename T>
T* TemplatedMy_matrix<T>::operator()(int i) const //overloaded to access the ith row
{
	return ptr[i];
}

template<typename T>
T& TemplatedMy_matrix<T>::operator()(int i, int j) //overloaded to access (i,j) element
{
	return ptr[i][j];
}

template<typename T>
T TemplatedMy_matrix<T>::operator()(int i, int j)const //overloaded to access (i,j) element
{
 return ptr[i][j];
}

template<typename T>
T TemplatedMy_matrix<T>::elem(int i, int j) const
{
  if (i < 0 || i >= n) throw out_of_range("Out of range");
  if (j < 0 || j >= m) throw out_of_range("Out of range");
   else 
	  return ptr[i][j];
}

template<typename T>
T& TemplatedMy_matrix<T>::elem(int i, int j)
{
  if(i < 0 || i >= n) 
  {
	  throw out_of_range("Out of range");
  }
  if(j < 0 || j >= m)
  {  
	throw out_of_range("Out of range");
  }
  else 
	  return ptr[i][j];
}

template<typename T>
ostream& operator<<(ostream& out, const TemplatedMy_matrix<T>& mat)
{
  for(int r=0; r< mat.number_of_rows(); r++)
  {
	for(int c=0; c< mat.number_of_columns(); c++)
	{
	 out << mat(r,c) << " ";
	}
	out << endl;
  }
	return out;
}

template<typename T>
istream& operator>>(istream& in, TemplatedMy_matrix<T>& mat)
{
	int n,m,count;
	T val;
	vector<T> elem;//only utilized to count numbers in the input file
	in>>n;//read in rows
	in>>m;//read in columns
	while(in >>val)
	{
		elem.push_back(val);//used vector to keep track of input types after n and m
	}
	if(elem.size()==n*m)//if the vector has same ammount of elements as n*m then its good
	{
	in.clear();//clear end of file flag
	in.seekg(0,ios::beg);//go back to the beginning
	in.ignore(1000,'\n');//ignore first line 
	TemplatedMy_matrix<T>& new_mat = const_cast<TemplatedMy_matrix<T>&>(mat);//casted away constness
	new_mat.set_rows(n);
	new_mat.set_columns(m);
	new_mat.call_allocate_memory();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			in>>val;
			new_mat(i,j)=val;
		}
	}
	}
	else
	{
		cout<<"Matrix.txt file has different amount of elements than expected.\n";
		throw invalid_input();//meaning the expected number of elements for matrix was not met
	}
	return in;
}

template<typename T>
TemplatedMy_matrix<T> operator+(const TemplatedMy_matrix<T>& mat1, const TemplatedMy_matrix<T>& mat2)
{
  if(mat1.number_of_columns() == mat2.number_of_columns() && mat1.number_of_rows() == mat2.number_of_rows())
  {
	  int n=mat1.number_of_rows();
	  int m=mat1.number_of_columns();
	TemplatedMy_matrix<T> result(n,m);
	for(int r=0;r<mat1.number_of_rows();r++)
	{
		for(int c=0;c<mat1.number_of_columns();c++)
		{	
			result(r,c)= mat1(r,c)+mat2(r,c);
		}
	}
	return result;
  }
  else 
  {
	 throw incompatible_matrices();
  }
}

template<typename T>
TemplatedMy_matrix<T> operator*(const TemplatedMy_matrix<T>& mat1, const TemplatedMy_matrix<T>& mat2)
{
  if(mat1.number_of_columns()== mat2.number_of_rows())
  {
	int n = mat1.number_of_rows();
	int m = mat2.number_of_columns();
	TemplatedMy_matrix<T> result(n,m);
	for(int i=0; i<mat1.number_of_rows();i++)
    {
        for(int j=0;j<mat2.number_of_columns();j++)
        {
            result(i,j)=0;
            for(int k=0;k<mat2.number_of_rows(); k++)
            {
                result(i,j) += mat1(i,k)*mat2(k,j);
            }
        }
    }
	return result;
  }
  else
  {
	  throw incompatible_matrices();
   }
}
