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
string reverseString (string& reversingStr);

/*******************************************************************************
 Function: 	 	main

 Description: converting base

 Parameters:	none

 Returned:	 	Exit Status
 ******************************************************************************/
int main () {
  const string MY_TITLE = "*****HEX-DECIMAL-BINARY CONVERTER*****",
    USER_PROMPT = "Enter your string to convert (q to quit):";

  const string DECIMAL = "D", BINARY = "B", HEXADECIMAL = "H", QUIT = "q";
  string myNumber, convertedString, baseChar;
  printTitle (MY_TITLE);
  myNumber = getNumber (USER_PROMPT);
  baseChar = getBase (myNumber);
  if (baseChar != DECIMAL && baseChar != HEXADECIMAL && baseChar != BINARY) {
    baseChar = QUIT;
  }
  while (baseChar != QUIT) {
    if (baseChar == DECIMAL) {
      cout << "The binary conversion is:  " << decimalToBinary (myNumber)
        << endl;
      cout << "The hexadecimal conversion is:  " << decimalToHex (myNumber)
        << endl << endl;
    }
    else if (baseChar == HEXADECIMAL) {
      cout << "The decimal conversion is: " << hexToDecimal (myNumber) << endl;
      cout << "The binary conversion is: " << hexToBinary (myNumber) << endl
        << endl;
    }
    else if (baseChar == BINARY) {
      cout << "The decimal conversion is: " << binaryToDecimal (myNumber)
        << endl;
      cout << "The hexadecimal conversion is: " << binaryToHex (myNumber)
        << endl << endl;
    }
    myNumber = getNumber (USER_PROMPT);
    baseChar = getBase (myNumber);
    if (baseChar != DECIMAL && baseChar != HEXADECIMAL && baseChar != BINARY) {
      baseChar = QUIT;
    }
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
  else if (hexInt % TEN == ZERO) {
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
  const string BINARY_PREFIX = "0b", HEXADECIMAL_PREFIX = "0x", QUIT = "q";
  const char BINARY = 'B', HEXADECIMAL = 'H', DECIMAL = 'D', QUIT_CHAR = 'q';
  int strLen = strNumber.length ();
  char originalNumPrefix;

  if (strNumber == QUIT) {
    originalNumPrefix = QUIT_CHAR;
  }
  else if (strLen > 2) {
    for (int i = 0; i <= 1; ++i) {
      if (strNumber[i] == BINARY_PREFIX[i]) {
        originalNumPrefix = BINARY;
      }
      else if (strNumber[i] == HEXADECIMAL_PREFIX[i]) {
        originalNumPrefix = HEXADECIMAL;
      }
      else {
        originalNumPrefix = DECIMAL;
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
  int convertedNum = 0, count = strNumber.length ();
  count--;

  for (int i = 2; i < strNumber.length (); i++) {
    convertedNum += (BINARY_NUM ^ count);
    count--;
  }
  return to_string (convertedNum);
}

/*******************************************************************************
 Function: 	 	decimalToBinary

 Description: converts decimal to binary

 Parameters:	strNumber - string carrying decimal to convert to binary

 Returned:	 	string representing the binary equivalent
 ******************************************************************************/
string decimalToBinary (const string& strNumber) {
  const char BINARY = 'b';
  int decimalConversion = stoi (strNumber), count = 0,
    decimalDivide = decimalConversion, modDecimal;
  string decimalToConvert;
  decimalToConvert += to_string (count);
  count++;
  decimalToConvert += BINARY;
  count++;
  if (decimalConversion == 0) {
    modDecimal = decimalDivide % 2;
  }
  else {
    while (decimalDivide != 1) {
      modDecimal = decimalConversion % 2;
      decimalToConvert += to_string (modDecimal);
      count++;
      decimalDivide /= 2;
    }
  }
  modDecimal = decimalDivide % 2;
  decimalToConvert += to_string (modDecimal);
  return reverseString (decimalToConvert);
}

/*******************************************************************************
 Function: 	 	decimalToHex

 Description: converts decimal to hexadecimal

 Parameters:	strNumber - string carrying decimal to convert to hexadecimal

 Returned:	 	string representing the hexadecimal equivalent
 ******************************************************************************/
string decimalToHex (const string& strNumber) {
  const char START = '0', HEX = 'x';
  string hexString;
  hexString += START;
  hexString += HEX;
  char hexChar;
  int decimalInt = stoi (strNumber), returningInt, divisionHex;
  returningInt = decimalInt % 16;
  divisionHex = decimalInt / 16;
  while (divisionHex != 0) {
    if (returningInt < 9) {
      hexString += to_string (divisionHex);
    }
    else if (returningInt == 10) {
      hexChar = 'A';
      returningInt -= 10;
    }
    else if (returningInt == 11) {
      hexChar = 'B';
      returningInt -= 11;
    }
    else if (returningInt == 12) {
      hexChar = 'C';
      returningInt -= 12;
    }
    else if (returningInt == 13) {
      hexChar = 'D';
      returningInt -= 13;
    }
    else if (returningInt == 14) {
      hexChar = 'E';
      returningInt -= 14;
    }
    else if (returningInt == 15) {
      hexChar = 'F';
      returningInt -= 15;
    }
    returningInt = divisionHex % 16;
    divisionHex /= 16;
  }
  if (returningInt < 9) {
    hexString += to_string (divisionHex);
  }
  else if (returningInt == 10) {
    hexChar = 'A';
    returningInt -= 10;
  }
  else if (returningInt == 11) {
    hexChar = 'B';
    returningInt -= 11;
  }
  else if (returningInt == 12) {
    hexChar = 'C';
    returningInt -= 12;
  }
  else if (returningInt == 13) {
    hexChar = 'D';
    returningInt -= 13;
  }
  else if (returningInt == 14) {
    hexChar = 'E';
    returningInt -= 14;
  }
  else if (returningInt == 15) {
    hexChar = 'F';
    returningInt -= 15;
  }
  else {
    hexString += hexChar;
    hexString = reverseString (hexString);
  }
  return hexString;
}

/*******************************************************************************
 Function: 	 	hexToDecimal

 Description: converts hex to decimal

 Parameters:	strNumber - string carrying hexadecimal to convert to decimal

 Returned:	 	string representing decimal equivalent
 ******************************************************************************/
string hexToDecimal (const string& strNumber) {
  int num = 0;
  for (int i = 2; i < strNumber.length (); i++) {
    num += hexCharToInt (strNumber[i]);
  }
  return to_string (num);
}

/*******************************************************************************
 Function: 	 	hexToBinary

 Description: converts hex to binary

 Parameters:	strNumber - string carrying hex to convert to binary

 Returned:	 	string representing binary equivalent
 ******************************************************************************/
string hexToBinary (const string& strNumber) {
  string decimalString = hexToDecimal (strNumber);
  return decimalToBinary (decimalString);
}

/*******************************************************************************
 Function: 	 	binaryToHex

 Description: converts binary to hex

 Parameters:	strNumber - string carrying binary to convert to hex

 Returned:	 	string representing the hexadecimal equivalent
 ******************************************************************************/
string binaryToHex (const string& strNumber) {
  string decimalString = binaryToDecimal (strNumber);
  return decimalToHex (decimalString);
}

/*******************************************************************************
 Function: 	 	reverseString

 Description: reverse input string

 Parameters:	reversingStr - string that needs to be reversed

 Returned:	 	reversed string
*******************************************************************************/
string reverseString (string& strToReverse) {
  string reversedString[strToReverse.length ()], stringReversed;
  int count = strToReverse.length ();
  stringReversed += '0';
  for (int i = 1; i < 2; ++i) {
    if (strToReverse[i] == 'b') {
      stringReversed += 'b';
    }
    else {
      stringReversed += 'x';
    }
  }
  for (int i = 1; i < strToReverse.length (); ++i) {
    reversedString[i] = strToReverse[count];
    --count;
  }
  for (int i = 2; i < strToReverse.length (); i++) {
    stringReversed += reversedString[i];
  }
  return stringReversed;
}