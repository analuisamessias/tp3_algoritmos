#include "../include/grafo.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

Grafo::Grafo(int V) : V(V), matrizAdj(V, vector<int>(MAX_VALOR)){
            for (int i = 0; i < V; i++){
                matrizAdj[i][i] = 0;
            }
     };

int Grafo::getNomeCidade(const string &cidade){
    for(int i = 0; i< nomeCidades.size(); i++){
        if(nomeCidades[i] == cidade){
            return i;
        }
    }
    nomeCidades.push_back(cidade);
    return nomeCidades.size() - 1;
}

void Grafo::addEstrada(const string &cidade1, const string &cidade2, int distancia){
    int u = getNomeCidade(cidade1);
    int w = getNomeCidade(cidade2);

    //Grafo não direcionado, logo origem e destino são iguais
    matrizAdj[u][w] = distancia;
    matrizAdj[w][u] = distancia;
}
