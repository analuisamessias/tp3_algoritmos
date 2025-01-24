#include "../include/grafo.hpp"
#include <vector>

using namespace std;

pair<int,vector<string>> Grafo::guloso(){
    int n = V;
    vector<bool> visitado(n, false);
    vector<int> rota;
    int custo = 0;

    int atual = 0;
    visitado[atual] = true;
    rota.push_back(atual);
    
    for(int i = 1; i < n; i++){
        int proxCidade = -1;
        int menorDistancia = MAX_VALOR;

        for(int j = 0; j < n; j++){
            if(!visitado[j] && matrizAdj[atual][j] < menorDistancia){
                menorDistancia = matrizAdj[atual][j];
                proxCidade = j;
            }
        }

        if(proxCidade != -1){
            custo += menorDistancia;
            atual = proxCidade;
            rota.push_back(atual);
            visitado[atual] = true;
        }
    }

    custo += matrizAdj[atual][0];

    vector<string> rotaCidades;
    for (int indice : rota) {
        rotaCidades.push_back(nomeCidades[indice]);
    }

    return {custo, rotaCidades};
}