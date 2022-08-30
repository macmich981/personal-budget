#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include "UserManager.h"

using namespace std;

class PersonalBudget {
    UserManager userManager;

public:
    PersonalBudget(string userFileName) : userManager(userFileName) {};
    void userRegistartion();
    void userSignIn();
};

#endif
