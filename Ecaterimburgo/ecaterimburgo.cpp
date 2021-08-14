#include <iostream>
#include <algorithm>
using namespace std;

typedef struct 
{
    double tempo;
    double processamento;
}Produto;

int comparar(const void *a, const void *b) {
    Produto *produtoA = (Produto *)a;
    Produto *produtoB = (Produto *)b;

    return ( produtoB->tempo - produtoA->tempo );
}

int main()
{
    int tarefas;

    while (scanf("%d", &tarefas) != EOF)
    {
        int i = 0;
        int resposta = 0;
        Produto produto[tarefas];

        while (i < tarefas)
        {
            cin >> produto[i].tempo >> produto[i].processamento;
            i++;
        }

        qsort(produto, tarefas, sizeof(Produto), comparar);

        while (i < tarefas)
        {
            if (resposta - produto[i].tempo < 0)
                resposta = produto[i].tempo + produto[i].processamento;
            else
                resposta += produto[i].processamento;

            i++;
        }
        
        cout << resposta << endl;
    }
}