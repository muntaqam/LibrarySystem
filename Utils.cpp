//----------------------------------------------
// Name:           Muntaqa Maahi
// Student Number: 164356180
// Email:          mmaahi@myseneca.ca
// Section:        F
//----------------------------------------------


#include <iostream>
using namespace std;
#include "Utils.h"
#include <string>
#include <algorithm>
#include <cctype>
namespace sdds {
   // reads an integer from console the integer referenced by "val"
   // argument.
   // if the user enters an invalid integer or values outside of the
   // boundries set by "min" or "max" , this function flushes the
   //keyboard, prints the "errorMessage and reads again
   // untill user enters an acceptable integer
   void readN(int& val, int min, int max, const char* ErrorMess) {
      bool ok;
      char newline;
      do {
         cin >> val;
         newline = cin.get();
         if (cin.fail() || newline != '\n') {
            ok = false;
            cin.clear();
            cin.ignore(1000, '\n');
         }
         else {
            ok = val <= max && val >= min;
         }
      } while (!ok && cout <<ErrorMess);
   }
   // reads a C style string from console up to "len" characters into the
   // the string pointed by the "str" pointer
   // if the user enters more than "len" characters, this function
   // flushes the keyboard, prints the "errorMessage and reads again
   // untill user enters an acceptable string
   void readC(char* str, int len, const char* errorMessage) {
      bool ok;
      do {
         ok = true;
         cin.getline(str, len+1,'\n'); ///removed ln
         if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            ok = false;
         }
      }while(!ok && cout << errorMessage);
   }

void readL(long long& val, long long min, long long max, const char* ErrorMess) {
     bool ok;
     char newline;
     do {
        cin >> val;
        newline = cin.get();
        if (cin.fail() || newline != '\n') {
           ok = false;
           cin.clear();
           cin.ignore(1000, '\n');
        }
        else {
           ok = val <= max && val >= min;
        }
     } while (!ok && cout <<ErrorMess);
  }
    

}
