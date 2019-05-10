/*
 * Members: John Jacobsen 
 * Class User Account: cssc0400
 * RED ID: 820405580
 *
 * CS530, Spring 2019
 * Assignment #3: Grammar/Parser Evaluation
 * Filename: Parser.cpp
 * Purpose: parses the input text
 */

#include "Parser.h"

void Parser::run(std::vector<std::string> statements) {
    
    // Open output file
    std::ofstream outputstream("out.txt");
    FILE *outputStream = fopen("out.txt", "wb");
    
    bool pass = true;
    if (outputstream.is_open()) {
        fprintf(outputStream, "Line#\tInput\t\t\t\t\t\t\tValidity\t\t\tReasoning\n");
        //Iterates through each statement in the vector of statements (each line of text)
        for (int i = 0; i < statements.size(); i++) {
            if (!statements[i].empty()) {
                std::vector<std::string> tokens;
                std::istringstream line(statements[i]);
                std::string token;
                //Parses the line into individual space delineated tokens, storing them in a vector
                while (getline(line, token, ' ')) {
                    tokens.push_back(token);
                }
                //Passes the tokens to check if they are the corrent format
                std::vector<std::string> parseResults = chooseNecessaryValidation(tokens);
                //If a non valid line is read, sets the pass to false
                if ((parseResults[0] == "Invalid Expression.") || (parseResults[0] == "Invalid Assignment.")) {
                    pass = false;
                }
                fprintf(outputStream, "%5d: %-55s %-31s %-35s \n", i, statements[i].c_str(), parseResults[0].c_str(), parseResults[1].c_str());
            }
        }
        //Outputs differently depending on whether all files were valid or not
        if (pass) {
            fprintf(outputStream, "File Validation Successful");
        }
        else {
            fprintf(outputStream, "File Validation Failed");
        }
        //Closes the outputStream to exit the file
        outputstream.close();
    }
}


std::vector<std::string> Parser::chooseNecessaryValidation(std::vector<std::string> tokens) {
    std::vector<std::string> result(2);
    std::vector<std::string> validationResults(2);
    //Creates a pointer to the Grammar class to allow method calls
    Grammar *grammar = new Grammar;
    //Iterates through each token
    for (int i = 0; i < tokens.size(); i++) {
        //Checks to see if any tokens were a = sign, meaning the line was a potential assignment
        if (tokens[i] == "=") {
            validationResults = grammar->checkAssignment(tokens);
            //If the assignment check was successful, stores the first string as valid and leaves the seond blank
            if (validationResults[0] == "Success") {
                result[0] = "Valid Assignment.";
                result[1] = "";
                return result;
            }
            //The assignment check was not successful, stores invalid followed by the found reason
            else {
                result[0] = "Invalid Assignment.";
                result[1] = validationResults[1];
                return result;
            }
        }
    }
    //No = signs were found, therefor the line was a potential expression
    validationResults = grammar->checkExpression(tokens);
    //If the expression check was successful, stores the first string as valid and leaves the seond blank
    if (validationResults[0] == "Success") {
        result[0] = "Valid Expression.";
        result[1] = " ";
        return result;
    }
    //The expression check was not successful, stores invalid followed by the found reason
    else {
        result[0] = "Invalid Expression.";
        result[1] = validationResults[1];
        return result;
    }
}