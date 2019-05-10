/*
 * Members: John Jacobsen 
 * Class User Account: cssc0400
 * RED ID: 820405580
 *
 * CS530, Spring 2019
 * Assignment #3: Grammar and parser
 * Filename: exp.cpp
 * Purpose: Driver Program
 */

#include <iostream>
#include <stdlib.h>
#include "Parser.h"
#include "Grammar.h"

int main(int argc, const char * argv[]) {
    std::string fileName;
    std::string currentLine;
    std::vector<std::string> statements;
    
    //If a file is provides at runtime, breaks that file into lines to be checked
    if (argc == 2) {
        fileName = argv[1];
        std::ifstream textFile(fileName.c_str(), std::ifstream::in);
        if (!textFile) {
            std::cerr << "Invalid input file" << std::endl;
            exit(-1);
        }
        while (std::getline(textFile, currentLine)) {
            statements.push_back(currentLine);
        }
        textFile.close();
    }
    //If no file is provided, allows the user to enter a line to be checked
    else {
        std::cout << "Enter a potential statement and hit enter: " << std::endl;
        std::getline(std::cin, currentLine);
        statements.push_back(currentLine);
    }
    Parser *run = new Parser;
    run -> run(statements);
    return 0;
}