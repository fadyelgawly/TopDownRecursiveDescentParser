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
    //program        = program ID; declaration-list compound-stmt
    match("program");
    match("ID");
    match(";");
    declaration_list();
    compound_stmt();
}

void Parser::type_specifier(){
    // int | float
    if(next_token.substr(0, 3) == "int")
        match("int");
    else if (next_token.substr(0, 5) == "float")
        match("float");
}
void Parser::relop(){
    // <= | < | > | >= | == | !=
    if(next_token.substr(0, 2) == "<=")
        match("<=");
    else if (next_token.substr(0, 1) == "<")
        match("<");
    else if (next_token.substr(0, 1) == ">")
        match(">");
    else if (next_token.substr(0, 2) == ">=")
        match(">=");
    else if (next_token.substr(0, 2) == "==")
        match("==");
    else if (next_token.substr(0, 2) == "!=")
        match("!=");
    
}
void Parser::addop(){
    // addop        = + | -
    if (next_token.substr(0, 1) == "+")
        match("+");
    else if (next_token.substr(0, 1) == "-")
        match("-");
}
void Parser::mulop(){
    // mulop        = * | /
    if (next_token.substr(0, 1) == "*")
    match("*");
    else if (next_token.substr(0, 1) == "/")
    match("/");
}

void Parser::factor(){
    //factor        = ( expression ) | ID | FLOAT | INT
    if (next_token.substr(0, 1) == "("){
        match("(");
        expression();
        match(")");
    }
    else if (next_token.substr(0, 2) == "ID")
        match("ID");
    else if (next_token.substr(0, 5) == "FLOAT")
        match("FLOAT");
    else if (next_token.substr(0, 3) == "INT")
    match("INT");

}

void Parser::write_var(){
    //write-var    = expression | STRING
    if (next_token.substr(0, 6) == "STRING")
        match("STRING");
    else
        expression();
}
void Parser::write_stmt(){
    //write-stmt    = write write-var {, write-var};
    match("write");
    write_var();
    while(next_token.substr(0, 1) == ","){
        match(",");
        write_var();
    }
    match(";");
}

void Parser::read_stmt(){
    //read-stmt    = read ID {, ID};
    match("read");
    match("ID");
    while(next_token.substr(0, 1) == ","){
        match(",");
        match("ID");
    }
    match(";");
}

void Parser::term(){
    //term        = factor { mulop factor }
    factor();
    while(next_token.substr(0, 1) == "*" || next_token.substr(0, 1) == "/"){
        mulop();
        factor();
    }
}

void Parser::additive_expression(){
    //additive-expression = term { addop term }
    term();
    while(next_token.substr(0, 1) == "+" || next_token.substr(0, 1) == "-"){
        addop();
        term();
    }
}
void Parser::expression(){
    //expression = additive-expression [ relop additive-expression ]
        additive_expression();
        //relop = <= | < | > | >= | == | !=
        if(next_token.substr(0,2) == "<=" ||
           next_token.substr(0,1) == "<" ||
           next_token.substr(0,1) == ">" ||
           next_token.substr(0,2) == ">="||
           next_token.substr(0,2) == "<="||
           next_token.substr(0,2) == "=="||
           next_token.substr(0,2) == "!="){
            relop();
            additive_expression();
        }
}
void Parser::iteration_stmt(){
    //iteration-stmt = while ( expression ) stmt
    if(next_token.substr(0,5) == "while"){
        match("while");
        match("(");
        expression();
        match(")");
        stmt();
    }
}
void Parser::selection_stmt(){
    //selection-stmt = if ( expression ) stmt [ else stmt ]
    match("if");
    match("(");
    expression();
    match(")");
    stmt();
    if(next_token.substr(0,4) == "else"){
        match("else");
        stmt();
    }
    
}

void Parser::expression_stmt(){
    //expression-stmt= let ID = expression
    match("let");
    match("ID");
    match("=");
    expression();
}

void Parser::stmt(){
    //stmt = expression-stmt|selection-stmt|iteration-stmt|read-stmt|write-stmt     | compound-stmt
    if(next_token.substr(0,3) == "let")
        expression_stmt();
    else if(next_token.substr(0,2) == "if")
        selection_stmt();
    else if(next_token.substr(0,5) == "while")
        iteration_stmt();
    else if(next_token.substr(0,5) == "write")
        write_stmt();
    else if(next_token.substr(0,4) == "read")
        read_stmt();
    else if(next_token.substr(0,1) == "{")
        compound_stmt();
}

void Parser::var_declaration(){
    //var-declaration= type-specifier ID;
    type_specifier();
    match("ID");
}

void Parser::compound_stmt(){
    //compound-stmt    = { { stmt; } }
    match("{");
    if (next_token.substr(0,1) == "{"){
        match("{");
        stmt();
        match("}");
    }
    match("}");
}

void Parser::declaration_list(){
    //declaration-list= var-declaration { var-declaration }
    var_declaration();
    if (next_token.substr(0, 1) == "{"){
        match("{");
        var_declaration();
        match("}");
    }
}
