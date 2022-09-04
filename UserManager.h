#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include "User.h"
#include "UserFile.h"

class UserManager {
    int loggedUserId;
    vector<User> users;
    UserFile userFile;

    User inputNewUserData();
    int getNewUserId();
    bool isLoginExist(string);

public:
    UserManager(string userFileName) : userFile(userFileName) {
        loggedUserId = 0;
        users = userFile.loadUsersFromFile();
    }
    void userRegistration();
    void userSignIn();
    bool isUserLogged();
    int getLoggedUserId();
};

#endif
