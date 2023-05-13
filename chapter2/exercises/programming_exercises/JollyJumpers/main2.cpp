#include <bits/stdc++.h>

using namespace std;

// This algorithm is wrong

// https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=979
// https://vjudge.net/problem/UVA-10038

void generateMask(vector<int> sequence, int n, int mask[3001], int i = 0) {
    if(i >= n-1){
        return;
    }
    else {
        mask[abs(sequence[i] - sequence[i+1])] = 1;
        return generateMask(sequence, n, mask, i + 1);
    }
}

string check(int n, int mask[3001], int i = 1) {
    if(i == n || n == 1){
        return "Jolly";
    }
    else if(mask[i] == 0){
        return "Not jolly";
    }
    else {
        return check(n, mask, i+1);
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

        int mask [3001] = {0};
        generateMask(sequence, n, mask);

        cout << check(n, mask) << endl;
    }
    return 0;
}
