#include <iostream>
// https://vjudge.net/problem/UVA-11172

using namespace std;

int main() {
    int t, a, b;
    cin >> t;

    while (t--){
        cin >> a >> b;

        if(a < b){
            cout << "<" << endl;
        }
        else if(a > b){
            cout << ">" << endl;
        }
        else {
            cout << "=" << endl;
        }

    }

    return 0;
}
