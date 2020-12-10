#include "DynamsoftBarcodeReader.h"
#include "database.h"

//Display the inputted database line by line
void displayDatabase(std::ifstream& database){
  std::string line;
  while(std::getline(database, line)){
    std::cout << line << std::endl;
  }
}

//This function will check the database for the details provided in the qrcode
//Returns true if found and false if not
bool checkDatabase(std::ifstream& database, char qrcode[512]){
  std::string line;
  //Scan our qrcode for the details
  std::string result = BarcodeScan(qrcode);
  //erase the newline that is put on the end of the line
  result.erase(result.end()-1, result.end());
  std::cout << "Data of QRcode: " << result << std::endl;
  //Parse through the database to find our input
  while(std::getline(database, line)){
    if(result == line){
      std::cout << "Found line: " << line << std::endl;
      return true;
    }
  }
  std::cout << "not in database!" << std::endl;
  return false;
}

//This will simply start a simple menu that will take user input for our details
//In a real product, this would verify if the input is actually the proper types and would also prevent from a buffer overflow
//unfortunetly, this is vulnerable to such an attack
void newEntry(std::ofstream& database){
  std::string name;
  std::string birthday;
  std::string ssn;
  //Get details from the user
  std::cout << "Name: ";
  std::cin >> name;
  std::cout << "\nBirth Date: (MM-DD-YYYY) ";
  std::cin >> birthday;
  std::cout << "\nSSN: ";
  std::cin >> ssn;

  //Make our qrcode and output to the database
  std::string entry = name + "," + birthday + "," + ssn + "," + "\n";
  makeQr(entry.c_str());
  database << entry.c_str();
  std::cout << "Adding " << entry;
}

//This function utilizes the DynamsoftBarcodeReader library class of CBarcodeReader to scan our qr code
std::string BarcodeScan(char* path){
  TextResultArray* pResults;
  //Create a new reader object
  dynamsoft::dbr::CBarcodeReader* reader = new dynamsoft::dbr::CBarcodeReader();
  //Scan our license (as this is normally a paid product in which I have a free trial)
  reader->InitLicense("t0068NQAAAC2twMVVLoH0MeCgyjaW/crdFW0D2PS21uV8pfpD/nkzlqx13pKgUVaAvKFO/h26EDNvnISsmJNu6SsycQoQZG4=");

  //This will decode the file and store error codes in the variable
  int errorCode = reader->DecodeFile(path, "");
  //This will get our results and put it in pResults
  reader->GetAllTextResults(&pResults);
  //Get our results from pResults
  std::string results = pResults->results[0]->barcodeText;
  //Free the memory in which our reader was in
  dynamsoft::dbr::CBarcodeReader::FreeTextResults(&pResults);

  delete reader;

  //return our results
  return results;
}

//This function will utilize the QrCode library to create a QR code in svg format
//We then use a system program called rsvg to convert the svg file into a png
void makeQr(const char text[256]) {
  std::ofstream qrcode;
  qrcode.open("data/qrcode.svg");
  const qrcodegen::QrCode::Ecc errCorLvl = qrcodegen::QrCode::Ecc::LOW;  // Error correction level
  // Make and print the QR Code symbol
  const qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(text, errCorLvl);
  qrcode << qr.toSvgString(100);
  //Convert our outputted svg into a png
  system("rsvg-convert data/qrcode.svg > data/qrcode.png");
}
