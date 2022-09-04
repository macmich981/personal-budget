#include "BudgetManager.h"

int BudgetManager::inputDate() {
    string date = "";

    while (!DateValidator::validateDate(date = AuxilaryMethods::readLine(), '-')) {
        cout << "Niepoprawny format i/lub data. Sprobuj ponownie: ";
    }
    return AuxilaryMethods::convertDateStringToDateAsInt(date, '-');
}

double BudgetManager::inputAmount() {
    string amount = "";

    while (!AuxilaryMethods::isDouble(amount = AuxilaryMethods::readLine())) {
        cout << "Niepoprawne dane. Sprobuj ponownie: ";
    }
    return round(stod(amount) * 100.0) / 100.0;
}

Income BudgetManager::inputNewIncomeData() {
    Income income;

    income.setId(incomeFile.getLastIncomeId() + 1);
    income.setUserId(LOGGED_USER_ID);

    cout << "Czy przychod dotyczy dnia dziejszego? Jesli tak, nacisnij 't': " << endl;
    if (getch() == 't') {
        income.setDate(AuxilaryMethods::convertDateStringToDateAsInt(DateValidator::getSystemCurrentDateAsString(), '-'));
    } else {
        cout << "Podaje date w formacie rrrr-mm-dd (nie wczesniej niz 2000-01-01 i nie pozniej niz ostatni dzien biezacego miesiaca): ";
        income.setDate(inputDate());
    }
    cout << "Podaj zrodlo przychodu: ";
    income.setItem(AuxilaryMethods::readLine());
    cout << "Podaj wysokosc przychodu: ";
    income.setAmount(inputAmount());

    return income;
}

void BudgetManager::addIncome() {
    Income income;

    system("cls");
    cout << " >>> DODAWANIE PRZYCHODU <<<" << endl << endl;
    income = inputNewIncomeData();

    incomes.push_back(income);
    if (incomeFile.saveIncomeToFile(income)) {
        cout << "Przychod zostal dodany" << endl;
    } else {
        cout << "Blad zapisu do pliku" << endl;
    }
    system("pause");
}

void BudgetManager::displayIncome(Income income) {
    cout << left << setw(15) << AuxilaryMethods::convertDateAsIntToDateString(income.getDate(), '-')
    << setw(20) << income.getItem()
    << setw(20) << right << fixed << setprecision(2) << income.getAmount() << endl;
}

void BudgetManager::displayIncomes() {
    system("cls");
    cout << ">>> Twoje przychody <<<" << endl << endl;
    if (incomes.empty()) {
        cout << "Brak wpisow..." << endl;
        return;
    }
    cout << left << setw(15) << "DATA" << setw(20) << "ZRODLO PRZYCHODU" << setw(20) << right << "KWOTA" << endl;
    cout << "=======================================================" << endl;
    sort(incomes.begin(), incomes.end());
    for (Income income : incomes) {
        displayIncome(income);
    }
}
