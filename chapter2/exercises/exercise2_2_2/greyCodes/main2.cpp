//
// Created by victor on 14/04/23.
//
#include <bits/stdc++.h>

// https://vjudge.net/problem/UVA-11173
using namespace std;


int main() {
    int t;

    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;
        cout << ((k >> 1)^k) << endl;
    }

    return 0;
}

/*
8*. Let’s reverse the UVa 11173 problem above. Given a gray code, find its position k
using bit manipulation.

 I don't have idea

 100

010
100
110

110 - 6
011
100 - 4

111 - 7
011
101 - 5

001 - 1
000
001 - 1

011 - 3
001
010 - 2
*/