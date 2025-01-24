#ifndef GRAFO_HPP
#define GRAFO_HPP
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX_VALOR = 9999999;

class Grafo{
private:
    int V;
    vector<vector<int>> matrizAdj;
    vector<string> nomeCidades;

    int getNomeCidade(const string &cidade);
    void permutaRotas(vector<int>& rota, int l, int r, int& menorCusto, vector<int>& melhorRota);

public:
     Grafo(int V);
     void addEstrada(const string &cidade1, const string &cidade2, int distancia);
     void imprimeGrafo();
     pair<int, vector<string>> forcaBruta();
     pair<int, vector<string>> programacaoDinamica();
     pair<int, vector<string>> guloso();
};

#endif //GRAFO_HPP