#include "UserFile.h"

void UserFile::saveUserToFile(User user) {
    CMarkup xml;

    xml.Load(USER_FILE_NAME);
    if (!xml.FindElem("USERS")) {
        xml.AddElem("USERS");
    }
    xml.IntoElem();
    xml.AddElem("userId", user.getId());
    xml.AddElem("login", user.getLogin());
    xml.AddElem("password", user.getPassword());
    xml.AddElem("name", user.getName());
    xml.AddElem("surname", user.getSurname());
    xml.Save(USER_FILE_NAME);
}

vector<User> UserFile::loadUsersFromFile() {
    CMarkup xml;
    User user;
    vector<User> users;

    xml.Load(USER_FILE_NAME);
    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("userId")) {
        user.setId(stoi(xml.GetData()));
        xml.FindElem("login");
        user.setLogin(xml.GetData());
        xml.FindElem("password");
        user.setPassword(xml.GetData());
        xml.FindElem("name");
        user.setName(xml.GetData());
        xml.FindElem("surname");
        user.setSurname(xml.GetData());
        users.push_back(user);
    }
    return users;
}
