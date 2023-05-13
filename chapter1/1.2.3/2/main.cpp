#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

/*
 * 2. Given an integer n (n ≤ 15), print π to n digits after the decimal point (rounded).
(e.g. for n = 2, print 3.14; for n = 4, print 3.1416; for n = 5, prints 3.14159.)
 * */

int main() {
    int n;
    cin >> n;

    cout << setprecision(n+1) << M_PI;

    return 0;
}
