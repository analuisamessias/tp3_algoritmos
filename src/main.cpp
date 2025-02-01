#include "../include/grafo.hpp"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    char c;
    int v, e;
    cin >> c;
    cin >> v >> e;

    //Criação do grafo e adição das estradas com pesos
    Grafo grafo(v);

    for(int i = 0; i < e; i++){
        string cidade1, cidade2;
        int distancia;
        cin >> cidade1 >> cidade2 >> distancia;
        grafo.addEstrada(cidade1, cidade2, distancia);
    }

    //Condicionais para escolha do algoritmo
    if(c == 'b'){
        auto parte1 = grafo.forcaBruta();
        cout << parte1.first << endl;
        for(const string& cidade : parte1.second){
            cout << cidade << " ";
        }
        cout << endl;
    } else if(c == 'd'){
        auto parte2 = grafo.programacaoDinamica();
        cout << parte2.first << endl;
        for(const string& cidade : parte2.second){
            cout << cidade << " ";
        }
        cout << endl;
    } else if(c == 'g'){
        auto parte3 = grafo.guloso();
        cout << parte3.first << endl;
        for(const string& cidade : parte3.second){
            cout << cidade << " ";
        }
        cout << endl;
    } else{
        cerr << "Erro: Algoritmo não reconhecido." << endl;
        return 1;
    }

    return 0;
}