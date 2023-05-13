#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>

using namespace std;

// Structure Node
struct LetterValueStruct {
    double value = 0;
};

double calculateMoneyByLine(map<char, LetterValueStruct> letterValue, string line) {
    double money = 0;
    for(char letter: line){
        money += letterValue[letter].value;
    }
    return money;
}

int main() {
    int t;
    cin >> t;

    while(t--){
        int k;
        cin >> k;
        map<char, LetterValueStruct> letterValue;

        for (int i = 0; i < k; ++i) {
            char letter;
            double value;
            cin >> letter >> value;

            LetterValueStruct letterValueStruct;
            letterValueStruct.value = value / 100;
            letterValue[letter] = letterValueStruct;
        }

        double money = 0;
        long int m;
        cin >> m;

        for (long int i = 0; i < m+1; ++i) {
            string line;
            getline(cin, line);

            money += calculateMoneyByLine(letterValue, line);
        }

        std::cout << std::fixed;
        std::cout << std::setprecision(2);
        cout <<  money << "$" << endl;
    }
    return 0;
}
