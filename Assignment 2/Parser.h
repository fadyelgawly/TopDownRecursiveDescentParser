//
//  Parser.h
//  C-Language-Parser
//

#ifndef PARSER_H
#define PARSER_H

#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;

class Parser
{
  private:
    void initialize(string);
    void scan(string);
    void match(string);
    void error(string);
    void parse();

    void program(); // grammer rule no. 1
    
    // TODO: Add the rest of the rules and private variables you will need to use within the class.

  public:
    string output_filepath;
    void run_program(string);
};

#endif /* PARSER_H */
