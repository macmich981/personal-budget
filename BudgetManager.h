#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <conio.h>
#include <iomanip>
#include <tgmath.h>
#include "Income.h"
#include "IncomeFile.h"
#include "DateValidator.h"
#include "AuxilaryMethods.h"

using namespace std;

class BudgetManager {
    const int LOGGED_USER_ID;
    vector<Income> incomes;
    IncomeFile incomeFile;

    Income inputNewIncomeData();
    int inputDate();
    double inputAmount();
    void displayIncome(Income);

public:
    BudgetManager(string incomeFileName, int loggedUserId) : incomeFile(incomeFileName), LOGGED_USER_ID(loggedUserId) {
        incomes = incomeFile.loadIncomesFromFile(LOGGED_USER_ID);
    }
    void addIncome();
    void displayIncomes();
};

#endif
