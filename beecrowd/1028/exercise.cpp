#include <iostream>

using namespace std;

int main() {
    int testCases, vicente, ricardo, remaining, result;

    cin >> testCases;

    for(int i = 0; i < testCases; i++) {
        cin >> vicente >> ricardo;

        while(vicente > 0) {
            remaining = ricardo % vicente;
            ricardo = vicente;
            vicente = remaining;
            result = ricardo;
        }

        cout << result << endl;
    }

    return 0;
}