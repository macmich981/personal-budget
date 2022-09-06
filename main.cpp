#include <iostream>
#include "PersonalBudget.h"

using namespace std;

int main() {
    PersonalBudget personalBudget("Users.xml", "Incomes.xml", "Expenses.xml");

    //personalBudget.userRegistration();
    personalBudget.userSignIn();
    //personalBudget.addIncome();
    personalBudget.addExpense();
    personalBudget.displayIncomes();
    personalBudget.displayExpenses();
    return 0;
}
