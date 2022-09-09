#include <iostream>
#include "PersonalBudget.h"

using namespace std;

char selectOptionFromMainMenu() {
    char select;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    select = AuxilaryMethods::readChar();

    return select;
}

char selectOptionFromUserMenu() {
    char select;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    select = AuxilaryMethods::readChar();

    return select;
}

int main() {
    PersonalBudget personalBudget("Users.xml", "Incomes.xml", "Expenses.xml");

    while (true) {
        if (!personalBudget.isUserLogged()) {
            char select = selectOptionFromMainMenu();

            switch (select) {
            case '1':
                personalBudget.userRegistration();
                break;
            case '2':
                personalBudget.userSignIn();
                break;
            case '9':
                exit(0);
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
            }
        } else {
            char select = selectOptionFromUserMenu();

            switch (select) {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.displayBalanceForCurrentMonth();
                break;
            case '4':
                personalBudget.displayBalanceForPreviousMonth();
                break;
            case '5':
                personalBudget.displayBalanceForSelectedPeriod();
                break;
            case '6':
                personalBudget.changeLoggedUserPassword();
                break;
            case '7':
                personalBudget.userSignOut();
                break;
            }
        }
    }
    return 0;
}
