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
  string holder, line, meta_data, log_file;  //holds name of config file, line is for file input
  vector<string> data_vector;   //hold contents of configuration file
  vector<string> meta_data_vector;    //hold contents of meta data file
  bool validity;      //use for error handling

  //iterates through each batch command to take on each file
  for(int i = 1; i < argc; i++)
  {
    holder = argv[i];
    file_interpretation(holder, data_vector);
    // read_file(holder, data_vector);
    // write_file(holder);
  }

  //checks validity of the meta data file name extrtacted from the configuration file
  validity = meta_validity(data_vector);
  if(validity == false)
  {
    cout << "invalid meta data file." << endl;
    return 0;
  }

  log_file = data_vector[12];

  // for (int i = 0; i < data_vector.size(); i++)
  // {
  //   cout << data_vector[i] << " " << i << endl;
  // }

  return 0;
}
