/* 
Implementation of the clas My_matrix
*/

#include "My_matrix.h"
#include <stdexcept>
#include <vector>

My_matrix::My_matrix()//default constructor
{
  n=0;
  m=0;
  ptr=nullptr;
}

void My_matrix::allocate_memory()//member variables
{
  ptr = new int*[n];
  for(int r=0; r<n; r++)
  {
	ptr[r] = new int[m];
  }
}

My_matrix::My_matrix(int n1, int m1) //parameter constructor
{
	if(n1<0||m1<0)
	{
		throw invalid_input();
	}
	n=n1;
	m=m1;
	this->allocate_memory();
}

My_matrix::My_matrix(const My_matrix& mat)//copy constructor
{
  n=mat.n;
  m=mat.m;
  if(mat.ptr)
  {
  ptr = new int*[n];
  for(int i=0;i<n;i++)
  {
	  ptr[i]=new int[m];
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

My_matrix::My_matrix(My_matrix&& mat)// move constructor
{
  n=mat.n;
  m=mat.m;
  ptr= mat.ptr;
  mat.n=0;
  mat.m=0;
  mat.ptr=nullptr;
}

My_matrix::~My_matrix()//destructor
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

My_matrix& My_matrix::operator=(const My_matrix& mat)//copy assignment operator
{
  int** q = new int*[mat.n];
   for(int r=0; r<mat.n; r++)
  {
	ptr[r] = new int[mat.m];
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

My_matrix& My_matrix::operator=(My_matrix&& mat)// move assignment operator 
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

int My_matrix::number_of_rows() const
{
  return n;
}

int My_matrix::number_of_columns() const
{
  return m;
}

int* My_matrix::operator()(int i) const //overloaded to access the ith row
{
	return ptr[i];
}

int& My_matrix::operator()(int i, int j) //overloaded to access (i,j) element
{
	return ptr[i][j];
}

int My_matrix::operator()(int i, int j)const //overloaded to access (i,j) element
{
 return ptr[i][j];
}

int My_matrix::elem(int i, int j) const
{
  if (i < 0 || i >= n) throw out_of_range("Out of range");
  if (j < 0 || j >= m) throw out_of_range("Out of range");
   else 
	  return ptr[i][j];
}

int& My_matrix::elem(int i, int j)
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

ostream& operator<<(ostream& out, const My_matrix& mat)
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

istream& operator>>(istream& in, My_matrix& mat)
{
	int n,m,val;
	vector<int>	 elem;
	in>>n;//read in rows
	in>>m;//read in columns
	while(in >>val)
	{
		elem.push_back(val);//use vector to store all ints after n and m
	}
	if(elem.size()==n*m)//if the vector has same ammount of elements as n*m then its good
	{
	in.clear();//clear end of file flag
	in.seekg(0,ios::beg);//go back to the beginning
	in.ignore(1000,'\n');//ignore first line 
	My_matrix& new_mat = const_cast<My_matrix&>(mat);//casted away constness
	new_mat.set_rows(n);
	new_mat.set_columns(m);
	new_mat.call_allocate_memory();//helper function
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

My_matrix operator+(const My_matrix& mat1, const My_matrix& mat2)
{
  if(mat1.number_of_columns() == mat2.number_of_columns() && mat1.number_of_rows() == mat2.number_of_rows())
  {
	  int n=mat1.number_of_rows();
	  int m=mat1.number_of_columns();
	My_matrix result(n,m);
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

My_matrix operator*(const My_matrix& mat1, const My_matrix& mat2)
{
  if(mat1.number_of_columns()== mat2.number_of_rows())
  {
	  int n = mat1.number_of_rows();
	  int m = mat2.number_of_columns();
	My_matrix result(n,m);
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