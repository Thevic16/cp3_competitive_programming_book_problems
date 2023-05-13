#include <bits/stdc++.h>

#define isOn(S, j) (S & (1 << j))
#define setBit(S, j) (S |= (1 << j))
#define clearBit(S, j) (S &= ~(1 << j))
#define toggleBit(S, j) (S ^= (1 << j))
#define lowBit(S) (S & (-S))
#define setAll(S, n) (S = (1 << n) - 1)

// https://vjudge.net/problem/UVA-11173
using namespace std;

map<int, vector<int>> dp = {{0, {0, 1}}};
int lastgenerate = 0;

vector<int> generateNextGreyCode(vector<int> greyCodes, int n, int i) {
    vector<int> nextGreyCodes;
    copy(greyCodes.begin(), greyCodes.end(), back_inserter(nextGreyCodes));

    for (int j = n-1; j >= 0; --j) {
        nextGreyCodes.push_back(setBit(greyCodes[j], i));
    }

    return nextGreyCodes;
}

vector<int> getGreyCodeByN(int n) {
    if(dp.find(n) != dp.end()) {
        return dp[n];
    }
    else {
        vector<int> result = generateNextGreyCode(dp[lastgenerate], dp[lastgenerate].size(),lastgenerate + 1);
        dp[lastgenerate + 1] = result;
        lastgenerate += 1;

        return getGreyCodeByN(n);
    }
}


int main() {
    int t;

    cin >> t;

    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> result = getGreyCodeByN(n);
        cout << result[k] << endl;
    }

    return 0;
}
