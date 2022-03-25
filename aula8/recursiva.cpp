#include <random>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> // std::sort




int mochila(int capacidade, vector<item> item, int valor, int n, peso){

    if(item[n].peso>=capacidade){
        return 0;
    }
    if(n<0){
        return 0;
    }

    if(item[n].peso + peso <= capacidade){
            peso += item[n].peso ;
            valor += item[n].valor;
        }

    std::max(mochila(capacidade, (item.remove(n)), valor, n-1, peso), mochila(capacidade, item.remove(n), valor+(item.end()).valor, n-1, peso))

    


}

struct item {
    int id;
    double peso;
    double valor;
};

int main() {
    int n = 0;
    int W = 0;
    vector<item> mochila;
    vector<item> items;
    cin >> n >> W;
    items.reserve(n);

    double peso, valor;

    for(int i = 0; i < n; i++){
        cin >> peso;
        cin >> valor;
        items.push_back({i, peso, valor});
    }

    mochila(W, items, 0, n, 0);