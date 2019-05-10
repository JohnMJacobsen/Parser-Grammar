/*
 * Members: John Jacobsen 
 * Class User Account: cssc0400
 * RED ID: 820405580
 *
 * CS530, Spring 2019
 * Assignment #3: Grammar/Parser Evaluation
 * Filename: Parser.h
 * Purpose: Header file for Parser.cpp
 */

#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>
#include "Grammar.h"


/**
 * Class Name: Parser
 * Description: Parses the text that has to be checked for validity.
 */
class Parser {
public:
    /**
     * Function: run
     * Prototype: void Parser::run()
     * Purpose: iterates through all statements that was given in the file and attempts to validate them
     * Parameters: std::vector<std::string> statements of all lines given in the file or through standard input
     * Returns: None
     */
    void run(std::vector<std::string> statements);
    
private:
    /**
     * Function: chooseNecessaryValidation
     * Prototype: std::vector<std::string> Parser::chooseNecessaryValidation(std::vector<std::string> tokens)
     * Purpose: decides what validation checks must be run and returns the result of those checks
     * Parameters: std::vector<std::string> tokens a single line broken up into tokens to be checked for valdity
     * Returns: std::vector<std::string> results of the checks that were performed
     */
    std::vector<std::string> chooseNecessaryValidation(std::vector<std::string> tokens);
};

#endif