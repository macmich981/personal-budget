#ifndef BUDGETFILE_H
#define BUDGETFILE_H

#include <iostream>

using namespace std;

class BudgetFile {
    const string FILE_NAME;

public:
    BudgetFile(string fileName) : FILE_NAME(fileName) {};
    string getFileName();
};

#endif
