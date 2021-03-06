#include <iostream>
using namespace std;

int maior(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int main (int argc, char *argv[])
{
    int tamanho, indice;
    while (true)
    {
        long bolas[1001][1001];
        long resposta = 0, auxiliar, valorBola;
        
        cin >> tamanho;

        if (tamanho == 0)
            break;
        
        for (int i = 0; i <= tamanho; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                indice = i - j + 1;
                cin >> valorBola;
                bolas[indice][j] = valorBola + bolas[indice][j - 1] + bolas[indice - 1][j] - bolas[indice - 1][j - 1];
                resposta = maior(resposta, bolas[indice][j]); 
            }
        }

        for (int i = 1; i <= tamanho; i++)
        {
            for (int j = tamanho - i + 1; j >= 1; j--)
            {
                auxiliar = bolas[i][j] - bolas[i][j - 1];
                resposta = maior(bolas[i][j] + bolas[i - 1][j + 1], resposta);

                int a = maior(bolas[i - 1][j + 1] + auxiliar, auxiliar);
                int b = maior(bolas[i][j + 1] + auxiliar, bolas[i - 1][j]);

                bolas[i][j] = maior(a, b);
            }
        }

        cout << resposta << endl;
    }
    
    return 0;
}