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
#include <string.h>
#include <cctype>
#include <fstream>
#include <vector>
using namespace std;


/* -----------------------------------------------------------------------------
FUNCTION PROTOTYPES
----------------------------------------------------------------------------- */
void read_file(string config_file, vector<string> &vector); //reads contents of file onto console and into vector
void write_file(string file_input);   //writes contents of a file into another file
bool config_validity(vector<string> &data_vector);       //parse through and deals with error handeling
bool meta_validity(vector<string> &data_vector);           //checks extracrted meta data file from config file
void file_interpretation(string file_name, vector<string> &data_vector);
// string getKeyword(string &line);
// char getCommand(string &line);
void look_up_table(vector<string> &data_vector);
void meta_parser(string meta_file, vector<string> &meta_vector);

#include "Sim1_imp.cpp"
#endif
