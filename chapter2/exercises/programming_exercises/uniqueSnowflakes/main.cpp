#include <bits/stdc++.h>

// https://vjudge.net/problem/UVA-11572
// Time Limit Exceed

using namespace std;

int solution(vector<long int> snowflakes, int n, set<long int> packaged, int i = 0){
    if(i >= n) {
        return packaged.size();
    }
    else if(packaged.find(snowflakes[i]) != packaged.end()){
        return packaged.size();
    }
    else {
        if(packaged.empty()){
            set<long int> otherPackaged;
            otherPackaged.insert(snowflakes[i]);

            return max(solution(snowflakes, n, packaged, i+1), solution(snowflakes, n, otherPackaged, i+1));
        }
        else{
            packaged.insert(snowflakes[i]);
            return solution(snowflakes, n, packaged, i+1);
        }
    }
}

int main() {
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        vector<long int> snowflakes;

        for (int i = 0; i < n; ++i) {
            long int x;
            cin >> x;
            snowflakes.push_back(x);
        }
        set<long int> packaged;
        cout << solution(snowflakes, n, packaged) << endl;
    }

    return 0;
}
