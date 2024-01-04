#include <iostream>

using namespace std;

int gcd(int x, int y) {
    int remainder;

    while(x > 0) {
        remainder = x % y;
        x = y;
        y = remainder;
    }

    return y;
}


int main() {
    int testCases, vicente, ricardo, remaining, result;

    cin >> testCases;

    for(int i = 0; i < testCases; i++) {
        cin >> vicente >> ricardo;

        cout << gcd(ricardo, vicente) << endl;
    }

    return 0;
}