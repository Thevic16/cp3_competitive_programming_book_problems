#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



struct State {
    bool up = true;
    bool right = false;
    bool down = false;
    bool left = false;
    ll  x;
    ll  y;
    ll  value;
    vector<vector<ll >> squareGrid;
};

map<ll, vector<vector<ll>>> dp;

State aux(ll  SZ, State state) {
    if(state.up){
        if(state.x < 0 || state.squareGrid[state.x][state.y] != 0){
            state.x += 1;
            state.y -= 1;
            return state;
        }

        state.squareGrid[state.x][state.y] = state.value;
        state.x -= 1;
        state.value -= 1;
    }
    else if(state.right){
        if(state.y < 0 || state.squareGrid[state.x][state.y] != 0){
            state.x += 1;
            state.y += 1;
            return state;
        }

        state.squareGrid[state.x][state.y] = state.value;
        state.y -= 1;
        state.value -= 1;

    }
    else if(state.down){
        if(state.x == SZ || state.squareGrid[state.x][state.y] != 0){
            state.x -= 1;
            state.y += 1;

            return state;
        }

        state.squareGrid[state.x][state.y] = state.value;
        state.x += 1;
        state.value -= 1;

    }
    else if(state.left){
        if(state.y == SZ || state.squareGrid[state.x][state.y] != 0){
            state.x -= 1;
            state.y -= 1;

            return state;
        }

        state.squareGrid[state.x][state.y] = state.value;
        state.y += 1;
        state.value -= 1;
    }

    return aux(SZ, state);
}

vector<vector<ll>> generateSquareGrid(ll  SZ) {
    vector<vector<ll >> squareGrid(SZ, vector<ll >(SZ));
    State state = State();
    state.x = SZ-1;
    state.y = SZ-1;
    state.value = SZ*SZ;
    state.squareGrid = squareGrid;

    while(state.value != 0){
        if(state.up){
            state = aux(SZ, state);
            state.up = false;
            state.right = true;
        }
        else if(state.right){
            state = aux(SZ, state);
            state.right = false;
            state.down = true;
        }
        else if(state.down){
            state = aux(SZ, state);
            state.down = false;
            state.left = true;

        } else{
            state = aux(SZ, state);
            state.left = false;
            state.up = true;
        }
    }

    return state.squareGrid;

}

pair<ll, ll> findP(vector<vector<ll >> squareGrid, ll P) {
    pair<ll, ll> positionP;
    positionP.first = -1;
    positionP.second =  -1;

    for (ll i = 0; i < squareGrid.size(); ++i) {
        for (ll j = 0; j < squareGrid.size(); ++j) {
            if(squareGrid[i][j] == P){
                positionP.first = i + 1;
                positionP.second = j + 1;
                return positionP;
            }
        }
    }

    return positionP;
}

void printAnswer(pair<ll, ll> positionP){
    cout << "Line = " << positionP.first << ", column = " << positionP.second << "." << endl;
}

int  main() {
    ll SZ, P;

    while (cin >> SZ >> P){
        if(SZ == 0 && P == 0){
            return 0;
        }

        pair<ll, ll> positionP;

        if(dp.find(SZ) != dp.end()){
            positionP = findP(dp[SZ], P);
            printAnswer(positionP);
        }
        else {
            vector<vector<ll >> squareGrid = generateSquareGrid(SZ);
            dp[SZ] = squareGrid;

            positionP = findP(dp[SZ], P);
            printAnswer(positionP);
        }
    }

    return 0;
}
