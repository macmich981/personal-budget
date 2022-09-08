#include "PersonalBudget.h"

void PersonalBudget::userRegistration() {
    userManager.userRegistration();
}

void PersonalBudget::userSignIn() {
    userManager.userSignIn();
    if (userManager.isUserLogged()) {
        budgetManager = new BudgetManager(INCOME_FILE_NAME, EXPENSE_FILE_NAME, userManager.getLoggedUserId());
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

void PersonalBudget::addExpense() {
    if (userManager.isUserLogged()) {
        budgetManager->addExpense();
    } else {
        cout << "Aby dodac wydatek nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void PersonalBudget::displayBalanceForCurrentMonth() {
    if (userManager.isUserLogged()) {
        budgetManager->displayBalanceForCurrentMonth();
    } else {
        cout << "Aby wyswietlic bilans nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void PersonalBudget::displayBalanceForPreviousMonth() {
    if (userManager.isUserLogged()) {
        budgetManager->displayBalanceForPreviousMonth();
    } else {
        cout << "Aby wyswietlic bilans nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void PersonalBudget::displayBalanceForSelectedPeriod() {
    if (userManager.isUserLogged()) {
        budgetManager->displayBalanceForSelectedPeriod();
    } else {
        cout << "Aby wyswietlic bilans nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void PersonalBudget::changeLoggedUserPassword() {
    if (userManager.isUserLogged()) {
        userManager.changeLoggedUserPassword();
    } else {
        cout << "Aby zmienic haslo nalezy najpierw sie zalogowac" << endl;
        system("pause");
    }
}

void PersonalBudget::userSignOut() {
    userManager.userSignOut();
    delete budgetManager;
    budgetManager = NULL;
    cout << "Wylogowano" << endl;
    system("pause");
}
