#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> // std::sort
using namespace std;

int num_leaf=0, num_copy=0, num_bounds=0;

struct lote
{
    int id;
    double preco;
    double retorno;
};

bool maior_retorno(lote i, lote j)
{
    return i.retorno > j.retorno;
};



int main(){


    int lotes;
    int invest;
    vector<lote> acoes;
    vector<lote> usado;
    vector<lote> melhor;

    cin>>lotes>>invest;
    acoes.reserve(lotes);
    usado.reserve(lotes);

    for(int i=0; i<lotes; i++){

        double valor_lote;
        double retorno_bruto;
        double imposto;
        lote lote;

        cin>>valor_lote>>retorno_bruto>>imposto;

        lote.id=i;
        lote.preco=valor_lote;
        lote.retorno=retorno_bruto-imposto;


        acoes.push_back(lote);
    }

    std::sort(acoes.begin(), acoes.end(), maior_retorno); 

    double preco = 0;
    double valor = 0;
    std::vector<lote> resposta;
    int T=0;

    for(int i=0; i<lotes; i++){

        if(preco+acoes[i].preco<=invest){

            resposta.push_back(acoes[i]);
            preco+=acoes[i].preco;
            valor+=acoes[i].retorno;
            T+=1;
        }


    }
    

    cout << preco << ", " << valor << ", " << 0 << endl;

    sort(resposta.begin(), resposta.end(), [](auto &i, auto &j)
         { return i.id < j.id; });

    for (int i = 0; i <T; i++)
    {
        cout << resposta[i].id << ", ";
    }


    


    
    return 0;
}