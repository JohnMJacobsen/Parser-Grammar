###########################################################
# File Name: makefile
# Members: John Jacobsen
# Class User Account: cssc0400
# REDIDs: 820405580
# CS530, Spring 2019
# Assignment #3, Grammar/Parser Evaluation
# Usage: run command: make -f makefile
# Output File: "outputFile"
###########################################################

# CC tells makefile to compile using g++ for .cpp files
# Fx, where x = files to be compiled
# OUT is the name of the output file

CC = g++

F1 = "exp.cpp"
F2 = "Parser.cpp"
F3 = "Grammar.cpp"

OUT = "exp"

all:
	$(CC) $(F1) $(F2) $(F3) -w -o $(OUT)

#######################[ EOF: Makefile ]###################
