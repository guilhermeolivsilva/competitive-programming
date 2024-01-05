#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int testCases, blocks;

    cin >> testCases;

    for(int i = 0; i < testCases; i++) {
        cin >> blocks;

        cout << static_cast<uint64_t>(pow(2, blocks)/12000)  << " kg" << endl;
    }

    return 0;
}
