#ifndef EXPENSEFILE_H
#define EXPENSEFILE_H

#include <vector>
#include "BudgetFile.h"
#include "Expense.h"
#include "Markup.h"
#include "AuxilaryMethods.h"

using namespace std;

class ExpenseFile : public BudgetFile {
    int lastExpenseId;

public:
    ExpenseFile(string expenseFileName) : BudgetFile(expenseFileName) {
        lastExpenseId = 0;
    }
    bool saveExpenseToFile(Expense);
    vector<Expense> loadExpensesFromFile(int);
    int getLastExpenseId();
};

#endif
