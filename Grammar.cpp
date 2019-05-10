/*
 * Members: John Jacobsen 
 * Class User Account: cssc0400
 * RED ID: 820405580
 *
 * CS530, Spring 2019
 * Assignment #3: Grammar/Parser Evaluation
 * Filename: Grammar.cpp
 * Purpose: Performs the necessary checks to see if the given tokens are grammatically correct
 */


#include "Grammar.h"

std::vector<std::string> Grammar::checkAssignment(std::vector<std::string> tokens) {
    std::vector<std::string> result(2);
    std::stringstream explanationStream;
    Grammar *grammar = new Grammar();
    //Checks that the first token found is a valid identifier
    if (grammar->checkIdentifier(tokens[0])) {
        // Check that the second token found is an identifier
        if (tokens[1] == "=") {
            // Checks that the last token of the line is a ;
            if (tokens[tokens.size() - 1][0] == ';') {
                std::vector<std::string> internalExpressions;
                //Iterates through the rest of the expression, placing it into a vector
                for (int i = 2; i < tokens.size() - 1; i++) {
                    internalExpressions.push_back(tokens[i]);
                }
                //The non assigning part of an assignment is simply an expression, passes it there as a result
                return checkExpression(internalExpressions);
            }
            //Gives lack of ending semi-colon as failure reasoning
            else {
                explanationStream << "The final token was not a semi-colon, recieved \"" << tokens[tokens.size() - 1] << "\" instead!";
                result[0] = "Failure";
                result[1] = explanationStream.str();
                return result;
            }
        }
        //Gives lack of second token = as failure reasoning
        else {
            explanationStream << "The second token was not an equal sign, recieved \"" << tokens[1] << "\" instead!";
            result[0] = "Failure";
            result[1] = explanationStream.str();
            return result;
        }
    }
    //Gives lack of starting identifier as failure reasoning
    else {
        explanationStream << "The first token was not a valid identifier, revieved \"" << tokens[0] << "\" instead.";
        result[0] = "Failure";
        result[1] = explanationStream.str();
        return result;
    }
}

std::vector<std::string> Grammar::checkExpression(std::vector<std::string> tokens){
    std::vector<std::string> result(2);
    std::stringstream explanationStream;
    Grammar *grammar = new Grammar();
    //Checks that the first token found is a valid identifier
    if (tokens[0] != " " && grammar->checkIdentifier(tokens[0])) {
        //Checks that the identifier found is followed by an operator
        if (tokens[1].length() == 1 && grammar->checkOperator(tokens[1][0])) {
            // Checks that the token after the operator is another valid identifier
            if (grammar->checkIdentifier(tokens[tokens.size()-1])) {
                //Iterates through the middle pieces of the line to check for validity in the event of several identifiers and operators
                for (int i = 2; i < tokens.size()-1; i++) {
                    if (!(grammar->checkIdentifier(tokens[i]))) {
                        explanationStream << "The token \"" << tokens[i] << "\" is not a valid identifier.";
                        result[0] = "Failure";
                        result[1] = explanationStream.str();
                        return result;
                    }
                    i += 1;
                    if (!(grammar->checkOperator(tokens[i][0]))) {
                        explanationStream << "The token \"" << tokens[i] << "\" is not a valid operator.";
                        result[0] = "Failure";
                        result[1] = explanationStream.str();
                        return result;
                    }
                }
                result[0] = "Success";
                result[1] = " ";
                return result;
            }
            //Gives the token that was expected to be a valid identifier as cause for failure
            else {
                explanationStream << "The token \"" << tokens[tokens.size()-1] << "\" is not a valid identifier.";
                result[0] = "Failure";
                result[1] = explanationStream.str();
                return result;
            }
        }
        //Gives the token that was expected to be a valid operator as cause for failure
        else {
            explanationStream << "The token \"" << tokens[1] << "\" is not a valid operator.";
            result[0] = "Failure";
            result[1] = explanationStream.str();
            return result;
        }
    }
    //Gives the token that was expected to be a valid identifier as cause for failure
    else {
        explanationStream << "The token \"" << tokens[0] << "\" is not a valid identifier.";
        result[0] = "Failure";
        result[1] = explanationStream.str();
        return result;
    }
}

bool Grammar::checkIdentifier (std::string token) {
    
    //Returns false early if the first char of the token is not a character
    if (!checkCharacter(token[0])) {
        return false;
    }
    else {
        //Iterates through the rest of the token, checking that it is composed only of digits and characters
        for (int i = 1; i < token.length(); i++) {
            if (checkCharacter(token[i]) || checkDigit(token[i])) {
                continue;
            }
            else {
                return false;
            }
        }
        return true;
    }
}


//Character array of all grammar valid operators
char validDigits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

bool Grammar::checkDigit (char potentialDigit) {
    
    //Iterates through all valid digits to check that at least one is the given digit.
    for (int i = 0; i < sizeof(validDigits); i++) {
        if (validDigits[i] == potentialDigit) {
            return true;
        }
    }
    //If the given char is not a valid digit, returns false
    return false;
}


//Character array of all grammar valid characters
char validCharacters[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                          'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                          'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G',
                          'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
                          'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '(', ')'};
                          
bool Grammar::checkCharacter(char potentialCharacter) {
    
    //Iterates through all valid operators to check that at least one is the given character.
    for (int i = 0; i < sizeof(validCharacters); i++) {
        if (validCharacters[i] == potentialCharacter) {
            return true;
        }
    }
    //If the given char is not a valid character, returns false
    return false;
}


//Character array of all grammar valid operators
char validOperators[] = {'+', '-', '*', '/', '%'};

bool Grammar::checkOperator (char potentialOperator) {
    
    //Iterates through all valid operators to check that at least one is the given operator.
    for (int i = 0; i < sizeof(validOperators); i++) {
        if (validOperators[i] == potentialOperator) {
            return true;
        }
    }
    //If the given char is not a valid operator, returns false
    return false;
}