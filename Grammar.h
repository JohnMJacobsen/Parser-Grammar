/*
 * Members: John Jacobsen 
 * Class User Account: cssc0400
 * RED ID: 820405580
 *
 * CS530, Spring 2019
 * Assignment #3: Grammar/Parser Evaluation
 * Filename: Grammar.h
 * Purpose: Header file for Grammar.cpp
 */


#ifndef GRAMMAR_H
#define GRAMMAR_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>


/**
 * Class Name: Grammar
 * Description: Checks that the given statements are valid with the defined grammar.
 */
class Grammar {
public:
    /**
     * Function: checkExpression
     * Prototype: std::vector<std::string> Grammar::checkExpression()
     * Purpose: Checks whether a given expression was grammatically correct in the particular situation
     * Parameters: std::vector<std::string> token that is being checked as an expression
     * Returns: a vector with two components that give the result of the test
     */
    std::vector<std::string> checkExpression (std::vector<std::string> token);
    
    /**
     * Function: checkAssignment
     * Prototype: std::vector<std::string> Grammar::checkAssignment()
     * Purpose: Checks whether a given assignment was grammatically correct in the particular situation
     * Parameters: std::vector<std::string> token that is being checked as an assignment
     * Returns: a vector with two components that give the result of the test
     */
    std::vector<std::string> checkAssignment (std::vector<std::string> token);
    
private:
    /**
     * Function: checkIdentifier
     * Prototype: bool Grammar::checkIdentifier()
     * Purpose: Checks whether a given identifier was grammatically correct in the particular situation
     * Parameters: std::string token that is being checked as an identifier
     * Returns: true if valid or false if not
     */
    static bool checkIdentifier (std::string token);
    
    /**
     * Function: checkCharacter
     * Prototype: bool Grammar::checkCharacter()
     * Purpose: Checks whether a given character was grammatically correct in the particular situation
     * Parameters: char character - a single character that is being attempted to be used as an character
     * Returns: true if valid or false if not
     */
    static bool checkCharacter (char character);
    
    /**
     * Function: checkDigit
     * Prototype: bool Grammar::checkDigit()
     * Purpose: Checks whether a given digit was grammatically correct in the particular situation
     * Parameters: digit - a single character that is being attempted to be used as an digit
     * Returns: true if valid or false if not
     */
    static bool checkDigit (char digit);
    
    /**
     * Function: checkOperator
     * Prototype: bool Grammar::checkOperator()
     * Purpose: Checks whether a given operator was grammatically correct in the particular situation
     * Parameters: operators - a single character that is being attempted to be used as an operator
     * Returns: true if valid or false if not
     */
    static bool checkOperator (char operators);
};

#endif