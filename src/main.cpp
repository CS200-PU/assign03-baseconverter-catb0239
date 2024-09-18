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
char getBase (const string& strNumber);
string getNumber (const string& prompt);
void printTitle (const string& myTitle);
string binaryToDecimal (const string& strNumber);
string decimalToBinary (const string& strNumber);
string decimalToHex (const string& strNumber);
string hexToDecimal (const string& strNumber);
string hexToBinary (const string& strNumber);
string binaryToHex (const string& strNumber);

/*******************************************************************************
 Function: 	 	main

 Description: converting base

 Parameters:	none

 Returned:	 	Exit Status
 ******************************************************************************/
int main () {
  const string MY_TITLE = "*****HEX-DECIMAL-BINARY CONVERTER*****",
    USER_PROMPT = "Enter your string to convert (q to quit):";
  const char DECIMAL = 'D', BINARY = 'B', HEXADECIMAL = 'H';
  string hexDigit;
  int intForHex;
  char baseChar;

  printTitle (MY_TITLE);
  hexDigit = getNumber (USER_PROMPT);
  baseChar = getBase (hexDigit);

  if (baseChar == DECIMAL) {

  }
  else if (baseChar == HEXADECIMAL) {
    for (int i = 0; i < hexDigit.length (); ++i) {
      intForHex = hexCharToInt (hexDigit[i]);
    }

  }
  else if (baseChar == BINARY) {

  }

  return EXIT_SUCCESS;
}

/*******************************************************************************
 Function: 	 	hexCharToInt

 Description: changes hex char to int

 Parameters:	hexDigit - hex digit to be changed

 Returned:	 	int to be changed to
 ******************************************************************************/
int hexCharToInt (char hexDigit) {
  const int TEN = 10, ZERO = 0, FIVE = 5, THREE = 3;
  const char ZERO_CHAR = '0';
  int hexInt = (hexDigit % TEN), tempInt = hexDigit - ZERO_CHAR;
  if (tempInt < TEN) {
    hexInt = tempInt;
  }
  if (hexInt % TEN == ZERO) {
    hexInt = FIVE * THREE;
  }
  else {
    hexInt = hexInt + FIVE;
  }
  return hexInt;
}
/*******************************************************************************
 Function: 	 	printTitle

 Description: printsTitle

 Parameters:	myTitle - title of program

 Returned:	 	none
 ******************************************************************************/
void printTitle (const string& myTitle) {
  const char ASTERISK = '*';
  for (int i = 0; i < myTitle.length (); ++i) {
    cout << ASTERISK;
  }
  cout << endl << myTitle << endl;
  for (int i = 0; i < myTitle.length (); ++i) {
    cout << ASTERISK;
  }
  cout << endl;
}

/*******************************************************************************
 Function: 	 	getNumber

 Description: gets user input

 Parameters:	prompt - prompt to display to screen

 Returned:	 	string representing a decimal, hexidecimal, or binary number
 ******************************************************************************/
string getNumber (const string& prompt) {
  string userInput;
  cout << prompt;
  cin >> userInput;

  return userInput;
}

/*******************************************************************************
 Function: 	 	getBase

 Description: get the base of the string input

 Parameters:	strNumber - string representing a decimal, hexadecimal or binary

 Returned:	 	D if its decimal, H if its hexadecimal, B if its binary
 ******************************************************************************/
char getBase (const string& strNumber) {
  const string BINARY_PREFIX = "0b", HEXADECIMAL_PREFIX = "0x";
  const char BINARY = 'B', HEXADECIMAL = 'H', DECIMAL = 'D';
  int strLen = strNumber.length ();
  char originalNumPrefix;

  if (strLen > 2) {
    for (int i = 0; i <= 1; ++i) {
      if (strNumber[i] == BINARY_PREFIX[i]) {
        originalNumPrefix = BINARY;
      }
      else if (strNumber[i] == HEXADECIMAL_PREFIX[i]) {
        originalNumPrefix = HEXADECIMAL;
      }
    }
  }
  else {
    originalNumPrefix = DECIMAL;
  }
  return originalNumPrefix;
}

/*******************************************************************************
 Function: 	 	binaryToDecimal

 Description: converts binary to decimal

 Parameters:	strNumber - string carrying binary to convert to decimal

 Returned:	 	string representing the decimal equivalent
 ******************************************************************************/
string binaryToDecimal (const string& strNumber) {
  const int BINARY_NUM = 2;
  int convertedNum = 0, count = strNumber.length();


  for (int i = 2; i < strNumber.length (); i++) {
    int num = static_cast<int>(strNumber[i]);
    convertedNum += num * BINARY_NUM ^ count;
    count--;
  }
  return to_string(convertedNum);
}

/*******************************************************************************
 Function: 	 	decimalToBinary

 Description: converts decimal to binary

 Parameters:	strNumber - string carrying decimal to convert to binary

 Returned:	 	string representing the binary equivalent
 ******************************************************************************/
string decimalToBinary (const string& strNumber) {
  int decimalConversion = stoi (strNumber);
  string binaryToConvert[strNumber.length ()], binaryConverted;
  char transferChar;

  for (int i = strNumber.length (); i > 0; i--) {
    binaryToConvert[i] = to_string (decimalConversion % 2);
    binaryConverted += binaryToConvert[i];

  }
  return binaryConverted;
}

/*******************************************************************************
 Function: 	 	decimalToHex

 Description: converts decimal to hexadecimal

 Parameters:	strNumber - string carrying decimal to convert to hexadecimal

 Returned:	 	string representing the hexadecimal equivalent
 ******************************************************************************/
string decimalToHex (const string& strNumber) {

}

/*******************************************************************************
 Function: 	 	hexToDecimal

 Description: converts hex to decimal

 Parameters:	strNumber - string carrying hexadecimal to convert to decimal

 Returned:	 	string representing decimal equivalent
 ******************************************************************************/
string hexToDecimal (const string& strNumber) {

}

/*******************************************************************************
 Function: 	 	hexToBinary

 Description: converts hex to binary

 Parameters:	strNumber - string carrying hex to convert to binary

 Returned:	 	string representing binary equivalent
 ******************************************************************************/
string hexToBinary (const string& strNumber) {

}

/*******************************************************************************
 Function: 	 	binaryToHex

 Description: converts binary to hex

 Parameters:	strNumber - string carrying binary to convert to hex

 Returned:	 	string representing the hexadecimal equivalent
 ******************************************************************************/
string binaryToHex (const string& strNumber) {

}