#include "../include/grafo.hpp"
#include <vector>
#include <cmath>

using namespace std;

pair<int, vector<string>> Grafo::programacaoDinamica(){
    int n = V;
    int subconjuntos = 1 << n;

    //Tabelas para armazenar o menor custo e a cidade anterior em cada passo
    vector<vector<int>> dp(subconjuntos, vector<int>(n, MAX_VALOR));
    vector<vector<int>> parent(subconjuntos, vector<int>(n, -1));

    dp[1][0] = 0;

    //Iteração sobre todos os subconjuntos de cidades
    for(int subset = 1; subset < subconjuntos; subset++){
        for(int k = 0; k < n; k++){

            if (!(subset & (1 << k))) continue;

            int subAnterior = subset ^ (1 << k);

                for(int j = 0; j < n; j++){
                //Se `j` não está no subconjunto ou não há aresta entre `j` e `k`, ignoramos
                  if (!(subset & (1 << j)) || matrizAdj[k][j] == MAX_VALOR) continue;

                  int novoCusto = dp[subAnterior][j] + matrizAdj[j][k];
                
                //Se o novo custo é menor que o custo atual, atualizamos
                  if (novoCusto < dp[subset][k]) {
                    dp[subset][k] = novoCusto;
                    parent[subset][k] = j;
                  }
                }
            }
        }

    //Encontrar menor custo para retornar a cidade de origem
    int menorCusto = MAX_VALOR;
    int cidadeFinal = -1;
    for(int i = 1; i < n; i++){
        if (matrizAdj[i][0] == MAX_VALOR) continue;
        int custoAtual = dp[subconjuntos - 1][i] + matrizAdj[i][0];
        if(custoAtual < menorCusto){
            menorCusto = custoAtual;
            cidadeFinal = i;
        }
    }

    //Reconstruir a rota
    vector<int> indiceRota;
    int subset = subconjuntos - 1;
    while(cidadeFinal != 0){
        indiceRota.push_back(cidadeFinal);
        int proximo = cidadeFinal;
        cidadeFinal = parent[subset][cidadeFinal];
        subset ^= (1 << proximo);
    }
    indiceRota.push_back(0);

    //Inverter a rota para verificar se caminho é válido
    for (int i = 0, j = static_cast<int>(indiceRota.size()) - 1; i < j; i++, j--){
        int reverso = indiceRota[i];
        indiceRota[i] = indiceRota[j];
        indiceRota[j] = reverso;
    }

    //Conversão dos índices para os nomes das cidades
    vector<string> rotaCidades;
    for(int indice : indiceRota){
        rotaCidades.push_back(nomeCidades[indice]);
    }

    return {menorCusto, rotaCidades};

}