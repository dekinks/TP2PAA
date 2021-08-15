#include <iostream>
using namespace std;

int main (int argc, char *argv[])
{
    int tamanho = 0;
    int bolas[1001][1001];

    while (true)
    {  
        cin >> tamanho;

        if (tamanho == 0)
            break;
        
        for (int i = 0; i < tamanho; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cin >> bolas[i][j];
            }
        }

        
        
    }
}