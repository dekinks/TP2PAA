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
        int bolas[1001][1001];
        int resposta = 0, auxiliar, valorBola;
        
        cin >> tamanho;

        if (tamanho == 0)
            break;
        
        for (int i = 1; i <= tamanho; i++)
        {
            int k = tamanho - i + 2;
            bolas[i][k] = 0;
            
            for (int j = 1; j <= i; j++)
            {
                cin >> bolas[i][j];
            }
        }
        
        for (int i = 1; i <= tamanho; i++)
        {
            int l = i;
            for (int j = 1; j <= i; j++)
            {
                indice = l;
                bolas[indice][j] = bolas[i][j] + bolas[indice][j - 1] + bolas[indice - 1][j] - bolas[indice - 1][j - 1];
                resposta = maior(resposta, bolas[indice][j]);
                
                l--;
            }
        }

        for (int i = 1; i <= tamanho; i++)
        {
            int m = tamanho - i + 1;
            for (int j = m; j >= 1; j--)
            {
                resposta = maior(bolas[i][j] + bolas[i - 1][j + 1], resposta);
                
                auxiliar = bolas[i][j] - bolas[i][j - 1];       
                int a = maior(bolas[i - 1][j + 1] + auxiliar, auxiliar);
                int b = maior(bolas[i][j + 1] + auxiliar, bolas[i - 1][j]);

                bolas[i][j] = maior(a, b);
            }
        }

        cout << resposta << endl;
    }
    
    return 0;
}