// main.cpp
// Tests all functionality of the class My_matrix class.

#include <iostream>
#include <fstream>
#include "My_matrix.h"
//There are multiple try blocks for purposeful exception throwing to 
//demonstrate it does work.
int main(){
    //  Phase 1 :Test 1
    // * Create an object of type My_matrix, called m1, using constructor
    // * Initialize m1 in main (by assigning numbers to matrix elements)
    // * Display m1 on the screen using the operator <<
	cout<<"Phase 1: Test 1\n";
	My_matrix m1(2,2);//Created object of My_matrix called m1;
	m1(0,0)=5;//Initializing all possible elements
	m1(0,1)=13;
	m1(1,0)=24;
	m1(1,1)=65;
	cout<<"m1:\n";
	cout<<m1;//Displaying matrix to screen
	cout<<endl;
	cout<<"--------------------------------------------------------------\n";
	// Test 2
    // * Create an object of type My_matrix, called m2, using (default)
    //   constructor
    // * Open an input file containing a matrix (row by row)
    // * Initialize m2 by reading from the input file using
    //   the operator >>
    // * Open an output file (can be empty)
    // * Write m2 to the output file using the operator <<
	cout<<"Phase 1: Test 2\n";
	cout<<"Look inside the matrix.txt file and output file to check correctness\n";
	My_matrix m2;
  try{
	const char * input_file= "matrix.txt";
	ifstream is(input_file);//opened input file 
	if(!is)
	{
		cout<<"Unable to open file: "<<input_file<<endl;
		return 1;
	}
	ofstream outf("output1.txt");//opened output file
	if(!outf)
	{
		cout<<"Unable to open file: "<<outf<<endl;
		return 1;
	}
	is>>m2;//read in matrix 
	cout<<"m2:\n";
	cout<<m2;//print to screen
	outf<<m2;//print to output file
	}
	catch(exception &error){
    cerr << "Error: " << error.what() << endl;
  }
	cout<<"-------------------------------------------------------------\n";
    // Test 3
    // * Use the copy constructor to make a copy of m1 called m3
    // * Apply the copy assignment to m1 called m4
    // * Display m3 and m4 on the screen using the operator <<
	cout<<"Phase 1: Test 3\n";
	My_matrix m3(m1);
	My_matrix m4 = m1;
	cout<<"Matrix m3:\n";
	cout<<m3;
	cout<<"Matrix m4:\n";
	cout<<m4;
	cout<<"------------------------------------------------------------\n";
	cout<<"Here are some Matrices to test Addition and Multiplication\n";
	cout<<"Feel free to change them in the main.cpp file.\n";
	//Created multiple matrices for testing addition and multiplication
	My_matrix m5(3,3);
	m5(0,0)=5;
	m5(0,1)=1;
	m5(0,2)=2;
	m5(1,0)=67;
	m5(1,1)=34;
	m5(1,2)=9;
	m5(2,0)=15;
	m5(2,1)=3;
	m5(2,2)=7;
	My_matrix m6(3,1);
	m6(0,0)=3;
	m6(1,0)=5;
	m6(2,0)=30;
	My_matrix m7(3,1);
	m7(0,0)=2;
	m7(1,0)=6;
	m7(2,0)=8;
	My_matrix m8(2,2);
	m8(0,0)=4;
	m8(0,1)=1;
	m8(1,0)=2;
	m8(1,1)=14;
	My_matrix m9(2,2);
	m9(0,0)=11;
	m9(0,1)=23;
	m9(1,0)=12;
	m9(1,1)=35;
	cout<<"Matrix m5:\n";
	cout<<m5;
	cout<<"Matrix m6:\n";
	cout<<m6;
	cout<<"Matrix m7:\n";
	cout<<m7;
	cout<<"Matrix m8:\n";
	cout<<m8;
	cout<<"Matrix m9:\n";
	cout<<m9;
	cout<<"--------------------------------------------------------------\n";
	// Test 4
    // * Test the matrix multiplication operator (operator*)
    // * Apply the multiplication operator to valid and invalid cases
    // * Display the resulting matrix and its number of rows and columns
	cout<<"Phase 1: Test 4 (multiplication)\n";
	cout<<"m5*m6:\n";
	My_matrix m10=m5*m6;
	cout<<m10;
	cout<<"Number of rows: "<<m10.number_of_rows()<<" ";
	cout<<"Number of columns: "<<m10.number_of_columns();
	cout<<endl;
	cout<<"m8*m9:\n";
	My_matrix m11=m8*m9;
	cout<<m11;
	cout<<"Number of rows: " <<m11.number_of_rows()<<" ";
	cout<<"Number of columns: "<<m11.number_of_columns();
	cout<<endl;
	try
	{
	//This is to test multiplication functionality with incompatible matrices
	//its supposed to throw an exception
	cout<< "This is testing the multiplication functionality, this should throw exception\n";
    cout<<"m5*m8:\n";
	cout<<m5*m8;//should throw exception becuase m5 is a (3x3) matrix and m8 is a (2x2) matrix
	}
	catch(exception &error){cerr<<"Error: "<<error.what()<<endl;}
	cout<<"-----------------------------------------------\n";
	// Test 5
    // * Test the matrix addition operator (operator+)
    // * Apply the multiplication operator to valid and invalid cases
    // * Display the resulting matrix and its number of rows and columns
	cout<<"Phase 1: Test 5 (addition)\n";
	cout<<"m6+m7:\n";
	My_matrix m12= m6+m7;
	cout<<m12;
	cout<<"Number of rows: "<<m12.number_of_rows()<<" ";
	cout<<"Number of columns: "<<m12.number_of_columns();
	cout<<endl;
	cout<<"m8+m9:\n";
	My_matrix m13= m8+m9;
	cout<<m13;
	cout<<"Number of rows: "<<m13.number_of_rows()<<" ";
	cout<<"Number of columns: "<<m13.number_of_columns();
	cout<<endl;
	try
	{
	//This try block is to test addition functionality with incompatible matrices
	//This is supposed to throw an exception 
	cout<< "This is testing the addition functionality, this should throw exception\n";
    cout<<"m5+m8:\n";
	cout<<m5+m8;
	} 
	catch(exception &error){cerr<<"Error: "<<error.what()<<endl;}
	cout<<"End of Part 1\n";
}
