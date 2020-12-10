#include <iostream>
#include <unistd.h>
#include "database.h"

//https://www.nayuki.io/page/qr-code-generator-library#cpp source for the generator
//https://www.dynamsoft.com/barcode-reader/ the scanner I'll be using. on a 30 day free trial
//https://wiki.gnome.org/action/show/Projects/LibRsvg?action=show&redirect=LibRsvg svg->png

//Simple usage function to display by default if no/invalid options are given or the user inputs the -h option
void usage(){
  std::cout << "USAGE: main [dnhs]" << std::endl;
  std::cout << "The s option requires the qrcode location" << std::endl;
}

int main(int argc, char* argv[]){
  int opt {};
  //Stream for input -> database
  std::ofstream database;
  //Stream for database -> program
  std::ifstream see_database;
  FILE* imagePath;
  bool loop = true;
  char* qrcode;

  while((opt = getopt(argc, argv, "ds:nh")) != EOF){
    switch(opt){
    case 'd':
      //Display the database with our input stream
      see_database.open("data/database.csv");
      displayDatabase(see_database);
      loop = false;
      break;
    case 's':
      //"scan" a qr code. Here we'll input an image file to be processed
      qrcode = optarg;
      //Check if the file path is valid
      imagePath = std::fopen(qrcode, "r");
      bool validFile;
      imagePath == NULL ? validFile = false : validFile = true;
      if(!validFile){
        std::cout << "file not found!" << std::endl;
        return 1;
      }
      //Open the database and enter the checkDatabase function with our qr code and database
      see_database.open("data/database.csv");
      checkDatabase(see_database, qrcode);
      loop = false;
      break;
    case 'n':
      //Input information into our database. outputs a qrcode into the data directory
      database.open("data/database.csv", std::fstream::app);
      newEntry(database);
      loop = false;
      break;
    case 'h':
      //help menu
      usage();
      break;
    default:
      usage();
      break;
    }
  }
  //Close our files
  database.close();
  see_database.close();
  return 0;
}
