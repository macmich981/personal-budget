#ifndef USERFILE_H
#define USERFILE_H

#include <vector>
#include "User.h"
#include "Markup.h"

using namespace std;

class UserFile {
    const string USER_FILE_NAME;

public:
    UserFile(string userFileName) : USER_FILE_NAME(userFileName) {};
    void saveUserToFile(User);
    vector<User> loadUsersFromFile();
    void changeLoggedUserPasswordInFile(string, int);
};

#endif
