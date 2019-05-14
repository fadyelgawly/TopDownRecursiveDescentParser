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
#include <fstream>
#include <sstream>
#include <iostream>

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
    
  
    void declaration_list();
    void var_declaration();
    void type_specifier();
    void compound_stmt();
    void stmt();
    void expression_stmt();
    void selection_stmt();
    void iteration_stmt();
    void expression();
    void relop();
    void additive_expression();
   void  addop();
    void term();
    void mulop();
    void factor();
    void write_stmt();
    void write_var();
    void read_stmt();
    
    
    // TODO: Add the rest of the rules and private variables you will need to use within the class.
    string next_token;
  public:
    string output_filepath;
    void run_program(string);
    
    
};

#endif /* PARSER_H */
