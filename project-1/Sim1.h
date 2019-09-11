/* -----------------------------------------------------------------------------
 FILE NAME:         sim1.h
 DESCRIPTION:       header file for sim1/project 1
 USAGE:             ./sim1
 COMPILER:          GNU g++ compiler on Linux
 NOTES:             contains function protoypes and libraries

 MODIFICATION HISTORY:
 Author             Date               Version
 ---------------    ----------         --------------
 Nathan Lee         2019-09-01         1.0
 ----------------------------------------------------------------------------- */
#ifndef SIM1_H
#define SIM1_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

/* -----------------------------------------------------------------------------
FUNCTION PROTOTYPES
----------------------------------------------------------------------------- */
void read_file(string config_file, vector<string> &vector);   //reads contents of file onto console and into vector
void write_file(string file_input);   //writes contents of a file into another file
bool config_validity(vector<string> &data_vector);       //parse through and deals with error handeling
string meta_data_extract(vector<string> &data_vector);      //parse through to find file name for meta data file


#include "Sim1_imp.cpp"
#endif
