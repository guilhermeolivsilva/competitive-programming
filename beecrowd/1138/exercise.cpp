#include <iostream>

using namespace std;

int solve(int binding, int digitReference) {
    int tens, result, l, unit, remainder;
    tens = 1;
    result = 0;
    l = 0;
    unit = 0;

    while(binding > 0) {
        remainder = binding % 10;
        binding /= 10;

        result += remainder * unit * tens / 10;
        unit++;

        if(remainder > digitReference) result += tens;
        if (remainder == digitReference) result += l + 1;

        l += tens * remainder;
        tens *= 10;
    }

    if(!digitReference) result -= (tens - 1) / 9;

    return result;
}

int main() {
    int left, right;

    while(cin >> left >> right) {
        if(!left) break;

        for (int i = 0; i < 10; ++i) {
            if(i != 9) cout << solve(right, i) - solve(left - 1, i) << " ";
            else cout << solve(right, i) - solve(left - 1, i);
        }

        cout << endl;
    }

    return 0;
}

