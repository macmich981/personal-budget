#ifndef AUXILARYMETHODS_H
#define AUXILARYMETHODS_H

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include "DateValidator.h"

using namespace std;

class AuxilaryMethods {
public:
    static vector<string> split(string, char);
    static int countDelimiters(string, char);
    static bool isNumber(string);
    static void removeSpaces(string&);
    static void replaceCommaByPoint(string&);
    static bool isDouble(string&);
    static int convertDateStringToDateAsInt(string, char);
    static string readLine();
    static string convertDateAsIntToDateString(int, char);
};

#endif
