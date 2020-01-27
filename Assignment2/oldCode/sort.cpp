//=========================================================================
// Name        : sort.cpp
// Author      : Teresa Leyk
// Date        :
// Copyright   : 
// Description : Read an integer sequence and display the sorted sequence
/*
 *     Usage: ./sort [-a ALGORITHM] [-f INPUTFILE] [-o OUTPUTFILE] [-h] 
 *                   [-d] [-p] [-t] [-T] [-c] [-r]
 *     Example: ./sort -a S -f input.txt -o output.txt -t -c -d
 *              ./sort -h
 *     For "./sort -h" do not add other options!
 *     Options: 
 *       -a ALGORITHM    Use ALGORITHM to sort. 
 *                       ALGORITHM is a single character representing 
 *                       an algorithm: 
 *                         S   (selection sort) 
 *                         B   (bubble sort) 
 *                         I   (insertion sort) 
 *                         H   (shell sort)
 *                         R   (radix sort) 
 *       -f INPUTFILE    Obtain integers from INPUTFILE instead of STDIN 
 *       -o OUTPUTFILE   Place output message into OUTPUTFILE instead of STDOUT 
 *       -h              Display this help and exit 
 *       -d              Display input: unsorted integer sequence
 *       -p              Display output: sorted integer sequence 
 *       -t              Display running time of the chosen algorithm 
 *                       in milliseconds 
 *       -T              Display running time of the chosen algorithm
 *                       in milliseconds using the C++ chrono class
 *       -c              Display number of element comparisons 
 *                       (excluding radix sort)
 *       -r              Provide the number of repeated runs
 *  Hint: use -r 10 (or larger) for input data of small size (<= 100)
*/
//=========================================================================

#include <iostream>
#include <iterator>
#include <ctime>
#include <chrono>
#include <cstdio>
#include <limits>
#include <iomanip>

#include "option.h"
#include "sort.h"

using namespace std;
using namespace std::chrono;

/* read input sequence from STDIN */
int readInput(int A[], int& size) {
  /* read integers to sort */
  for (int i = 0; i < size; i++)
    if (!(cin >> A[i])) {
      cerr << "sort: input data error" << endl;
      return 1; //exit abnormally
    }  
   
  return 0; //exit normally
}

/* display elements of array A seperated by new lines */
void printArray(const int A[], int size) {
  // call the standard function "copy" to display the array
  copy(A, A+size, ostream_iterator<int>(cout,"\n"));
  cout << endl;  
}

// returns true if sorted as increasing sequence
// returns false otherwise
bool Sort::testIfSorted(int A[], int size)
{
  for (int i = 1; i < size; ++i)
    if (A[i-1] > A[i]) return false;
  return true;
}

// create an sorting object
Sort* getSortingAlg(Option& op, bool& radixsortQ)
{
  Sort* s = nullptr;
  switch(op.getAlg()) 
    {
    case 'S':
      s=new SelectionSort();
      break;
    case 'I':
      s=new InsertionSort();
      break;
    case 'B':
      s=new BubbleSort();
      break;
    case 'H':
      s=new ShellSort();
      break;
    case 'R':
      s=new RadixSort();
      radixsortQ = true;
      break;
    }
  return s;
}

double getAvgSortTime(Option& op, Sort* s, int* A, int size)
{
  int sortTime = 0;
  int numRuns = op.numberOfRuns();
  int* orig = new int[size];

  for (int i = 0; i<size; i++){
    orig[i] = A[i];
  }
  for (int i = 0; i < numRuns; i++) {
    for (int j = 0; j<size; j++){
      A[j] = orig[j];
    }
    
    if (op.showTimeChrono()) {
      auto start = high_resolution_clock::now();
       
      /* call sorting function to sort */
      s->sort(A, size);
       
      auto finish = high_resolution_clock::now();
      auto duration = duration_cast<nanoseconds>(finish - start);
      sortTime += duration.count();
    } else {
      clock_t start = clock();
       
      /* call sorting function to sort */
      s->sort(A, size);
       
      clock_t finish = clock();
      sortTime += (finish - start);
    }
  }
  return double(sortTime)/numRuns;
}

/* show running time of the algorithm to sort input data */
void showRunTime(Option& op, Sort* s, double avgSortTime)
{
  cout << s->sortName() << endl;
  cout << fixed << setprecision(4);
  if (op.showTimeChrono())
    cout << "Running time: "
	 << avgSortTime*1e-6
	 << " ms" << endl;
  else if (op.showTime())
    cout << "Running time: "
	 << avgSortTime*1000/CLOCKS_PER_SEC
	 << " ms" << endl;
  cout << defaultfloat << setprecision(6);
}

/* show number of comparisons in the algorithm */
void showNumComp(Option& op, double avgNumCmps, bool radixsortQ)
{
  if (op.showNumCmps()) {
    if (radixsortQ) {
      cout << "No comparisons for radix sort"
	   << endl;
    } else {
      cout << "# Comparisons: " << avgNumCmps << endl;
    }
  }
}

/////////////////////////////////////////////////////////////////

int main(int argc, char** argv)
{
  Option op;
  bool radixsortQ = false;
   
  /* initialize program options */
  try {
    op.init(argc, argv);
  } catch (Option::InvalidArgument& ex) {
    cerr << ex.what() << endl;
    return 1;
  }
   
  /* show help message and exit */
  if (op.showHelp()) {
    op.printUsage();
    const unsigned int max_int = std::numeric_limits<int>::max();
    cout << "NOTE: The Radix Sort sorts " << 0
	 << " to " << (max_int+1)/2-1 << endl;
    return 0; //exit normally
  }

  // input/output files
  const char *input_file, *output_file;
   
  /* If provided input file, reopen standard input onto that file
     so that we only need to deal with standard input. */
  if ((input_file=op.getInputFile()) &&
      freopen(input_file, "r", stdin) == 0) {
    cerr << "sort: " << input_file << ": no such file" << endl;
    return 1;
  }
   
  /* If provided output file, reopen standard output onto that file
     so that we only need to deal with standard output. */
  if ((output_file=op.getOutputFile()) &&
      freopen(output_file, "w", stdout) == 0) {
    cerr << "sort: " << output_file << ": No such file" << endl;
    return 1; //exit abnormally
  }  
  
  /* read number of integers */
  int size; //number of integers
  if (input_file == nullptr) {
    cout << "Enter input data:\n";
  }
  if (!(cin >> size)) return 1; //exit abnormally
    
  /* read input integers */
  int* A=new int[size]; //stores integers  
  if (readInput(A,size)) 
    return 1; //exit abnormally

  /* show unsorted input sequence */
  if (op.showInput()) {
    cout << "Unsorted sequence:" << endl;
    printArray(A, size); 
  }
  
  Sort* s = getSortingAlg(op, radixsortQ); //sorting object
  
  double avgSortTime = getAvgSortTime(op, s, A, size);

  if (!s->testIfSorted(A, size)) {
    cerr << "Error: The output sequence IS NOT sorted!\n"
	 << "Fix this part of the code\n"
	 << endl;
  } else {
    /* output sorted sequence */
    if (op.showOutput()) {
      cout << "Sorted sequence:" << endl;
      printArray(A,size); 
    }
    
    showRunTime(op, s, avgSortTime);
    double avgNumCmps = double(s->getNumCmps())/op.numberOfRuns();
    showNumComp(op, avgNumCmps, radixsortQ);
  }
  
  // it may be useful for Windows
  // char ch;
  // cin >> ch;
  return 0;
}
