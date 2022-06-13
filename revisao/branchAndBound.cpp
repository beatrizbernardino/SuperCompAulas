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

double investimentos(int invest_total, vector<lote>acoes, vector<lote>&usados, vector<lote>&melhor){

    double valor = 0.0;
    double investimento = 0.0;
    double sem_i = 0.0, com_i = 0.0;
    vector<lote> acoes2 = acoes;
    double valor_atual = 0.0, valor_melhor = 0.0, bound = 0.0;



    if(acoes.empty() || invest_total == 0){
        return 0;
    }
    else{

        for(auto& el : usados){
            valor_atual += el.retorno;
        }
        for(auto& el : melhor){
            valor_melhor += el.retorno;
        }
        for(auto& el: acoes)
            bound+=el.retorno;

        if (valor_atual+bound<=valor_melhor)  {
           return 0;
           num_bounds++;
        }

   
        if(acoes[0].preco <= invest_total){
            usados.push_back(acoes[0]);
            valor = acoes[0].retorno;
            investimento = acoes[0].preco;
            acoes.erase(acoes.begin());
            com_i = investimentos(invest_total - investimento, acoes, usados, melhor);
        }
        acoes2.erase(acoes2.begin());
        sem_i = investimentos(invest_total, acoes2, usados, melhor);
    

        for(auto& el : usados){
            valor_atual += el.retorno;
        }
        for(auto& el : melhor){
            valor_melhor += el.retorno;
        }
        num_leaf++;
        if(valor_atual > valor_melhor){
            melhor=usados;
            num_copy++;
        }
    }
    usados.clear();
    return max(sem_i, valor + com_i);
    
}



// double investimentos(int total, vector<lote> items){
//     if(items.empty() || total == 0){
//         return 0;
//     }
//     if(items[0].preco > total){
//         items.erase(items.begin());
//         return investimentos(total,items);
//     }    
//     else {
//         double valor = items[0].retorno;
//         double preco = items[0].preco;
       
//         items.erase(items.begin());
//         return max(valor + investimentos(total - preco,items), investimentos(total, items));
//      }
// }

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


    cout << "RESULTADO = " << investimentos(invest, acoes, usado, melhor) << "\n";
    cout << "ELEMENTOS NA MOCHILA = "; 
    for(auto& el: melhor) {
            cout << el.id << " ";
    }
    cout<<"\nnum_leaf = "<<num_leaf<<"\nnum_copy = "<<num_copy<<"\nnum_bounds = "<<num_bounds<<"\n";



    
    return 0;
}