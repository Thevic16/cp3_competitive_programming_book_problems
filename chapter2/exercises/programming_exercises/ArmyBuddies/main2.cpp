#include <bits/stdc++.h>

using namespace std;

//
// Created by victor on 20/04/23.
//

struct Soldiers {
    int leftMostDead;
    int rightMostDead;
};


Soldiers generateSoldier(int S){
    Soldiers soldiers = *new Soldiers();
    soldiers.leftMostDead = INT_MAX;
    soldiers.rightMostDead = INT_MIN;

    return soldiers;
}

Soldiers updateS(Soldiers soldiers, int L, int R) {
    soldiers.leftMostDead = min(soldiers.leftMostDead, L);
    soldiers.rightMostDead = max(soldiers.rightMostDead, R);

    return soldiers;
}

void printTestCase(Soldiers soldiers, int S){
    if(soldiers.leftMostDead == 1 && soldiers.rightMostDead == S){
        cout << "*" << " " << "*" << endl;
    }
    else if(soldiers.rightMostDead == S){
        cout << soldiers.leftMostDead-1 << " " << "*" << endl;
    }
    else if(soldiers.leftMostDead == 1){
        cout << "*" << " " << soldiers.rightMostDead+1 << endl;
    }
    else {
        cout << soldiers.leftMostDead-1 << " " << soldiers.rightMostDead+1 << endl;
    }

    return;
}


int main() {
    int S, B;

    while(cin >> S >> B){
        if(S == 0 && B == 0){
            return 0;
        }

        // create a pointer to the head node
        Soldiers soldiers = generateSoldier(S);

        for (int i = 0; i < B; ++i) {
            int L, R;
            cin >> L >> R;

            soldiers = updateS(soldiers, L, R);
            printTestCase(soldiers, S);
        }

        cout << "-" << endl;
    }


    return 0;
}
