#include <iostream>
#include <iomanip>
 
using namespace std;
 
int main() {
    int pessoas, doses, idxVencedor;
    float garrafa, cuia;
    
    cin >> pessoas;
    cin >> garrafa;
    cin >> cuia;
    doses = 0;
    
    std::string nomes[pessoas];
    
    for(int i=0; i<pessoas; i++) {
        cin >> nomes[i];
    }
    
    while(garrafa > cuia) {
        garrafa -= cuia;
        doses++;
    }
    
    idxVencedor = doses % pessoas;
    
    cout << nomes[idxVencedor] << " " << std::setprecision(1) << garrafa << endl;
 
    return 0;
}