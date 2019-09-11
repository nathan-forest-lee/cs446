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
// void write_file(string file)
// {
//   string line;
//   // ifstream log;
//   // ofstream out_file;

//   ofstream out_file("config_test.mdf", ios::app);

//   // out_file.open("Test_1a.mdf");
//   config_file.open(file);

//   //prints any file input below(currently prints to console)
//   if (config_file.is_open())
//   {
//     while (getline(config_file,line))
//     {
//       out_file << line << '\n';
//     }
//     config_file.close();
//   }
//   else cout << "Unable to open file";
//   out_file.close();

// }



/* -----------------------------------------------------------------------------
function name: file_interpretation
description: takes contents of config file and fills vector with proper data
----------------------------------------------------------------------------- */
void file_interpretation(string file_name, vector<string> &data_vector)
{
  ifstream config_file;
  string line, info, newline;
  bool copy = false;
  int count = 0;

  config_file.open(file_name);

      while (config_file)
     {
        getline(config_file, line);
        for(int i = 0; i < line.length(); i++) 
        {
            if (line[i] == ':') {
                copy = true;
            }
            if (copy == true) {
                if (line[i]!= ':' && line[i] != ' ') {
                    newline += line[i];
                }
            }
        }
        
        copy = false;
        //write the data to the vector
        data_vector.push_back(newline);
        // cout << newline << endl;
        newline.clear();
    }
}


/* -----------------------------------------------------------------------------
function name: meta_validity
description: checks if the extracted file name for the meta data file is valid
----------------------------------------------------------------------------- */
bool meta_validity(vector<string> &data_vector)
{
  string file_name;   //hold the name of the file
  ifstream meta_file;   //ifstream that will open the meta data file
  bool status;

  file_name = data_vector[3];
  meta_file.open(file_name);

  if(meta_file.is_open())
  {
    status = true;
    meta_file.close();
    return status;
  }
  else
  {
    return status;
  }
}
