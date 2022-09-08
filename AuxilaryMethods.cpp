#include "AuxilaryMethods.h"

vector<string> AuxilaryMethods::split(string str, char delimiter) {
    stringstream stream(str);
    string segment;
    vector<string> splittedString;

    while (getline(stream, segment, delimiter)) {
       splittedString.push_back(segment);
    }
    return splittedString;
}

int AuxilaryMethods::countDelimiters(string str, char delimiter) {
    int delimiterCounter = 0;
    size_t delimiterPosition = str.find(delimiter);

    if (delimiterPosition == string::npos) {
        return 0;
    }
    do {
        delimiterCounter++;
        delimiterPosition = str.find(delimiter, delimiterPosition + 1);
    } while (delimiterPosition != string::npos);

    return delimiterCounter;
}

bool AuxilaryMethods::isNumber(string str) {
    for (int i = 0; i < str.size(); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

void AuxilaryMethods::removeSpaces(string &str) {
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
}

void AuxilaryMethods::replaceCommaByPoint(string &str) {
    replace(str.begin(), str.end(), ',', '.');
}

bool AuxilaryMethods::isDouble(string &str) {
    char *end = NULL;

    removeSpaces(str);
    replaceCommaByPoint(str);
    strtod(str.c_str(), &end);
    if (end == str || *end != '\0') {
        return false;
    }
    return true;
}

int AuxilaryMethods::convertDateStringToDateAsInt(string date, char delimiter) {
    vector<string> splittedDate = split(date, delimiter);
    return stoi(splittedDate[0] + splittedDate[1] + splittedDate[2]);
}

string AuxilaryMethods::readLine() {
    string line;

    getline(cin, line);

    return line;
}

string AuxilaryMethods::convertDateAsIntToDateString(int date, char delimiter) {
    string dateString = to_string(date);

    dateString.insert(dateString.size() - 2, 1, delimiter);
    dateString.insert(dateString.size() - 5, 1, delimiter);

    return dateString;
}

char AuxilaryMethods::readChar() {
    char ch;

    ch = getch();
    cout << ch << endl;
    return ch;
}
