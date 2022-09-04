#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

using namespace std;

class Expense {
    int id;
    int userId;
    int date;
    string item;
    double amount;

public:
    Expense(int id = 0, int userId = 0, int date = 0, string item = "", double amount = 0) {
        this->id = id;
        this->userId = userId;
        this->date = date;
        this->item = item;
        this->amount = amount;
    }
    bool operator < (const Expense &expense) const {return date < expense.date;}

    void setId(int);
    void setUserId(int);
    void setDate(int);
    void setItem(string);
    void setAmount(double);

    int getId();
    int getUserId();
    int getDate();
    string getItem();
    double getAmount();
};

#endif
