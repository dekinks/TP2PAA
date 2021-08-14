#include <iostream>
using namespace std;

int inversoes = 0;

void merge (long int *lista, int inicio, int meio, int fim) {
    
    int a = meio - inicio + 1;
    int b = fim - meio;
    int indexA = 0;
    int indexB = 0;
    int indexFinal = inicio;

    auto *esquerda = new int[a],
         *direita = new int[b];
        
    for (int i = 0; i < a; i++) { 
        esquerda[i] = lista[inicio + i];
    }

    for (int j = 0; j < b; j++) {
        direita[j] = lista[meio + 1 + j];
    }
    
    while (indexA < a && indexB < b) {
        if (esquerda[indexA] <= direita[indexB]) {
            lista[indexFinal] = esquerda[indexA];
            indexA++;
        }
        else {
            lista[indexFinal] = direita[indexB];
            indexB++;
            inversoes += meio - inicio + 1;
        }
        indexFinal++;
    }

    while (indexA < a) {
        lista[indexFinal] = esquerda[indexA];
        indexA++;
        indexFinal++;
    }

    while (indexB < b) {
        lista[indexFinal] = direita[indexB];
        indexB++;
        indexFinal++;
    }
}

void mergesort (long int *lista, int inicio, int fim) {
    if (fim <= inicio)
        return;
    
    int meio = inicio + (fim - inicio) / 2;

    mergesort(lista, inicio, meio);
    mergesort(lista, meio + 1, fim);
    merge (lista, inicio, meio, fim);
}

int main (int argc, char *argv[]) {
    int tamanho, tamanhoAux = 1;
    while (true) {
        cin >> tamanho;
        tamanhoAux = tamanho;
        int i = 0;

        if (tamanho == 0) {
            break;
        }

        long int listaParaOrdenar[tamanho];

        while (tamanhoAux != 0) {
            cin >> listaParaOrdenar[i];
            i++;
            tamanhoAux--;
        }

        mergesort(listaParaOrdenar, 0, tamanho - 1);

        if (inversoes % 2 == 0)
            cout << "Carlos\n";
        else 
            cout << "Marcelo\n";

        inversoes = 0;
    }
}