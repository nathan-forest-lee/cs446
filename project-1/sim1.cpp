/* -----------------------------------------------------------------------------
 FILE NAME:         sim1.cpp
 DESCRIPTION:
 USAGE:             ./sim1
 COMPILER:          GNU g++ compiler on Linux
 NOTES:

 MODIFICATION HISTORY:
 Author             Date               Version
 ---------------    ----------         --------------
 Nathan Lee         2019-09-01         1.0
 ----------------------------------------------------------------------------- */
#include "Sim1.h"

 /* -----------------------------------------------------------------------------
FUNCTION:          int main()
DESCRIPTION:       program entry point
RETURNS:           int
NOTES:
------------------------------------------------------------------------------- */
int main(int argc, char *argv[])
{
  string holder, line, meta_data;  //holds name of config file, line is for file input
  vector<string> data_vector;   //hold contents of configuration file
  vector<string> meta_data_vector;    //hold contents of meta data file

  //iterates through each batch command to take on each file
  for(int i = 1; i < argc; i++)
  {
    holder = argv[i];
    read_file(holder, data_vector);
    write_file(holder);
  }

  meta_data = meta_data_extract(data_vector);
  meta_data_interpret(meta_data, meta_data_vector);
  read_file(meta_data, meta_data_vector);

  return 0;
}
