#include <iostream>

using namespace std;

class TipoCelula {
    public:
        TipoCelula();
    private:
        std::string contents;
        TipoCelula *prox;
    friend class PilhaEncadeada;
};

TipoCelula::TipoCelula(){
    contents = "-1";
    prox = NULL;
}

class Pilha {
    public:
        Pilha(){tamanho = 0;};
        int GetTamanho() {return tamanho;};
        bool Vazia() {return tamanho == 0;};
        virtual void Empilha(std::string item) = 0;
        virtual std::string Desempilha() = 0;
        virtual void Limpa() = 0;
    protected:
        int tamanho;
};

class PilhaEncadeada : public Pilha {
    public:
        PilhaEncadeada();
        virtual ~PilhaEncadeada();
        void Empilha(std::string item);
        std::string Desempilha();
        void Limpa();
    private:
        TipoCelula* topo;
};

PilhaEncadeada::PilhaEncadeada() : Pilha() {
    topo = NULL;
}

PilhaEncadeada::~PilhaEncadeada() {
    Limpa();
}

void PilhaEncadeada::Empilha(std::string item){
    TipoCelula *nova;
    nova = new TipoCelula();
    nova->contents = item;
    nova->prox = topo;
    topo = nova;
    tamanho++;
};

std::string PilhaEncadeada::Desempilha(){
    std::string aux;
    TipoCelula *p;

    if(tamanho == 0)
        throw "A pilha está vazia!";

    aux = topo->contents;
    p = topo;
    topo = topo->prox;

    delete p;

    tamanho--;

    return aux;
};

void PilhaEncadeada::Limpa(){
    while(!Vazia())
        Desempilha();
}

int main() {
    std::string input;
    PilhaEncadeada assuntos;
    int assuntosPendentes;

    cin >> input;

    for(std::string::iterator it = input.begin(); it != input.end(); it++) {
        if(*it == '(')
            assuntos.Empilha("1");
        else if(*it == ')' && assuntos.GetTamanho() > 0)
            assuntos.Desempilha();
    }

    assuntosPendentes = assuntos.GetTamanho();

    if(assuntosPendentes) {
        cout << "Ainda temos " << assuntosPendentes << " assunto(s) pendente(s)!" << endl;
    } else {
        cout << "Partiu RU!" << endl;
    }

    return 0;
}