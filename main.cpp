#include <iostream>
#include "PersonalBudget.h"

using namespace std;

int main() {
    PersonalBudget personalBudget("Users.xml", "Incomes.xml");

    //personalBudget.userRegistration();
    personalBudget.userSignIn();
    personalBudget.addIncome();
    personalBudget.displayIncomes();
    return 0;
}
