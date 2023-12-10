#include <iostream>
#include <string>


using namespace std;


class Pais {
    private:
        string nome;
        int ouro, prata, bronze;
    public:
        Pais() = default;
        Pais(string _nome, int _ouro, int _prata, int _bronze);
        string getNome();
        int getOuro();
        int getPrata();
        int getBronze();
        void printPais();
};


Pais::Pais(string _nome, int _ouro, int _prata, int _bronze) {
    nome = _nome;
    ouro = _ouro;
    prata = _prata;
    bronze = _bronze;
}

string Pais::getNome() {
    return nome;
}


int Pais::getOuro() {
    return ouro;
}


int Pais::getPrata() {
    return prata;
}


int Pais::getBronze() {
    return bronze;
}


void Pais::printPais() {
    cout << getNome() << " ";
    cout << getOuro() << " ";
    cout << getPrata() << " ";
    cout << getBronze();
}


bool comparaPais(Pais& paisA, Pais& paisB) {
    if(paisA.getOuro() > paisB.getOuro()) return true;
    if(paisB.getOuro() > paisA.getOuro()) return false;

    if(paisA.getPrata() > paisB.getPrata()) return true;
    if(paisB.getPrata() > paisA.getPrata()) return false;
    
    if(paisA.getBronze() > paisB.getBronze()) return true;
    if(paisB.getBronze() > paisA.getBronze()) return false;

    return paisA.getNome() < paisB.getNome();
}


void ordena(Pais* paises, int numPaises) {
    int i, j, idxMin;
    Pais paisAux;

    for (i = 0; i < numPaises - 1; i++) {
        idxMin = i;
        for (j = i + 1 ; j < numPaises; j++) {
            if(comparaPais(paises[j], paises[idxMin]))
                idxMin = j;
        }
        paisAux = paises[i];
        paises[i] = paises[idxMin];
        paises[idxMin] = paisAux;
   }
}


int main() {
    int numPaises, counter;
    int _ouro, _prata, _bronze;
    string _nome;

    cin >> numPaises;

    Pais paises[numPaises];

    for(counter = 0; counter < numPaises; counter++) {
        cin >> _nome;
        cin >> _ouro;
        cin >> _prata;
        cin >> _bronze;

        paises[counter] = Pais(_nome, _ouro, _prata, _bronze);
    }

    ordena(paises, numPaises);

    for(counter = 0; counter < numPaises; counter++) {
        paises[counter].printPais();
        cout << endl;
    }

    return 0;
}
