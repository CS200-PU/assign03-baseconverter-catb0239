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
  const string MY_TITLE = "*****HEX-DECIMAL-BINARY CONVERTER*****";
  char hexDigit;

  printTitle(MY_TITLE);
  cout << "Enter a hex digit: ";
  cin >> hexDigit;

  cout << "Your hex digit is " << hexCharToInt(hexDigit) << endl;

  return EXIT_SUCCESS;
}

/*******************************************************************************
 Function: 	 	hexCharToInt

 Description: changes hex char to int

 Parameters:	hexDigit - hex digit to be changed

 Returned:	 	int to be changed to
 ******************************************************************************/
int hexCharToInt (char hexDigit) {
  const int ZERO = 0, TEN = 10, B_EQUAL = 11, C_EQUAL = 12, D_EQUAL = 13,
            E_EQUAL = 14, F_EQUAL = 15;
  const char HEX_A = 'A', HEX_B = 'B', HEX_C = 'C', HEX_D = 'D', HEX_E = 'E',
             HEX_F = 'F';
  int hexInt = ZERO, tempInt = hexDigit - '0';
  if (tempInt > ZERO && tempInt < TEN) {
    hexInt = tempInt;
  } else if (hexDigit == HEX_A) {
      hexInt = TEN;
  } else if (hexDigit == HEX_B) {
      hexInt = B_EQUAL;
  } else if (hexDigit == HEX_C) {
      hexInt = C_EQUAL;
  } else if (hexDigit == HEX_D) {
      hexInt = D_EQUAL;
  } else if (hexDigit == HEX_E) {
      hexInt = E_EQUAL;
  } else if (hexDigit == HEX_F) {
      hexInt = F_EQUAL;
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