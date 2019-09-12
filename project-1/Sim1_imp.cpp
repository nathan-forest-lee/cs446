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
      // cout << line << '\n';
      vector.push_back(line);
    }
    config_file.close();
  }
  else cout << "Unable to open file";
}


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

  file_name = data_vector[2];
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


/* -----------------------------------------------------------------------------
function name: meta_parser
description: takes meta contents and extracts keywords, and operations...multiple embeed function calls
----------------------------------------------------------------------------- */
void meta_parser(vector<string> &data_vector, string meta_file, vector<string> &meta_vector, ofstream &file_logger)
{
  ifstream data_file;
  string line, keyword;
  bool status;
  char meta_char;
  int duty_cycles;

  data_file.open(meta_file);
  data_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  cout << "\nMeta-Data Metrics" << endl;    //this is for logging to monitor
  file_logger << "\nMeta-Data Metrics" << endl;

  while(!data_file.eof())
  {
    data_file >> line;
    if (line.find("hard") != -1)
    {
      string prev_line = line;
      data_file >> line;
      line = prev_line + line;
    }
    status = is_line_valid(line);
    if(status == true)
    {
      meta_char = get_command(line);
      if(meta_char != 'S' && meta_char != 'A')
      {
        cout << meta_char;
        file_logger << meta_char;
      }
      keyword = get_keyword(line);
      if(keyword != "begin" && keyword != "finish")
      {
        cout << "{" << keyword << "}";
        file_logger << "{" << keyword << "}";
      }
      duty_cycles = num_of_cycles(line);
      if(duty_cycles != 0)
      {
        cout << duty_cycles << " - ";
        file_logger << duty_cycles << " - ";
      }
      
      calculations(data_vector, keyword, duty_cycles, meta_char, file_logger);
      //put calculations function right here pass it the duty_cycles and keyword and data_vector
    }
  }
}

/* -----------------------------------------------------------------------------
function name: is_line_valid
description: checks the validity of the opertion from meta data tag
----------------------------------------------------------------------------- */
bool is_line_valid(string &line)
{
  char first_char = line[0];
  // cout << first_char << endl;
  if (line.find('{') != -1)
  {
    // cout << "y" << endl;
    return true;
  }
  else
  {
    // cout << "n" << endl;
    return false;
  }
}

/* -----------------------------------------------------------------------------
function name: num_of_cycles
description: extracts the integer value of duty cycles for each meta operation
----------------------------------------------------------------------------- */
int num_of_cycles(string &line)
{
  int cycles, start;
  string temp;

    start = (line.find('}')+1);
    for (int i= start; i<line.length(); i++){
        temp += line[i];
    }
    try {
        cycles = stoi(temp);
    } catch (const std::invalid_argument& i) {
        cout << "\nArgument Not a number!\n";
        return 0;
    }
    return cycles;
}

/* -----------------------------------------------------------------------------
function name: get_command
description: acquires the first character in meta tag from meta file
----------------------------------------------------------------------------- */
char get_command(string &line)
{
  char character = line[0];
  try
  {
    if(!isalpha(character))
    {
      throw(11);
    }
    if(!isupper(character))
    {
      throw(11);
    }
  }
  catch(int i)
  {
    cout << "INVALID COMMAND " << character << endl;
    return 0;
  }
  // cout << character << endl;
  return character;
}

/* -----------------------------------------------------------------------------
function name: get_keyword
description: acquires the keyword in between braces from meta data tag
----------------------------------------------------------------------------- */
string get_keyword(string &line)
{
  string keyword;
  int first;

  first = (line.find('{') + 1);

  for (int i = first; line[i] != '}'; i++)
  {
    keyword += line[i];
  }
  // cout << keyword << endl;
  return keyword;
}

