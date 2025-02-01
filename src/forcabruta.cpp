#include "../include/grafo.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Recursão para permutar todas as rotas possíveis e calcular os custos
void Grafo::permutaRotas(vector<int>& rota, int l, int r, int& menorCusto, vector<int>& melhorRota){
    if(l == r){
        int custo = 0;
        bool valido = true;

        for(int i = 0; i < V - 1; i++){
            int origem = rota[i];
            int destino = rota[i + 1];

            //Se não houver estrada entre duas cidades, a rota é inválida
            if(matrizAdj[origem][destino] == 0){
                valido = false;
                break;
            }

            custo += matrizAdj[origem][destino];
        }

        //Adiciona o custo da última cidade até a cidade de origem
        if(valido && matrizAdj[rota[V-1]][rota[0]] != MAX_VALOR){
            custo += matrizAdj[rota[V-1]][rota[0]];

            //Atualiza a melhor rota se encontrarmos custo menor
            if(custo < menorCusto){
                menorCusto = custo;
                melhorRota = rota;
            }
        }
        return;
    }

    //Permuta todas as cidades usando backtracking
    for(int i = l; i <= r; i++){
        swap(rota[l], rota[i]);
        permutaRotas(rota, l + 1, r, menorCusto, melhorRota);
        swap(rota[l], rota[i]);
    }
}

//Função para calcular a menor rota usando força bruta
pair<int, vector<string>> Grafo::forcaBruta(){
    vector<int> rota(V);
    vector<int> melhorRota;
    int menorCusto = MAX_VALOR;

    for(int i = 0; i < V; i++){
        rota[i] = i;
    }

    //Calcula todas as permutações possíveis
    permutaRotas(rota, 0, V - 1, menorCusto, melhorRota);

    //Converte os índices das cidades para os nomes das cidades
    vector<string> rotaCidades;
    for(int indice : melhorRota){
        rotaCidades.push_back(nomeCidades[indice]);
    }

    return {menorCusto, rotaCidades};
}