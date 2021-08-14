#include <iostream>
#include <cstring>
using namespace std;

int preta = 1;
int branca = 2;
int ambas = 3;

int main() 
{
    int dimensao, pecas;
    int linha, coluna;

    cin >> dimensao >> pecas;

    int pecas_preta = pecas;
    int pecas_branca = pecas;
    int tabuleiro[dimensao][dimensao];
    memset(tabuleiro, 0, sizeof(tabuleiro[0][0]) * dimensao * dimensao);

    for (int i = 0; i < 2 * pecas; i++)
    {
        cin >> linha >> coluna;

        if (i < pecas) 
            tabuleiro[linha-1][coluna-1] = preta;
        else 
            tabuleiro[linha-1][coluna-1] = branca;
    }

    if (dimensao == 2) 
    {
        cout << pecas_preta << " " << pecas_branca << endl;
    }
    else 
    {
        for (int tamanho = dimensao; tamanho > 2 ; tamanho--) 
        {
            for (int i = 0; i < tamanho - 1; i++) 
            {
                for (int j = 0; j < tamanho - 1; j++) 
                {
                    if (tabuleiro[i][j] == ambas || tabuleiro[i+1][j] == ambas || tabuleiro[i][j+1] == ambas || tabuleiro[i+1][j+1] == ambas)
                    { 
                        tabuleiro[i][j] = ambas;
                    }
                    else if (tabuleiro[i][j] == preta) 
                    {
                        if (tabuleiro[i+1][j] != branca && tabuleiro[i][j+1] != branca && tabuleiro[i+1][j+1] != branca) 
                            pecas_preta += 1;
                        else 
                            tabuleiro[i][j] = ambas;
                    }
                    else if (tabuleiro[i][j] == branca) 
                    {
                        if (tabuleiro[i+1][j] != preta && tabuleiro[i][j+1] != preta && tabuleiro[i+1][j+1] != preta) 
                            pecas_branca += 1;
                        else 
                            tabuleiro[i][j] = ambas;
                    }
                    else 
                    {
                        if ((tabuleiro[i+1][j] == preta || tabuleiro[i][j+1] == preta || tabuleiro[i+1][j+1] == preta) &&
                            (tabuleiro[i+1][j] != branca && tabuleiro[i][j+1] != branca && tabuleiro[i+1][j+1] != branca))
                        {
                            tabuleiro[i][j] = preta;
                            pecas_preta += 1;
                        }
                        else if ((tabuleiro[i+1][j] == branca || tabuleiro[i][j+1] == branca || tabuleiro[i+1][j+1] == branca) &&
                                 (tabuleiro[i+1][j] != preta && tabuleiro[i][j+1] != preta && tabuleiro[i+1][j+1] != preta))
                        {
                            tabuleiro[i][j] = branca;
                            pecas_branca += 1;
                        }
                        else if ((tabuleiro[i+1][j] == preta || tabuleiro[i][j+1] == preta || tabuleiro[i+1][j+1] == preta) &&
                                 (tabuleiro[i+1][j] == branca || tabuleiro[i][j+1] == branca || tabuleiro[i+1][j+1] == branca))
                        {
                            tabuleiro[i][j] = ambas;
                        }
                    }
                }
            }
        }

        cout << pecas_preta << " " << pecas_branca << endl;
    }

    return 0;
}