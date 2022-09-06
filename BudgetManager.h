#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <conio.h>
#include <iomanip>
#include <tgmath.h>
#include "Income.h"
#include "IncomeFile.h"
#include "Expense.h"
#include "ExpenseFile.h"
#include "DateValidator.h"
#include "AuxilaryMethods.h"

using namespace std;

class BudgetManager {
    const int LOGGED_USER_ID;
    vector<Income> incomes;
    vector<Expense> expenses;
    IncomeFile incomeFile;
    ExpenseFile expenseFile;

    Income inputNewIncomeData();
    Expense inputNewExpenseData();
    int inputDate();
    double inputAmount();
    void displayIncome(Income);
    void displayExpense(Expense);

public:
    BudgetManager(string incomeFileName, string expenseFileName, int loggedUserId)
    : incomeFile(incomeFileName), expenseFile(expenseFileName), LOGGED_USER_ID(loggedUserId) {
        incomes = incomeFile.loadIncomesFromFile(LOGGED_USER_ID);
        expenses = expenseFile.loadExpensesFromFile(LOGGED_USER_ID);
    }
    void addIncome();
    void addExpense();
    void displayIncomes();
    void displayExpenses();
};

#endif
