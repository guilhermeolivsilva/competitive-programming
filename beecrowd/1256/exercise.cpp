#include <iostream>
#include <string.h>


class Hash {
    private:
        int enderecosTabela;
        std::string *tabela;
    public:
        Hash(int enderecosTabela);
        Hash() = default;
        void insere(int chave);
        int dispersao(int chave);
        void imprime();
};
 
Hash::Hash(int _enderecosTabela) {
    enderecosTabela = _enderecosTabela;
    tabela = new std::string[enderecosTabela];
}
 
void Hash::insere(int chave) {
    int index = dispersao(chave);
    tabela[index] += " -> " + std::to_string(chave);
}


int Hash::dispersao(int chave) {
    return chave % enderecosTabela;
}
 

void Hash::imprime() {
    for (int i = 0; i < enderecosTabela; i++) {
        std::cout << i;
        for (auto chave : tabela[i])
            std::cout << chave;

        std::cout << " -> \\" << std::endl;
    }
}


int main() {
    int testes, enderecosTabela, numChaves, elemento, i;
    Hash *tabelas;

    std::cin >> testes;

    tabelas = new Hash[testes];

    for(i = 0; i < testes; i++) {
        std::cin >> enderecosTabela;
        std::cin >> numChaves;

        tabelas[i] = Hash(enderecosTabela);

        for(int j = 0; j < numChaves; j++) {
            std::cin >> elemento;
            tabelas[i].insere(elemento);
        }
    }

    for(i = 0; i < testes; i++) {
        tabelas[i].imprime();
        if(i < testes - 1)
            std::cout << std::endl;
    }

    return 0;
}