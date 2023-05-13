#include <bits/stdc++.h>

using namespace std;

// https://vjudge.net/problem/UVa-146

vector<char> stringToVectorChar(string word) {
    vector<char> letters;

    for (char letter: word){
        letters.push_back(letter);
    }

    return letters;
}


int main() {
    string word;

    getline(cin, word);
    while (word != "#"){
        vector<char> letters = stringToVectorChar(word);

        if(next_permutation(letters.begin(), letters.end())){
            for(char l: letters){
                    cout << l;
            }
            cout << endl;
        }
        else{
            cout << "No Successor" << endl;
        }

        getline(cin, word);
    }

    return 0;
}
