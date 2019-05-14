//
//  Parser.c
//  C-Language-Parser
//

#include "Parser.h"

void Parser::run_program(string file_path)
{
    initialize(file_path);
    
    // TODO: Add the calls for your starting functions
}

void Parser::initialize(string file_path)
{
    // TODO: Read input testcase file from file.
    
}

void Parser::scan(string lookahead_token)
{
    // TODO: Get the lookahead token.
}

void Parser::match(string expectedToken)
{
    // TODO: Match lookahead token with expected token.
}

void Parser::error(string expectedToken)
{
    // TODO: Write error message to output file.
    // Don't forget to use 'output_filepath' variable to get the path.
}

void Parser::parse()
{
    program();
    printf("Parsing Successful\n");
    ofstream myfile(output_filepath);
    if (myfile.is_open())
        myfile << "Parsing Successful" << endl;
    else
        printf("Unable to open file: File doesn't exists.\n");
}

void Parser::program() // program = declaration_list
{
    // TODO: Call declaration_list() which is grammer rule no. 2
}

