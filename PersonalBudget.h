#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include "UserManager.h"
#include "BudgetManager.h"

using namespace std;

class PersonalBudget {
    UserManager userManager;
    BudgetManager *budgetManager;
    const string INCOME_FILE_NAME;

public:
    PersonalBudget(string userFileName, string incomeFileName) : userManager(userFileName), INCOME_FILE_NAME(incomeFileName) {
        budgetManager = NULL;
    }
    ~PersonalBudget() {
        delete budgetManager;
        budgetManager = NULL;
    }
    void userRegistration();
    void userSignIn();
    void addIncome();
    void displayIncomes();
};

#endif
