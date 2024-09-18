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

/*******************************************************************************
 Function: 	 	main

 Description: converting base

 Parameters:	none

 Returned:	 	Exit Status
 ******************************************************************************/
int main () {
  const string MY_TITLE = "*****HEX-DECIMAL-BINARY CONVERTER*****",
               USER_PROMPT = "Enter your string to convert (q to quit):";
  string hexDigit;
  int intForHex;

  printTitle(MY_TITLE);
  hexDigit = getNumber(USER_PROMPT);
  for (int i = 0; i < hexDigit.length(); ++i) {
    intForHex = hexCharToInt (hexDigit[i]);
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
  } else {
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
  for (int i = 0; i < myTitle.length(); ++i) {
    cout << ASTERISK;
  }
  cout << endl << myTitle << endl;
  for (int i = 0; i < myTitle.length(); ++i) {
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

 Description: get the base 

 Parameters:	prompt - prompt to display to screen

 Returned:	 	string representing a decimal, hexidecimal, or binary number
 ******************************************************************************/
char getBase(const string& strNumber) {
  
}