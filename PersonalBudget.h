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
    const string EXPENSE_FILE_NAME;

public:
    PersonalBudget(string userFileName, string incomeFileName, string expenseFileName)
    : userManager(userFileName), INCOME_FILE_NAME(incomeFileName), EXPENSE_FILE_NAME(expenseFileName) {
        budgetManager = NULL;
    }
    ~PersonalBudget() {
        delete budgetManager;
        budgetManager = NULL;
    }
    void userRegistration();
    void userSignIn();
    void addIncome();
    void addExpense();
    void displayBalanceForCurrentMonth();
    void displayBalanceForPreviousMonth();
    void displayBalanceForSelectedPeriod();
    void changeLoggedUserPassword();
    void userSignOut();
};

#endif
