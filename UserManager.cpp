#include "UserManager.h"
#include "UserFile.h"

User UserManager::inputNewUserData() {
    User user;

    user.setId(getNewUserId());
    string name = "";
    cout << "Podaj imie: ";
    name = AuxilaryMethods::readLine();
    user.setName(name);

    string surname = "";
    cout << "Podaj nazwisko: ";
    surname = AuxilaryMethods::readLine();
    user.setSurname(surname);

    string login = "";
    do {
        cout << "Podaj login: ";
        login = AuxilaryMethods::readLine();
        user.setLogin(login);
    } while (isLoginExist(user.getLogin()));

    string password = "";
    cout << "Podaj haslo: ";
    password = AuxilaryMethods::readLine();
    user.setPassword(password);

    return user;
}

int UserManager::getNewUserId() {
    if (users.empty()) {
        return 1;
    }
    return users.back().getId() + 1;
}

bool UserManager::isLoginExist(string login) {
    for (User user : users) {
        if (user.getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::userRegistration() {
    User user = inputNewUserData();

    users.push_back(user);
    userFile.saveUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

void UserManager::userSignIn() {
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = AuxilaryMethods::readLine();

    for (User user : users) {
        if (user.getLogin() == login) {
            for (int attempts = 3; attempts > 0; attempts--) {
                cout << "Podaj haslo. Pozostalo prob: " << attempts << ": ";
                password = AuxilaryMethods::readLine();

                if (user.getPassword() == password) {
                    loggedUserId = user.getId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
}

bool UserManager::isUserLogged() {
    return loggedUserId > 0;
}

int UserManager::getLoggedUserId() {
    return loggedUserId;
}

void UserManager::changeLoggedUserPassword() {
    string newPassword = "";

    cout << "Podaj nowe haslo: ";
    newPassword = AuxilaryMethods::readLine();

    for (User &user : users) {
        if (user.getId() == loggedUserId) {
            user.setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    userFile.changeLoggedUserPasswordInFile(newPassword, loggedUserId);
}

void UserManager::userSignOut() {
    loggedUserId = 0;
}
