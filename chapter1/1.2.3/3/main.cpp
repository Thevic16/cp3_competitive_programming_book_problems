#include <iostream>
#include <map>

using namespace std;

/*
 * 3. Given a date, determine the day of the week (Monday, . . . , Sunday) on that day.
(e.g. 9 August 2010—the launch date of the first edition of this book—is a Monday.)
 *
 * */

int main() {
//    string months[12] = {
//            "March", "April", "May", "June",
//            "July", "August", "September", "October",
//            "November", "December", "January", "February"
//    };
    string days[7] = {
            "Sunday", "Monday", "Tuesday",
            "Wednesday", "Thursday", "Friday", "Saturday"
    };
    map<string, int> monthKeys = {{"January", 1}, {"February", 4}, {"March", 4},
                                  {"April", 0}, {"May", 2}, {"June", 5},
                                  {"July", 0}, {"August", 3}, {"September", 6},
                                  {"October", 1}, {"November", 4}, {"December", 6}};

    int day;
    string month;
    int year;
    int result = 0;

    cin >> day >> month >> year;

    int lastTwoDigit = year - (year/100)*100;
    result += lastTwoDigit;
    result += lastTwoDigit/4;
    result += day;
    result += monthKeys[month];
    result -=1; // Because 2004 is in the range of 2000 to 2099, subtract 1 from 37. This yields 36.

    cout << days[result % 7 - 1];

    return 0;
}
