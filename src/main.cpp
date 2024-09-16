//******************************************************************************
// File name:   main.cpp
// Author:      Micah Catbagan
// Date:        09/15/2024 (Replace xx/xx/xxxx with month/day/year)
// Class:       CS200-01 (Replace xx with your section number)
// Assignment:  Base Converter
// Purpose:     Convert hex, decimal and binary
// Hours:       too long.
//******************************************************************************

#include <iostream>

using namespace std;

int hexCharToInt (char hexDigit);
char getBase(const string& strNumber);
string getNumber (const string& prompt);
void printTitle (const string& myTitle);
string binaryToDecimal (const string& strNumber);
string decimalToBinary (const string& strNumber);
string decimalToHex (const string& strNumber);
string hexToDecimal (const string& strNumber);
string hexToBinary (const string& strNumber);
string binaryToHex (const string& strNumber);

/**************************************************************************
 Function: 	 	main

 Description: converting base

 Parameters:	none

 Returned:	 	Exit Status
 *************************************************************************/
int main () {
  char hexDigit;

  cout << "Enter a hex digit: ";
  cin >> hexDigit;

  cout << "Your hex digit is " << hexCharToInt(hexDigit) << endl;

  return EXIT_SUCCESS;
}

/**************************************************************************
 Function: 	 	hexCharToInt

 Description: changes hex char to int

 Parameters:	hexDigit - hex digit to be changed

 Returned:	 	int to be changed to
 *************************************************************************/
int hexCharToInt (char hexDigit) {
  const int ZERO = 0, TEN = 10;
  int hexInt = ZERO, tempInt = hexDigit - '0';
  if (tempInt > ZERO && tempInt < TEN) {
    hexInt = tempInt;
  } else if (hexDigit == 'A') {
    hexInt = 10;
  }
  return hexInt;
}