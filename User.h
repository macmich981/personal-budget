#ifndef USER_H
#define USER_H

#include <iostream>

using namespace std;

class User {
    int id;
    string login;
    string password;
    string name;
    string surname;

public:
    void setId(int);
    void setLogin(string);
    void setPassword(string);
    void setName(string);
    void setSurname(string);

    int getId();
    string getLogin();
    string getPassword();
    string getName();
    string getSurname();
};

#endif
