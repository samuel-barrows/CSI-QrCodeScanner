/**
   @file database.h
   @brief the functions for our csv database
   handles the functions needed to enter and read through our csv database
   @Author Samuel Barrows
   final project
   @date 12/03/20
*/

#ifndef DATABASE_H
#define DATABASE_H
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "QrCode.hpp"

//ifstream -> std::cout
//List out the lines in the database that is passed into the function
void displayDatabase(std::ifstream& database);

//ifstream, char -> bool
//Check to see if the details in a qrcode are in the inputted file
bool checkDatabase(std::ifstream& database, char qrcode[512]);

//details -> ofstream
//when called, start a menu for details to be put into the database and qrcode
void newEntry(std::ofstream& database);

//char -> file
//will make a qrcode out of the inputted text
void makeQr(const char text[256]);

#endif
