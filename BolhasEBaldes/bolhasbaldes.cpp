#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> lista;
int inversoes = 0;

lista merge (lista esquerda, lista direita) 
{
    lista listaOrdenada;
    int indexA = 0;
    int indexB = 0;
    int a = esquerda.size();
    int b = direita.size();
    
    while (indexA < a && indexB < b) 
    {
        if (esquerda[indexA] < direita[indexB]) 
        {
            listaOrdenada.push_back(esquerda[indexA]);
            indexA++;
        }
        else 
        {
            listaOrdenada.push_back(direita[indexB]);
            indexB++;
            inversoes += esquerda.size() - indexA;
        }
    }

    while (indexA < a) 
    {
        listaOrdenada.push_back(esquerda[indexA]);
        indexA++;
    }

    while (indexB < b) 
    {
        listaOrdenada.push_back(direita[indexB]);
        indexB++;
    }

    return listaOrdenada;
}

lista mergesort (lista listaParaOrdenar, int inicio, int fim) 
{
    lista listaOrdenada;

    int meio = (inicio + fim) / 2;

    if (fim <= inicio + 1)
    {
        listaOrdenada.push_back(listaParaOrdenar[inicio]);
        return listaOrdenada;
    }
    
    lista esquerda = mergesort(listaParaOrdenar, inicio, meio);
    lista direita = mergesort(listaParaOrdenar, meio, fim);
    listaOrdenada = merge (esquerda, direita);

    return listaOrdenada;
}

int main (int argc, char *argv[]) 
{
    int tamanho, tamanhoAux, valor = 1;
    lista listaParaOrdenar;

    while (true) {
        cin >> tamanho;

        listaParaOrdenar.clear();
        tamanhoAux = tamanho;

        if (tamanho == 0) 
            break;

        while (tamanhoAux != 0) 
        {
            cin >> valor;
            listaParaOrdenar.push_back(valor);
            tamanhoAux--;
        }

        mergesort(listaParaOrdenar, 0, tamanho);

        if (inversoes % 2 == 0)
            cout << "Carlos\n";
        else 
            cout << "Marcelo\n";

        inversoes = 0;
    }
}