#include <iostream>
#include <vector>
#include <bits/stdc++.h>

/*
 * Sample input
 5
16 03 1999 14 03 2001 23 09 2015 08 06 1992 12 12 1965
 * */

using namespace std;

struct Birthday {
    int DD, MM, YYYY;
};

bool compareBirthdayByDD(Birthday i1, Birthday i2)
{
    return (i1.DD < i2.DD);
}

bool compareBirthdayByMM(Birthday i1, Birthday i2)
{
    return (i1.MM < i2.MM);
}

bool compareBirthdayByYYYY(Birthday i1, Birthday i2)
{
    return (i1.YYYY < i2.YYYY);
}

void printBirthdays(vector<Birthday> birthdays) {
    for(Birthday b: birthdays) {
        cout << b.DD << "/" << b.MM << "/" << b.YYYY << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    vector<Birthday> birthdays;

    for (int i = 0; i < n; ++i) {
        Birthday birthday;
        cin >> birthday.DD >> birthday.MM >> birthday.YYYY;
        birthdays.push_back(birthday);
    }

    cout << "BY DAY" << endl;
    sort(birthdays.begin(), birthdays.end(), compareBirthdayByDD);
    printBirthdays(birthdays);

    cout << "BY MONTH" << endl;
    sort(birthdays.begin(), birthdays.end(), compareBirthdayByMM);
    printBirthdays(birthdays);

    cout << "BY YEAR" << endl;
    sort(birthdays.begin(), birthdays.end(), compareBirthdayByYYYY);
    printBirthdays(birthdays);


    return 0;
}
