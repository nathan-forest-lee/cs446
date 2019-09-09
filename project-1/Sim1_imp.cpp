/* -----------------------------------------------------------------------------
 FILE NAME:         Sim1_imp.cpp
 DESCRIPTION:       implementation file for sim1.cpp
 USAGE:             ./sim1
 COMPILER:          GNU g++ compiler on Linux
 NOTES:             contains function definitions

 MODIFICATION HISTORY:
 Author             Date               Version
 ---------------    ----------         --------------
 Nathan Lee         2019-09-01         1.0
 ----------------------------------------------------------------------------- */
#include "Sim1.h"

/* -----------------------------------------------------------------------------
function name: read_file
description: takes in a file name as a string and reads contents to console
----------------------------------------------------------------------------- */
void read_file(string file, vector<string> &vector)
{
  string line;    //to hold the contents of the file
  ifstream config_file;

  config_file.open(file);

  //prints any file input below(currently prints to console)
  if (config_file.is_open())
  {
    while (getline(config_file,line))
    {
      cout << line << '\n';
      vector.push_back(line);
    }
    config_file.close();
  }
  else cout << "Unable to open file";
}

/* -----------------------------------------------------------------------------
function name: write_file
description: takes file contents and writes to specified file
----------------------------------------------------------------------------- */
void write_file(string file)
{
  string line;
  ifstream config_file;
  // ofstream out_file;

  ofstream out_file("config_test.mdf", ios::app);

  // out_file.open("Test_1a.mdf");
  config_file.open(file);

  //prints any file input below(currently prints to console)
  if (config_file.is_open())
  {
    while (getline(config_file,line))
    {
      out_file << line << '\n';
    }
    config_file.close();
  }
  else cout << "Unable to open file";
  out_file.close();

}

/* -----------------------------------------------------------------------------
function name: meta_data_extract
description: finds file name for meta data file to interpret
----------------------------------------------------------------------------- */
string meta_data_extract(vector<string> &data_vector)
{
  //sentence_holder contains the entire 3rd line of config file
  //meta_file_name contains the extracted file name for the mdf file.
  //char_test is to test when we pass the : to notify that the name of mdf will begin
  //iterator is to keep track of the index of the string im in
  string sentence_holder, meta_file_name;
  char char_test;
  int iterator = 0;

  sentence_holder = data_vector[3];

  while(sentence_holder[iterator] != ':')
  {
    iterator++;
  }
  iterator = iterator + 2;

  while(sentence_holder[iterator] != '\0')
  {
    meta_file_name += sentence_holder[iterator];
    iterator++;
  }

  return meta_file_name;
}


/* -----------------------------------------------------------------------------
function name: meta_data_interpret
description: opens the mdf file and stores contents into a vector
----------------------------------------------------------------------------- */
void meta_data_interpret(string mdf_name, vector<string> &meta_data_vector)
{
//need to create file to open mdf
//need to getline string lines into vector
}

