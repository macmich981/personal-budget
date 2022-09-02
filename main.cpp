#include <iostream>
#include "PersonalBudget.h"

using namespace std;

int main() {
    PersonalBudget personalBudget("Users.xml");

    personalBudget.userRegistration();
    personalBudget.userSignIn();
    return 0;
}
