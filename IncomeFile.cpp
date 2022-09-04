#include "IncomeFile.h"

bool IncomeFile::saveIncomeToFile(Income income) {
    CMarkup xml;

    xml.Load(getFileName());
    if (!xml.FindElem("INCOMES")) {
        xml.AddElem("INCOMES");
    }
    xml.IntoElem();
    xml.AddElem("incomeId", income.getId());
    xml.AddElem("userId", income.getUserId());
    xml.AddElem("date", AuxilaryMethods::convertDateAsIntToDateString(income.getDate(), '-'));
    xml.AddElem("item", income.getItem());
    xml.AddElem("amount", to_string(income.getAmount()));
    lastIncomeId++;
    return xml.Save(getFileName());
}

vector<Income> IncomeFile::loadIncomesFromFile(int loggedUserId) {
    CMarkup xml;
    Income income;
    vector<Income> incomes;

    xml.Load(getFileName());
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("incomeId")) {
        int incomeId = stoi(xml.GetData());
        lastIncomeId = incomeId;
        xml.FindElem("userId");
        if (loggedUserId == stoi(xml.GetData())) {
            income.setId(incomeId);
            income.setUserId(stoi(xml.GetData()));
            xml.FindElem("date");
            income.setDate(AuxilaryMethods::convertDateStringToDateAsInt(xml.GetData(), '-'));
            xml.FindElem("item");
            income.setItem(xml.GetData());
            xml.FindElem("amount");
            income.setAmount(stod(xml.GetData()));
            incomes.push_back(income);
        }
    }
    return incomes;
}

int IncomeFile::getLastIncomeId() {
    return lastIncomeId;
}
