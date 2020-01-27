/* My_matrix.h
Header file for the class My_matrix
Adrian Gamez-Rodriguez	126009409
*/

#include <iostream>
#include <exception>

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

class My_matrix {
	
  //member variables
  int n, m;
  int **ptr;
  void allocate_memory();  // optional
  
public:	
  //member functions
  My_matrix();  // default constructor
  My_matrix(int n1, int m1); // parameter constructor
  ~My_matrix(); // destructor
  My_matrix(const My_matrix& mat); // copy constructor
  My_matrix(My_matrix&& mat);  // move constructor (optional)
  My_matrix& operator=(const My_matrix& mat); //copy assignment operator
  My_matrix& operator=(My_matrix&& mat); // move assignment operator (optional)
  int number_of_rows() const; 
  int number_of_columns() const;
  void set_rows(int n1){n=n1;}//sets rows
  void set_columns(int m1){m =m1;}//sets columns
  void call_allocate_memory(){ allocate_memory();};//calls allocate memory 
  int* operator()(int i) const; // overloaded to access to ith row
  int& operator()(int i, int j); // overloaded to access (i,j) element
  int operator()(int i, int j) const; // overloaded to access (i,j) element
  int elem(int i, int j) const; // overloaded to access (i,j) element
  int& elem(int i, int j); // overloaded to access (i,j) element
};

// see the handout for the description of these operators
ostream& operator<<(ostream& out, const My_matrix& mat);
istream& operator>>(istream& in, My_matrix& mat);
My_matrix operator+(const My_matrix& mat1, const My_matrix& mat2);
My_matrix operator*(const My_matrix& mat1, const My_matrix& mat2);

