//============================================================================
// Name        : option.h
// Author      : Teresa Leyk
// Date        :
// Copyright   : 
// Description : Command line processing for the sort program
//============================================================================

#ifndef OPTION_H_
#define OPTION_H_

#include <stdexcept>

class Option {
public:
  // user defined exception class
  struct InvalidArgument:public std::invalid_argument {
    InvalidArgument():std::invalid_argument(
       "Usage: ./sort [-a ALGORITHM] [-f INPUTFILE] [-o OUTPUTFILE] "
       "[-h] [-d] [-t] [-T] [-c] [-r]\n"
       "Try './sort -h' for more information.") {}
  };
  
private:
  /// variables representing command line options provided by the user
  char        alg;         /// Algorithm selected
  const char* input_file;  /// Name of the input file if provided
  const char* output_file; /// Name of the output file if provided
  bool        show_help;   /// Whether to show help or not
  bool        show_input;  /// Whether to display unsorted input sequence
  bool        show_time;   /// Whether to display running time
  bool        show_time_chrono; //display running time using C++ chrono class
  bool        show_num_cmps;/// Whether to display number of element comparisons
  bool        show_output;  /// Whether to display sorted input sequence
  int         num_runs; //the number of runs

public:  
  Option() : alg(0), input_file(nullptr), output_file(nullptr),
	     show_help(false), show_input(false), show_time(false),
	     show_time_chrono(false), show_num_cmps(false),
	     show_output(false), num_runs(1) {}
  
  /* initialize options according to command line */
  void init(int argc, char** argv);
  
  /* accessor functions */
  char getAlg() const { return alg; } 
  const char* getInputFile() const { return input_file; }
  const char* getOutputFile() const { return output_file; }
  
  /* query functions */
  bool showHelp() const { return show_help; }
  bool showInput() const { return show_input; }
  bool showTime() const { return show_time; }
  bool showTimeChrono() const { return show_time_chrono; }
  bool showNumCmps() const { return show_num_cmps; }
  bool showOutput() const { return show_output; }
  int  numberOfRuns() const { return num_runs; }
  
  /* print help message */
  void printUsage() const;
};

#endif // OPTION_H_
