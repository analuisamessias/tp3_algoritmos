#include "../include/grafo.hpp"
#include <vector>

using namespace std;

//Algoritmo guloso de Prim
pair<int,vector<string>> Grafo::guloso(){
    int n = V;
    vector<bool> visitado(n, false);
    vector<int> rota;
    int custo = 0;

    //Começa na cidade inicial
    int atual = 0;
    visitado[atual] = true;
    rota.push_back(atual);
    
    //Escolhe a cidade mais próxima a cada passo
    for(int i = 1; i < n; i++){
        int proxCidade = -1;
        int menorDistancia = MAX_VALOR;

        //Procura a cidade mais próxima ainda não visitada
        for(int j = 0; j < n; j++){
            if(!visitado[j] && matrizAdj[atual][j] < menorDistancia){
                menorDistancia = matrizAdj[atual][j];
                proxCidade = j;
            }
        }

        //Retorna à cidade inicial para fechar o ciclo
        if(proxCidade != -1){
            custo += menorDistancia;
            atual = proxCidade;
            rota.push_back(atual);
            visitado[atual] = true;
        }
    }

    custo += matrizAdj[atual][0];

    //Converte os índices das cidades para os nomes das cidades
    vector<string> rotaCidades;
    for (int indice : rota) {
        rotaCidades.push_back(nomeCidades[indice]);
    }

    return {custo, rotaCidades};
}