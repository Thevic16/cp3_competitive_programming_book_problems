#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

// https://vjudge.net/problem/UVA-10911

using namespace std;

// Shortcuts for "common" data types in contests
typedef long long ll;
// comments that are mixed in with code
typedef pair<int, int> ii;
// are aligned to the right like this
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000
// 1 billion, safer than 2B for Floyd Warshall’s

int N, target;
double dist[20][20]; // 1 << 16 = 2^16, note that max N = 8
map<set<pair<ii, ii>>, int> memo;

double calculateDistance(ii a, ii b){
    return ::hypot(a.first - b.first, a.second - b.second);
}


double dp(vii coordinates, set<pair<ii, ii>> coordinatesPairs) {
    if(coordinates.empty()){
        return 0;
    }
//    else if(memo.count(coordinatesPairs)){
////        cout << "memooo!!!";
//        return memo[coordinatesPairs];
//    }

    double summationDistance = INT_MAX;
    for(int i = 0 ; i < coordinates.size(); i++) {
        for(int j = i+1 ; j < coordinates.size(); j++) {
            if(i != j){
                vii newCoordinates(coordinates.size());
                copy(coordinates.begin(), coordinates.end(), newCoordinates.begin());
                newCoordinates.erase(newCoordinates.begin() + i);
                newCoordinates.erase(newCoordinates.begin() + j);
                double distance = calculateDistance(coordinates[i], coordinates[j]);

                set<pair<ii, ii>> newCoordinatesPairs(coordinatesPairs);
                newCoordinatesPairs.insert(pair(coordinates[i], coordinates[j]));

//                cout << "i: " << i << " j:" << j << " distance:" << distance << "\n";
//                for (auto c: coordinates)
//                    cout << "x:" << c.first << " y:" << c.second  << " ";
//
//                cout << "\n" << "\n";

                summationDistance = min(summationDistance, distance + dp(newCoordinates, newCoordinatesPairs));
            }
        }
    }

    memo[coordinatesPairs] = summationDistance;

    return summationDistance;
}

int main() {
    int i, caseNo = 1;


    while (scanf("%d", &N), N) {
        vii coordinates;
        int x[20], y[20];

        for (i = 0; i < 2 * N; i++)
        {
            scanf("%*s %d %d", &x[i], &y[i]); // ’%*s’ skips names
            coordinates.push_back(pair(x[i], y[i]));
        }

        set<pair<ii, ii>> coordinatesPairs;
        double result = dp(coordinates, coordinatesPairs);
        cout << fixed;
        cout << setprecision(2);
        cout << "Case " << caseNo << ": " << result << "\n";
        caseNo += 1;
    }

    return 0;
}




