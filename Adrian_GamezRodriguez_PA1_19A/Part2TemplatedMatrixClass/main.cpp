// main.cpp
// Tests all functionality of the class TemplatedMy_matrix class.
#include <iostream>
#include <fstream>
#include "TemplatedMy_matrix.h"
//There are multiple try blocks for purposeful exception throwing to 
//demonstrate it does work.
int main()
{
	//  Phase 2 :Test 1
    // * Create an object of type My_matrix, called m1, using constructor
    // * Initialize m1 in main (by assigning numbers to matrix elements)
    // * Display m1 on the screen using the operator <<
	cout<<"Phase 2: Test 1 with different data types\n";
	cout<<endl;
	TemplatedMy_matrix<double> m1_doubles(2,2);//Created object of My_matrix called m1;
	m1_doubles(0,0)=15.4;//Initializing all possible elements
	m1_doubles(0,1)=8.9;
	m1_doubles(1,0)=3.4;
	m1_doubles(1,1)=12.4;
	cout<<"m1 with doubles:\n";
	cout<<m1_doubles;
	cout<<endl;
	TemplatedMy_matrix<float> m1_float(2,2);//Created object of My_matrix called m1;
	m1_float(0,0)=4563.116;//Initializing all possible elements
	m1_float(0,1)=7315.623;
	m1_float(1,0)=654.964;
	m1_float(1,1)=3.945;
	cout<<"m1 with floating point :\n";
	cout<<m1_float;
	cout<<endl;
	TemplatedMy_matrix<char> m1_char(2,2);//Created object of My_matrix called m1;
	m1_char(0,0)='a';//Initializing all possible elements
	m1_char(0,1)='d';
	m1_char(1,0)='r';
	m1_char(1,1)='i';
	cout<<"m1 with characters:(just to demonstrate it works for all data types)\n";
	cout<<m1_char;
	cout<<"--------------------------------------------------------------\n";
	// Test 2
    // * Create an object of type My_matrix, called m2, using (default)
    //   constructor
    // * Open an input file containing a matrix (row by row)
    // * Initialize m2 by reading from the input file using
    //   the operator >>
    // * Open an output file (can be empty)
    // * Write m2 to the output file using the operator <<
	cout<<"Phase 2: Test 2\n";
	cout<<"Look inside the matrix.txt file and output file to check correctness\n";
	TemplatedMy_matrix<double> m2;//declaring matrix of type double to read in from file
  try{
	const char * input_file= "doubletypematrix.txt";
	ifstream is(input_file);//opened input file 
	if(!is)
	{
		cout<<"Unable to open file: "<<input_file<<endl;
		return 1;
	}
	ofstream outf("output2.txt");//opened output file
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
	cout<<"Phase 2: Test 3\n";
	TemplatedMy_matrix<double> m3_doubles(m1_doubles);
	TemplatedMy_matrix<float> m3_float(m1_float);
	TemplatedMy_matrix<char> m3_char(m1_char);
	TemplatedMy_matrix<double> m4_doubles=m1_doubles;
	TemplatedMy_matrix<float> m4_float=m1_float;
	TemplatedMy_matrix<char> m4_char=m1_char;
	cout<<"Using copy constructor:\n";
	cout<<"Matrix m3 (doubles):\n";
	cout<<m3_doubles;
	cout<<"Matrix m3 (floating point):\n";
	cout<<m3_float;
	cout<<"Matrix m3 (characters):\n";
	cout<<m3_char;
	cout<<endl;
	cout<<"Using copy assignment:\n";
	cout<<"Matrix m4(doubles):\n";
	cout<<m4_doubles;
	cout<<"Matrix m4(floating point):\n";
	cout<<m4_float;
	cout<<"Matrix m4(characters):\n";
	cout<<m4_char;
	cout<<"------------------------------------------------------------\n";
	cout<<"Here are some Matrices to test Addition and Multiplication (using double type):\n";
	cout<<"Feel free to change them in the main.cpp file.\n";
	//Created multiple matrices for testing addition and multiplication
	TemplatedMy_matrix<double> m5(3,3);
	m5(0,0)=5.41;
	m5(0,1)=6.65;
	m5(0,2)=7.9;
	m5(1,0)=15.1;
	m5(1,1)=25.9;
	m5(1,2)=64.47;
	m5(2,0)=8.9;
	m5(2,1)=40.1;
	m5(2,2)=14.5;
	TemplatedMy_matrix<double> m6(3,1);
	m6(0,0)=4.5;
	m6(1,0)=6.12;
	m6(2,0)=7.48;
	TemplatedMy_matrix<double> m7(3,1);
	m7(0,0)=78.41;
	m7(1,0)=45.5;
	m7(2,0)=91.4;
	TemplatedMy_matrix<double> m8(2,2);
	m8(0,0)=7.4;
	m8(0,1)=4.6;
	m8(1,0)=0.7;
	m8(1,1)=4.12;
	TemplatedMy_matrix<double> m9(2,2);
	m9(0,0)=3.85;
	m9(0,1)=7.67;
	m9(1,0)=1.7;
	m9(1,1)=74.5;
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
	cout<<"Phase 2: Test 4 (multiplication) using double matrices\n";
	cout<<"m5*m6:\n";
	TemplatedMy_matrix<double> m10=m5*m6;
	cout<<m10;
	cout<<"Number of rows: "<<m10.number_of_rows()<<" ";;
	cout<<"Number of columns: "<<m10.number_of_columns();
	cout<<endl;
	cout<<endl;
	cout<<"m8*m9:\n";
	TemplatedMy_matrix<double> m11=m8*m9;
	cout<<m11;
	cout<<"Number of rows: " <<m11.number_of_rows()<<" ";
	cout<<"Number of columns: "<<m11.number_of_columns();
	cout<<endl;
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
	cout<<"Phase 2: Test 5 (addition, using double data type)\n";
	cout<<"m6+m7:\n";
	TemplatedMy_matrix<double> m12= m6+m7;
	cout<<m12;
	cout<<"Number of rows: "<<m12.number_of_rows()<<" ";
	cout<<"Number of columns: "<<m12.number_of_columns();
	cout<<endl;
	cout<<endl;
	cout<<"m8+m9:\n";
	TemplatedMy_matrix<double> m13= m8+m9;
	cout<<m13;
	cout<<"Number of rows: "<<m13.number_of_rows()<<" ";
	cout<<"Number of columns: "<<m13.number_of_columns();
	cout<<endl;
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
	cout<<"End of Part 2\n";
}