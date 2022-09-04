#include "PersonalBudget.h"

void PersonalBudget::userRegistration() {
    userManager.userRegistration();
}

void PersonalBudget::userSignIn() {
    userManager.userSignIn();
    if (userManager.isUserLogged()) {
        budgetManager = new BudgetManager(INCOME_FILE_NAME, userManager.getLoggedUserId());
    }
}

void PersonalBudget::addIncome() {
    if (userManager.isUserLogged()) {
        budgetManager->addIncome();
    } else {
        cout << "Aby dodac przychod nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void PersonalBudget::displayIncomes() {
    budgetManager->displayIncomes();
}
