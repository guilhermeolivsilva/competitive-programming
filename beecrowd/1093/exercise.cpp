#include <iomanip>
#include <iostream>
#include <math.h>


using namespace std;


float probVictoryVamp1(int hitsTankedV1, int hitsTankedV2, int at) {
    if(at == 3) return ((float) hitsTankedV1/(hitsTankedV1 + hitsTankedV2));

    float prob = (1.0 - (1.0 - (6 - at) / 6.0)) / (1.0 - (6 - at) / 6.0);

    return (
        (1.0 - pow(prob, hitsTankedV1)) /
        (1.0 - pow(prob, hitsTankedV1 + hitsTankedV2))
    );
}


int main() {
    int ev1, ev2, at, d;
    int hitsTankedV1, hitsTankedV2;
    float prob;

    while(cin >> ev1 >> ev2 >> at >> d) {
        if(!ev1) break;

        hitsTankedV1 = ev1/d + (ev1 % d != 0);
        hitsTankedV2 = ev2/d + (ev2 % d != 0);

        cout << setprecision(1) << fixed << 100 * probVictoryVamp1(hitsTankedV1, hitsTankedV2, at) << endl;
    }

    return 0;
}