#include "Expense.h"

void Expense::setId(int id) {
    this->id = id;
}

void Expense::setUserId(int userId) {
    this->userId = userId;
}

void Expense::setDate(int date) {
    this->date = date;
}

void Expense::setItem(string item) {
    this->item = item;
}

void Expense::setAmount(double amount) {
    this->amount = amount;
}

int Expense::getId() {
    return id;
}

int Expense::getUserId() {
    return userId;
}

int Expense::getDate() {
    return date;
}

string Expense::getItem() {
    return item;
}

double Expense::getAmount() {
    return amount;
}
