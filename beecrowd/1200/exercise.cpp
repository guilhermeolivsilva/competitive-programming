#include <iostream>


class TipoNo {
    public:
        TipoNo();
    private:
        char item;
        TipoNo *esq;
        TipoNo *dir;
        friend class ArvoreBinaria;
};

TipoNo::TipoNo() {
    item = '0';
    esq = NULL;
    dir = NULL;
}


class ArvoreBinaria {
    public:
        ArvoreBinaria();
        void Insere(char item);
        void Imprime(std::string modo);
        char Pesquisa(char chave);
        void Remove(char chave);
        void Limpa();
    private:
        void InsereRecursivo(TipoNo* &p, char item);
        char PesquisaRecursivo(TipoNo* p, char chave);
        std::string PreOrdem(TipoNo* p);
        std::string InOrdem(TipoNo* p);
        std::string PosOrdem(TipoNo* p);
        TipoNo *raiz;
};

ArvoreBinaria::ArvoreBinaria() {
    raiz = NULL;
}

void ArvoreBinaria::Insere(char item) {
    InsereRecursivo(raiz, item);
}

void ArvoreBinaria::InsereRecursivo(TipoNo* &p, char item) {
    if(p == NULL) {
        p = new TipoNo();
        p->item = item;
    }
    else {
        if(int(item) < int(p->item))
            InsereRecursivo(p->esq, item);
        else
            InsereRecursivo(p->dir, item);
    }
}

char ArvoreBinaria::Pesquisa(char chave) {
    return PesquisaRecursivo(raiz, chave);
}

char ArvoreBinaria::PesquisaRecursivo(TipoNo *no, char chave) {
    char aux;
    if (no == NULL) {
        aux = '0';
        return aux;
    }

    if (int(chave) < int(no->item))
        return PesquisaRecursivo(no->esq, chave);
    else if (int(chave) > int(no->item))
        return PesquisaRecursivo(no->dir, chave);
    else
        return no->item;
}

void ArvoreBinaria::Imprime(std::string modo) {
    std::string _string;

    if(modo == "PREFIXA")
        _string = PreOrdem(raiz);
    else if(modo == "POSFIXA")
        _string = PosOrdem(raiz);
    else
        _string = InOrdem(raiz);

    _string.pop_back();
    std::cout << _string << std::endl;
}

std::string ArvoreBinaria::PreOrdem(TipoNo *p) {
    std::string _return;
    _return = "";

    if(p != NULL) {
        _return.push_back(p->item);
        _return += " ";
        _return += PreOrdem(p->esq);
        _return += PreOrdem(p->dir);
    }

    return _return;
}

std::string ArvoreBinaria::InOrdem(TipoNo *p) {
    std::string _return;
    _return = "";

    if(p != NULL) {
        _return += InOrdem(p->esq);
        _return.push_back(p->item);
        _return += " ";
        _return += InOrdem(p->dir);
    }

    return _return;
}

std::string ArvoreBinaria::PosOrdem(TipoNo *p) {
    std::string _return;
    _return = "";

    if(p != NULL) {
        _return += PosOrdem(p->esq);
        _return += PosOrdem(p->dir);
        _return.push_back(p->item);
        _return += " ";
    }

    return _return;
}

int main() {
    std::string comando;
    char entrada, resultadoPesquisa;
    ArvoreBinaria arvore = ArvoreBinaria();

    while(std::cin >> comando) {
        if(comando == "I") {
            std::cin >> entrada;
            arvore.Insere(entrada);
        } else if(comando == "P") {
            std::cin >> entrada;
            resultadoPesquisa = arvore.Pesquisa(entrada);
            
            if(resultadoPesquisa != '0')
                std::cout << entrada << " existe" << std::endl;
            else
                std::cout << entrada << " nao existe" << std::endl;
        } else {
            arvore.Imprime(comando);
        }
    }
}
