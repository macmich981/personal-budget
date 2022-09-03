#ifndef INCOMEFILE_H
#define INCOMEFILE_H

#include <vector>
#include "BudgetFile.h"
#include "Income.h"
#include "Markup.h"

using namespace std;

class IncomeFile : public BudgetFile {
    int lastIncomeId;

    IncomeFile(string incomeFileName) : BudgetFile(incomeFileName) {
        lastIncomeId = 0;
    }
    bool saveIncomeToFile(Income);
    vector<Income> loadIncomesFromFile(int);
    int getLastIncomeId();
};

#endif
