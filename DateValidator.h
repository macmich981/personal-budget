#ifndef DATEVALIDATOR_H
#define DATEVALIDATOR_H

#include <iostream>
#include <ctime>
#include "AuxilaryMethods.h"

using namespace std;

class DateValidator {
public:
    static string getSystemCurrentDateAsString();
    static int getNumberOfDays(int, int);
    static string getEndOfCurrentMonthDate(char);
    static bool validateDate(string, char);
};

#endif
