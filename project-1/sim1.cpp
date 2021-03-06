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
  string holder, line, meta_data_file, log_file;  //holds name of config file, line is for file input
  vector<string> data_vector;   //hold contents of configuration file
  vector<string> meta_data_vector;    //hold contents of meta data file
  bool validity, test;      //use for error handling, status is fused for config file validity
  ofstream file_logger;   //this will be the file that is created and output will go to

  file_logger.open("logfile_1.lgf");

  //iterates through each batch command to take on each file
  for(int i = 1; i < argc; i++)
  {
    holder = argv[i];
    file_interpretation(holder, data_vector);
  }

  //checks validity of the meta data file name extrtacted from the configuration file
  validity = meta_validity(data_vector);
  if(validity == false)
  {
    cout << "invalid meta data file." << endl;
    return 0;
  }
  else
  {
    output(data_vector, file_logger);
    meta_data_file = data_vector[2];
    read_file(meta_data_file, meta_data_vector);
  }


 //time to do the meat of the program, calculations
  meta_parser(data_vector, meta_data_file, meta_data_vector, file_logger);

  file_logger.close();
  
  return 0;
}
