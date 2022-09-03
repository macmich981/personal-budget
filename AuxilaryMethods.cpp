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
    if (!DateValidator::validateDate(date, delimiter)) {
        return -1;
    }
    vector<string> splittedDate = split(date, delimiter);
    return stoi(splittedDate[0] + splittedDate[1] + splittedDate[2]);
}
