#include <bits/stdc++.h>

using namespace std;

/*
Tener una funcion recursiva que se haga el loco y genere todos los casos posibles
 (se desfase en i o en j del cuadrado peque;o con respecto al grande),
 hasta que me pase en algun caso.

Se me ocurre crear un estructura que indique si tengas varios estados,
 por ejemplo hace match (se cuenta), no hace match (no se cuenta), me pase (no se cuenta)

 Seria hacer otra funcion que rote 90 grados el cuadro peque;o y repetir lo anteior 4 veces.
 */

// https://vjudge.net/problem/UVA-10855

struct State {
    bool starter = false;
    bool match = true;
    bool outbound= false;
};

int N, n;

map<pair<int, int>, int> dp;

State compareSquares(vector<vector<char>> bigSquare, vector<vector<char>> smallSquare, int x, int y) {
    State state = *new State();
    state.starter = true;

    for (int i = x; i < n+x; ++i) {
        for (int j = y; j < n+y; ++j) {
            if(i >= N || j >= N){
                state.match = false;
                state.outbound = true;
                return state;
            }

            if(bigSquare[i][j] != smallSquare[i-x][j-y]){
                state.match = false;
                return state;
            }
        }
    }

    return state;
}

int solution(vector<vector<char>> bigSquare, vector<vector<char>> smallSquare, int x = 0, int y = 0, State state = *new State()) {
    if(state.starter && state.outbound){
        pair<int, int> key;
        key.first = x;
        key.second = y;

        dp[key] = 0;

        return dp[key];
    }
    else if(state.starter && state.match){
        int result = 1 + solution(bigSquare, smallSquare, x + 1, y, compareSquares(bigSquare, smallSquare , x + 1, y))
                     + solution(bigSquare, smallSquare, x , y + 1, compareSquares(bigSquare, smallSquare , x, y + 1));

        pair<int, int> key;
        key.first = x;
        key.second = y;

        dp[key] = result;

        return dp[key];
    }
    else {
        int result = solution(bigSquare, smallSquare, x + 1, y, compareSquares(bigSquare, smallSquare , x + 1, y))
                     + solution(bigSquare, smallSquare, x , y + 1, compareSquares(bigSquare, smallSquare , x, y + 1));

        pair<int, int> key;
        key.first = x;
        key.second = y;
        dp[key] = result;

        return dp[key];
    }
}

vector<vector<char>> rotate90Degrees(vector<vector<char>> smallSquare, int n) {
    vector<vector<char>> rotate(n);

    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            rotate[j].push_back(smallSquare[i][j]);
        }
    }
    return rotate;
}

int main() {

    while(cin >> N >> n){
        if(N == 0 && n == 0){
            return 0;
        }

        vector<vector<char>> bigSquare(N);
        vector<vector<char>> smallSquare(n);


        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                char x;
                cin >> x;
                bigSquare[i].push_back(x);
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                char x;
                cin >> x;
                smallSquare[i].push_back(x);
            }
        }

        int solutions[4];

        for (int i = 0; i < 4; ++i) {
            solutions[i] = solution(bigSquare, smallSquare);

            if(i != 3){
                smallSquare = rotate90Degrees(smallSquare, n);
            }
        }

        cout << solutions[0] << " " << solutions[1] << " " << solutions[2] << " " << solutions[3] << endl;
        dp.clear();
    }


    return 0;
}
