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
  Operation_struct *config_struct = new Operation_struct;    //struct to hold commands taken from the config file

  if(argc == 1)
  {
    cout << "too few commands" << endl;
    return 0;
  }
  //iterates through each batch command to take on each file
  for(int i = 1; i < argc; i++)
  {
    holder = argv[i];
    file_interpretation(holder, data_vector);
    // read_file(holder, data_vector);
    // write_file(holder);
  }
  // cout << "start" << endl;
  // // cout << data_vector[0] << endl;
  // // cout << data_vector[1] << endl;
  // cout << data_vector[2] << endl;
  // config_struct->version_num = stoi(data_vector[2]);
  // cout << data_vector[3] << endl;
  // cout << data_vector[4] << endl;
  // cout << data_vector[5] << endl;
  // cout << data_vector[6] << endl;
  // cout << data_vector[7] << endl;
  // cout << data_vector[8] << endl;
  // cout << data_vector[9] << endl;
  // cout << data_vector[10] << endl;
  // cout << data_vector[11] << endl;
  // cout << data_vector[12] << endl;
  // // cout << data_vector[13] << endl;
  // cout << "end" << endl;

  fill_struct(config_struct, data_vector);
  cout << config_struct->version_num << endl;
  cout << config_struct->projector << endl;

  // meta_data = meta_data_extract(data_vector);
  // meta_data_interpret(meta_data, meta_data_vector);
  // read_file(meta_data, meta_data_vector);

  /*------------------------------------------------------
  structure fill from vector
  ------------------------------------------------------*/
  // fill_struct(config_struct, data_vector);

  return 0;
}
