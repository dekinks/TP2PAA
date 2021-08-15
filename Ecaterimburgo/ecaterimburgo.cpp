#include <iostream>
#include <algorithm>
using namespace std;

typedef struct
{
    double tempo;
    double processamento;
    double proporcao;
}Produto;

bool comparar (Produto posterior, Produto anterior)
{
    return posterior.tempo < anterior.tempo;
}

int main()
{
    int tarefas;

    while (scanf("%d", &tarefas) != EOF)
    {
        int i = 0;
        int tempo_total = 0;
        Produto produto[tarefas];

        while (i < tarefas)
        {
            cin >> produto[i].tempo >> produto[i].processamento;
            i++;
        }

        sort(produto, produto + tarefas, comparar);
        
        for (int j = 0; j < tarefas; j++)
        {
            if (tempo_total - produto[j].tempo < 0)
                tempo_total = produto[j].tempo + produto[j].processamento;
            else
                tempo_total += produto[j].processamento;
        }

        cout << tempo_total << endl;
    }
}
