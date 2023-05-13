#include <bits/stdc++.h>

using namespace std;

// This algorithm is wrong

// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=979
// https://vjudge.net/problem/UVA-10038

string solution(vector<int> sequence, int n, int lastDifference, int i = 1){
    if(i >= n-1 || n == 1){
        return "Jolly";
    }
    else if(abs(sequence[i] - sequence[i+1]) != lastDifference - 1){
        return "Not jolly";
    }
    else {
        return solution(sequence, n, abs(sequence[i] - sequence[i+1]), i + 1);
    }
}

int main() {
    int n;
    while(cin >> n){
        vector<int> sequence;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
           sequence.push_back(x);
        }

        cout << solution(sequence, n, abs(sequence[0] - sequence[1])) << endl;
    }
    return 0;
}