/* -----------------------------------------------------------------------------
function name: calculations
description: this is where we are going to compare the keyword with a look up table, 
              depending on the keyword we will then get the duty cycle associate with the
              keyword and then mulitply it by the staic index of the data vector that is
              forehandedly associated with the keyword
----------------------------------------------------------------------------- */
void calculations(vector<string> &data_vector, string key_word, int cycles, char letter, ofstream &file_logger)
{
  int result, temp;
  
  if (key_word == "begin")
  {
    // cout << "bhere" << endl;
    return;
  }
  if(key_word == "run")
  {
    temp = stoi(data_vector[4]);    //without stoi you will get an error
    result = cycles * temp;       //cant mult int by vector element
    cout << result << " ms" << endl;
    file_logger << result << " ms" << endl;
  }
  if(key_word == "allocate")
  {
    temp = stoi(data_vector[8]);
    result = cycles * temp;
    cout << result << " ms" << endl;
    file_logger << result << " ms" << endl;
  }
  if(key_word == "monitor")
  {
    temp = stoi(data_vector[3]);
    result = cycles * temp;
    cout << result << " ms" << endl;
    file_logger << result << " ms" << endl;

  }
  if(key_word == "harddrive")
  {
    temp = stoi(data_vector[6]);
    result = cycles * temp;
    cout << result << " ms" << endl;
    file_logger << result << " ms" << endl;
  }
  if(key_word == "mouse")
  {
    temp = stoi(data_vector[5]);
    result = cycles * temp;
    cout << result << " ms" << endl;
    file_logger << result << " ms" << endl;
  }
  if(key_word == "printer")
  {
    temp = stoi(data_vector[9]);
    result = cycles * temp;
    cout << result << " ms" << endl;
    file_logger << result << " ms" << endl;
  }
  if(key_word == "block")
  {
    temp = stoi(data_vector[8]);
    result = cycles * temp;
    cout << result << " ms" << endl;
    file_logger << result << " ms" << endl;
  }
  if(key_word == "keyboard")
  {
    temp = stoi(data_vector[7]);
    result = cycles * temp;
    cout << result << " ms" << endl;
    file_logger << result << " ms" << endl;
  }
  if (key_word == "finish")
  {
    // cout << "bhere" << endl;
    return;
  }
}

/* -----------------------------------------------------------------------------
function name: output
description: outputs all information to monitor and file
----------------------------------------------------------------------------- */
void output(vector<string> &data_vector, ofstream &file_logger)
{
  cout << "\nConfiguration File Data" << endl;
  file_logger << "Configuration File Data" << endl;
  cout << "Monitor = " << data_vector[3] << " ms/cycle" << endl;
  file_logger << "Monitor = " << data_vector[3] << " ms/cycle" << endl;
  cout << "Processor = " << data_vector[4] << " ms/cycle" << endl;
  file_logger << "Processor = " << data_vector[4] << " ms/cycle" << endl;
  cout << "Mouse = " << data_vector[5] << " ms/cycle" << endl;
  file_logger << "Mouse = " << data_vector[5] << " ms/cycle" << endl;
  cout << "Hard Drive = " << data_vector[6] << " ms/cycle" << endl;
  file_logger << "Hard Drive = " << data_vector[6] << " ms/cycle" << endl;
  cout << "Keyboard = " << data_vector[7] << " ms/cycle" << endl;
  file_logger << "Keyboard = " << data_vector[7] << " ms/cycle" << endl;
  cout << "Memory = " << data_vector[8] << " ms/cycle" << endl;
  file_logger << "Memory = " << data_vector[8] << " ms/cycle" << endl;
  cout << "Printer = " << data_vector[9] << " ms/cycle" << endl;
  file_logger << "Printer = " << data_vector[9] << " ms/cycle" << endl;
  // cout << "Logged to: " << data_vector[10] << " ms/cycle" << endl;
}


bool config_validity(string conf_file)
{
  ofstream test_file;
  test_file.open(conf_file);

  if(test_file.is_open())
  {
    return true;
  }
  else
  {
    return false;
  }
}


