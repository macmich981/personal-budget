#include "DateValidator.h"

string DateValidator::getSystemCurrentDateAsString() {
    time_t now = time(0);
    tm *currentTime = localtime(&now);
    char dateString[50];

    strftime(dateString, sizeof(dateString), "%Y-%m-%d", currentTime);
    return dateString;
}

int DateValidator::getNumberOfDays(int month, int year) {
    if (month == 2) {
		if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
			return 29;
		} else {
			return 28;
		}
	} else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month==12) {
		return 31;
	} else {
		return 30;
	}
}

string DateValidator::getEndOfCurrentMonthDate(char delimiter) {
    string currentDate = getSystemCurrentDateAsString();
    vector<string> splittedCurrentDate = AuxilaryMethods::split(currentDate, delimiter);

    int year = stoi(splittedCurrentDate[0]);
    int month = stoi(splittedCurrentDate[1]);
    int days = getNumberOfDays(month, year);

    currentDate.pop_back();
    currentDate.pop_back();

    return currentDate + to_string(days);
}

bool DateValidator::validateDate(string date, char delimiter) {
    if (AuxilaryMethods::countDelimiters(date, delimiter) != 2) {
        return false;
    }

    vector<string> dateSplittedByDelimiters = AuxilaryMethods::split(date, delimiter);
    if (!AuxilaryMethods::isNumber(dateSplittedByDelimiters[0])) {
        return false;
    }
    if (dateSplittedByDelimiters[1].size() != 2 || !AuxilaryMethods::isNumber(dateSplittedByDelimiters[1])) {
        return false;
    }
    if (dateSplittedByDelimiters[2].size() != 2 || !AuxilaryMethods::isNumber(dateSplittedByDelimiters[2])) {
        return false;
    }
    if (date.compare("2000-01-01") < 0 || getEndOfCurrentMonthDate(delimiter).compare(date) < 0) {
        return false;
    }
    int year = stoi(dateSplittedByDelimiters[0]);
    int month = stoi(dateSplittedByDelimiters[1]);
    if (month < 1 || month > 12) {
        return false;
    }
    int days = stoi(dateSplittedByDelimiters[2]);
    if (days < 1 || days > getNumberOfDays(month, year)) {
        return false;
    }
    return true;
}
