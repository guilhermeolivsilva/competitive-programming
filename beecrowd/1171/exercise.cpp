#include <iostream>


void ordena(int *vetor, int numeros) {
    int i, j, idxMin, valorAux;

    for (i = 0; i < numeros - 1; i++) {
        idxMin = i;
        for (j = i + 1 ; j < numeros; j++) {
            if (vetor[j] < vetor[idxMin])
                idxMin = j;
        }
        valorAux = vetor[i];
        vetor[i] = vetor[idxMin];
        vetor[idxMin] = valorAux;
   }
}


int main() {
    int numeros, i, j, aparicoes;

    std::cin >> numeros;

    int vetor[numeros];
    int vetorUnicos[numeros][2];

    for(i = 0; i < numeros; i++) {
        std::cin >> vetor[i];
        vetorUnicos[i][0] = -1;
        vetorUnicos[i][1] = -1;
    }

    ordena(vetor, numeros);

    for(i = 0; i < numeros; i++) {
        aparicoes = 0;
        
        for(j = 0; j < numeros; j++)
            if (vetor[i] == vetor[j])
                aparicoes++;

        vetorUnicos[i][0] = vetor[i];
        vetorUnicos[i][1] = aparicoes;
    }

    for(i = 0; i < numeros; i++) {
        for(j = 0; j < i; j++)
            if(vetorUnicos[i][0] == vetorUnicos[j][0]) {
                vetorUnicos[i][0] = -1;
                break;
            }
    }

    for(i = 0; i < numeros; i++) {
        if(vetorUnicos[i][0] != -1)
            std::cout << vetorUnicos[i][0] << " aparece " << vetorUnicos[i][1] << " vez(es)" << std::endl;
    }

    return 0;
}
