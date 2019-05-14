//
//  main.cpp
//  Assignment 2
//
//  Created by Fady on 4/2/19.
//  Copyright © 2019 Fady Hanna. All rights reserved.
//


#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <vector>
#include "Parser.h"
using namespace std;

int main()
{
    Parser parser;
    parser.run_program("gcd-error.txt");
    return 0;
}
