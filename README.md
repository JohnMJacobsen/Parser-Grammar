/******************************************************************************

Members: John Jacobsen
Class User Accounts: cssc0400
REDIDs: 820405580


CS530, Spring 2019
Assignment #3, Grammar/Parser Evaluation
Filename: README.md

******************************************************************************/

Files included in this project:

Grammar.cpp
Grammer.h
Parser.cpp
Parser.h
exp.cpp
makefile
testFile.txt

Compile Instructions: Run command: make
Operating instructions: $ ./exp testFile.txt

Description of significant design decisions:

Main Program (exp.cpp):

  Reads in files file if provided, prompts user for input if no file is present


  Reads input file or user input into a vector<string>, runs Parser.cpp

Parser (Parser.cpp):

  Iteratively parser the line/s of text, passing them on to be checked for validity


  Outputs the result from the tests to a file for a comprehensive report

Grammar (Grammar.cpp):

  Takes a series of unique tokens and checks whether or not they are grammatically correct


  Checks that everything given is a correct series of identifiers, expressions, assignments, digits, characters, and operators


  Returns a vector detailing the results of the tests, whether they were a success or failure and why


List of extra features/algorithms/functionality included which were not required:

No extra features included in this program.

List of all known deficiencies or bugs:

No known bugs, hopefully you don't discover one

Lessons Learned:

How to write C++ code completely independently
How to use pointers to call other classes
How to create and parse a simple grammar
