#include <iostream>
#include "PersonalBudget.h"

using namespace std;

int main() {
    PersonalBudget personalBudget("Users.xml");

    personalBudget.userRegistartion();
    personalBudget.userSignIn();
    return 0;
}
