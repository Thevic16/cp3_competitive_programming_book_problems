#include <bits/stdc++.h>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

/*
4. Given n random integers, print the distinct (unique) integers in sorted order.
*/

int main() {
    int n;
    cin >> n;
    set<int> s;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        s.insert(x);
    }

    vector<int> v;
    for(int i: s){
        v.push_back(i);
    }

    sort(v.begin(), v.end());

    for(int i: v){
        cout << i << " ";
    }

    return 0;
}
