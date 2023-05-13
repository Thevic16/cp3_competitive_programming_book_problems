#include <bits/stdc++.h>

using namespace std;

// https://vjudge.net/problem/UVA-11933

// 01010101010101010101010101010101 (bin) = 1431655765 (dec)
// 10101010101010101010101010101010 (bin) = 2863311530 (dec)

//                    6 (dec) = 110 (bin)
// And
// 01010101010101010101010101010101 (bin) = 1431655765 (dec)
// 100 - 4 (dec)


//                    6 (dec) = 110 (bin)
// And
// 10101010101010101010101010101010 (bin) = 2863311530 (dec)
// 010 - 2 (dec)

/*
110110101 (bin) = 437 (dec)


 //                       110110101 (bin) = 437 (dec)
// And
// 01010101010101010101010101010101 (bin) = 1431655765 (dec)
// 100010101 - 4 (dec)

 Entendi mal el problema no es asi XD

 La solucion prodria ser la siguiente.
    piendo que tenemos que usar esto:

    7. To get the value of the least significant bit that is on (first from the right),
        use T = (S & (-S)).

*/

pair<long long, long long> solution(long long n, long long a = 0, long long b = 0, bool toggle = true) {
    if(n == 0){
        pair<long long, long long> ab;
        ab.first = a;
        ab.second = b;
        return ab;
    }
    else {
        long long T = (n & (-n));

        if(toggle){
            a = a | T;
        }
        else {
            b = b | T;
        }

        toggle = !toggle;
        n = n ^ T;

        return solution(n, a, b, toggle);
    }
}


int main() {
    long long n;

    while(cin >> n, n != 0){
        pair<long long, long long> ab = solution(n);
        cout << ab.first << " " << ab.second << endl;
    }
    return 0;
}
