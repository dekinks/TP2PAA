#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
    double duracao;
    double pontuacao;
    double proporcao;
}Brinquedo;

bool comparar(Brinquedo posterior, Brinquedo anterior) {
    return posterior.proporcao > anterior.proporcao;
}

int main (int argc, char *argv[]) {
    int numBrinquedos;
    double tempoTotal;
    int resposta = 0;

    while (true) {
        int i = 0;

        cin >> numBrinquedos >> tempoTotal;

        Brinquedo brinquedo[numBrinquedos]; 

        if (numBrinquedos == 0 && tempoTotal == 0)
            break;

        while (i < numBrinquedos) {
            cin >> brinquedo[i].duracao >> brinquedo[i].pontuacao;
            brinquedo[i].proporcao = brinquedo[i].pontuacao / brinquedo[i].duracao;
            i++;
        }

        sort(brinquedo, brinquedo + numBrinquedos, comparar);

        i = 0;
        double pontuacaoTotal = 0;
        double duracaoTotal = 0;

        while (i < numBrinquedos) {
            if (duracaoTotal + brinquedo[i].duracao <= tempoTotal) {
                pontuacaoTotal += brinquedo[i].pontuacao;
                duracaoTotal += brinquedo[i].duracao;
            }
            else {
                i++;
            }
        }
        
        resposta++;
        cout << "Instancia " << resposta << "\n";
        cout << pontuacaoTotal << "\n";
        cout << "\n";
    }
}