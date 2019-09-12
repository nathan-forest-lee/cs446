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
bool config_validity(string conf_file);       //parse through and deals with error handeling
void file_interpretation(string file_name, vector<string> &data_vector);
string get_keyword(string &line);
char get_command(string &line);
void meta_parser(vector<string> &data_vector, string meta_file, vector<string> &meta_vector, ofstream &file_logger);
bool is_line_valid(string &line);
int num_of_cycles(string &line);
void calculations(vector<string> &data_vector, string key_word, int cycles, char letter, ofstream &file_logger);
void output(vector<string> &data_vector, ofstream &file_logger);

#include "Sim1_imp.cpp"
#endif
