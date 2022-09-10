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
    if (AuxilaryMethods::readChar() == 't') {
        income.setDate(AuxilaryMethods::convertDateStringToDateAsInt(DateValidator::getSystemCurrentDateAsString(), '-'));
    } else {
        cout << "Podaje date w formacie rrrr-mm-dd (nie wczesniej niz 2000-01-01 i nie pozniej niz ostatni dzien biezacego miesiaca): " << endl;
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

void BudgetManager::displayIncomes(string year, string month) {
    bool found = false;

    cout << endl << ">>> Twoje przychody za " + year + "-" + month + " <<<" << endl << endl;
    if (incomes.empty()) {
        cout << "Baza danych jest pusta..." << endl;
        return;
    }
    cout << left << setw(15) << "DATA" << setw(20) << "ZRODLO PRZYCHODU" << setw(20) << right << "KWOTA" << endl;
    cout << "=======================================================" << endl;
    sort(incomes.begin(), incomes.end());
    for (Income income : incomes) {
        string incomeDate = AuxilaryMethods::convertDateAsIntToDateString(income.getDate(), '-');
        vector<string> incomeSplittedDate = AuxilaryMethods::split(incomeDate, '-');
        string incomeYear = incomeSplittedDate[0];
        string incomeMonth = incomeSplittedDate[1];
        if (year == incomeYear && month == incomeMonth) {
            found = true;
            displayIncome(income);
        }
    }
    if (!found) {
        cout << "Brak wpisow za dany miesiac..." << endl;
    }
}

Expense BudgetManager::inputNewExpenseData() {
    Expense expense;

    expense.setId(expenseFile.getLastExpenseId() + 1);
    expense.setUserId(LOGGED_USER_ID);

    cout << "Czy wydatek dotyczy dnia dziejszego? Jesli tak, nacisnij 't': " << endl;
    if (AuxilaryMethods::readChar() == 't') {
        expense.setDate(AuxilaryMethods::convertDateStringToDateAsInt(DateValidator::getSystemCurrentDateAsString(), '-'));
    } else {
        cout << "Podaje date w formacie rrrr-mm-dd (nie wczesniej niz 2000-01-01 i nie pozniej niz ostatni dzien biezacego miesiaca): " << endl;
        expense.setDate(inputDate());
    }
    cout << "Podaj nazwe wydatku: ";
    expense.setItem(AuxilaryMethods::readLine());
    cout << "Podaj wysokosc wydatku: ";
    expense.setAmount(inputAmount());

    return expense;
}

void BudgetManager::addExpense() {
    Expense expense;

    system("cls");
    cout << " >>> DODAWANIE WYDATKU <<<" << endl << endl;
    expense = inputNewExpenseData();

    expenses.push_back(expense);
    if (expenseFile.saveExpenseToFile(expense)) {
        cout << "Wydatek zostal dodany" << endl;
    } else {
        cout << "Blad zapisu do pliku" << endl;
    }
    system("pause");
}

void BudgetManager::displayExpense(Expense expense) {
    cout << left << setw(15) << AuxilaryMethods::convertDateAsIntToDateString(expense.getDate(), '-')
    << setw(20) << expense.getItem()
    << setw(20) << right << fixed << setprecision(2) << expense.getAmount() << endl;
}

void BudgetManager::displayExpenses(string year, string month) {
    bool found = false;

    cout << endl << ">>> Twoje wydatki za " + year + "-" + month + " <<<" << endl << endl;
    if (expenses.empty()) {
        cout << "Baza danych jest pusta..." << endl;
        return;
    }
    cout << left << setw(15) << "DATA" << setw(20) << "NAZWA WYDATKU" << setw(20) << right << "KWOTA" << endl;
    cout << "=======================================================" << endl;
    sort(expenses.begin(), expenses.end());
    for (Expense expense : expenses) {
        string expenseDate = AuxilaryMethods::convertDateAsIntToDateString(expense.getDate(), '-');
        vector<string> expenseSplittedDate = AuxilaryMethods::split(expenseDate, '-');
        string expenseYear = expenseSplittedDate[0];
        string expenseMonth = expenseSplittedDate[1];
        if (year == expenseYear && month == expenseMonth) {
            found = true;
            displayExpense(expense);
        }
    }
    if (!found) {
        cout << "Brak wpisow za dany miesiac..." << endl;
    }
}

double BudgetManager::getIncomesSumForSelectedMonth(string year, string month) {
    if (incomes.empty()) {
        return 0;
    }
    bool found = false;
    double sum = 0;

    for (Income income : incomes) {
        string incomeDate = AuxilaryMethods::convertDateAsIntToDateString(income.getDate(), '-');
        vector<string> incomeSplittedDate = AuxilaryMethods::split(incomeDate, '-');
        string incomeYear = incomeSplittedDate[0];
        string incomeMonth = incomeSplittedDate[1];
        if (year == incomeYear && month == incomeMonth) {
            found = true;
            sum += income.getAmount();
        }
    }
    if (!found) {
        return 0;
    }
    return sum;
}

double BudgetManager::getExpensesSumForSelectedMonth(string year, string month) {
    if (expenses.empty()) {
        return 0;
    }
    bool found = false;
    double sum = 0;

    for (Expense expense : expenses) {
        string expenseDate = AuxilaryMethods::convertDateAsIntToDateString(expense.getDate(), '-');
        vector<string> expenseSplittedDate = AuxilaryMethods::split(expenseDate, '-');
        string expenseYear = expenseSplittedDate[0];
        string expenseMonth = expenseSplittedDate[1];
        if (year == expenseYear && month == expenseMonth) {
            found = true;
            sum += expense.getAmount();
        }
    }
    if (!found) {
        return 0;
    }
    return sum;
}

void BudgetManager::displayBalanceForCurrentMonth() {
    system("cls");
    cout << " >>> BILANS DLA BIEZACEGO MIESIACA <<<" << endl << endl;
    string date = DateValidator::getSystemCurrentDateAsString();
    vector<string> splittedDate = AuxilaryMethods::split(date, '-');

    displayIncomes(splittedDate[0], splittedDate[1]);
    displayExpenses(splittedDate[0], splittedDate[1]);
    double incomeSum = getIncomesSumForSelectedMonth(splittedDate[0], splittedDate[1]);
    double expenseSum = getExpensesSumForSelectedMonth(splittedDate[0], splittedDate[1]);
    cout << endl;
    cout << "Suma przychodow: " << incomeSum << endl;
    cout << "Suma wydatkow: " << expenseSum << endl;
    cout << "Bilans: " << incomeSum - expenseSum << endl;
    system("pause");
}

string BudgetManager::getPreviousMonthDate(string date) {
    vector<string> splittedDate = AuxilaryMethods::split(date, '-');
    int year = stoi(splittedDate[0]);
    int month = stoi(splittedDate[1]);
    char firstDigitInMonthNumber = splittedDate[1][0];

    if (--month <= 0) {
        month = 12;
        year--;
    }
    if (firstDigitInMonthNumber == '0') {
        return to_string(year) + "-" + firstDigitInMonthNumber + to_string(month);
    } else {
        return to_string(year) + "-" + to_string(month);
    }
}

void BudgetManager::displayBalanceForPreviousMonth() {
    system("cls");
    cout << " >>> BILANS DLA POPRZEDNIEGO MIESIACA <<<" << endl << endl;
    string currentDate = DateValidator::getSystemCurrentDateAsString();
    string previousMonthDate = getPreviousMonthDate(currentDate);
    vector<string> splittedPreviousMonthDate = AuxilaryMethods::split(previousMonthDate, '-');

    displayIncomes(splittedPreviousMonthDate[0], splittedPreviousMonthDate[1]);
    displayExpenses(splittedPreviousMonthDate[0], splittedPreviousMonthDate[1]);
    double incomeSum = getIncomesSumForSelectedMonth(splittedPreviousMonthDate[0], splittedPreviousMonthDate[1]);
    double expenseSum = getExpensesSumForSelectedMonth(splittedPreviousMonthDate[0], splittedPreviousMonthDate[1]);
    cout << endl;
    cout << "Suma przychodow: " << incomeSum << endl;
    cout << "Suma wydatkow: " << expenseSum << endl;
    cout << "Bilans: " << incomeSum - expenseSum << endl;
    system("pause");
}

void BudgetManager::displayBalanceForSelectedPeriod() {
    system("cls");
    cout << ">>> BILANS DLA WYBRANEGO OKRESU <<<" << endl << endl;
    cout << "Podaje date poczatkowa w formacie rrrr-mm-dd: ";
    int dateFrom = inputDate();
    cout <<"Podaj date koncowa w formacie rrrr-mm-dd: ";
    int dateTo;
    while (dateTo = inputDate() < dateFrom) {
        cout << "Data koncowa musi byc pozniejsza od daty poczatkowej! Sprobuj ponownie: ";
    }
    double incomeSum = 0;
    double expenseSum = 0;

    cout << endl;
    sort(incomes.begin(), incomes.end());
    cout << ">>> Twoje przychody za wybrany okres <<< " << endl << endl;
    for (Income income : incomes) {
        if (income.getDate() >= dateFrom && income.getDate() <= dateTo) {
            incomeSum += income.getAmount();
            displayIncome(income);
        }
    }
    if (!incomeSum) {
        cout << "Brak wpisow za dany miesiac..." << endl;
    }
    cout << endl;
    sort(expenses.begin(), expenses.end());
    cout << ">>> Twoje wydatki za wybrany okres <<< " << endl << endl;
    for (Expense expense : expenses) {
        if (expense.getDate() >= dateFrom && expense.getDate() <= dateTo) {
            expenseSum += expense.getAmount();
            displayExpense(expense);
        }
    }
    if (!expenseSum) {
        cout << "Brak wpisow za dany miesiac..." << endl;
    }
    cout << endl;
    cout << "Suma przychodow: " << incomeSum << endl;
    cout << "Suma wydatkow: " << expenseSum << endl;
    cout << "Bilans: " << incomeSum - expenseSum << endl;
    system("pause");
}
