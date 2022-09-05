#include "ExpenseFile.h"

bool ExpenseFile::saveExpenseToFile(Expense expense) {
    CMarkup xml;

    xml.Load(getFileName());
    if (!xml.FindElem("EXPENSES")) {
        xml.AddElem("EXPENSES");
    }
    xml.IntoElem();
    xml.AddElem("expenseId", expense.getId());
    xml.AddElem("userId", expense.getUserId());
    xml.AddElem("date", AuxilaryMethods::convertDateAsIntToDateString(expense.getDate(), '-'));
    xml.AddElem("item", expense.getItem());
    xml.AddElem("amount", to_string(expense.getAmount()));
    lastExpenseId++;
    return xml.Save(getFileName());
}

vector<Expense> ExpenseFile::loadExpensesFromFile(int loggedUserId) {
    CMarkup xml;
    Expense expense;
    vector<Expense> expenses;

    xml.Load(getFileName());
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("expenseId")) {
        int expenseId = stoi(xml.GetData());
        lastExpenseId = expenseId;
        xml.FindElem("userId");
        if (loggedUserId == stoi(xml.GetData())) {
            expense.setId(expenseId);
            expense.setUserId(stoi(xml.GetData()));
            xml.FindElem("date");
            expense.setDate(AuxilaryMethods::convertDateStringToDateAsInt(xml.GetData(), '-'));
            xml.FindElem("item");
            expense.setItem(xml.GetData());
            xml.FindElem("amount");
            expense.setAmount(stod(xml.GetData()));
            expenses.push_back(expense);
        }
    }
    return expenses;
}

int ExpenseFile::getLastExpenseId() {
    return lastExpenseId;
}
