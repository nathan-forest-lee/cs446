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


/* -----------------------------------------------------------------------------
function name: look_up_table
description: takes the elements of the data-Vector and associates it with a operator keycharacter
----------------------------------------------------------------------------- */
void look_up_table(vector<string> &data_vector)
{
    for (int i = 0; i < data_vector.size(); i++)
  {
    cout << data_vector[i] << " " << i << endl;
  }
}

/* -----------------------------------------------------------------------------
function name: meta_parser
description: takes meta contents and extracts keywords, and operations...multiple embeed function calls
----------------------------------------------------------------------------- */
void meta_parser(string meta_file, vector<string> &meta_vector)
{
  ifstream data_file;
  string line, keyword;
  bool status;
  char meta_char;
  int duty_cycles;

  data_file.open(meta_file);

  data_file.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
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
      keyword = get_keyword(line);
      duty_cycles = num_of_cycles(line);
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

// /* -----------------------------------------------------------------------------
// function name: meta_validity
// description: checks if the extracted file name for the meta data file is valid
// ----------------------------------------------------------------------------- */
// string getKeyword (string &line) {
//     string keyword;
//     int start;
//     start = (line.find('{')+1);
//     for( int i = start; line[i]!= '}'; i++){
//         keyword += line[i];
//         // cout << "keyword[]:" << keyword[i-start] << endl;
//         // cout << "line[]:" << line[i] << endl;

//     }
//     cout << keyword;
//     return keyword;
// }

// char getCommand (string &line) {
//     char letter = line[0];
//     try {
//         if (!isalpha(letter)) {
//             throw (11);
//         if (!isupper(letter)) {
//             throw(11);
//             }
//         }
//     } catch (int i) {
//         cout << "\nINVALID COMMAND: " << letter << endl;
//         return 0;
//     }
//     return letter;
// }