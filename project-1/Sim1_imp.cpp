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
void read_file(string file)
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

  ofstream out_file("Test_1a.mdf", ios::app);

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
