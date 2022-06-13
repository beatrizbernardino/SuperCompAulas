#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> // std::sort
using namespace std;

struct item
{
    int id;
    double peso;
    double valor;
};
bool mais_caro(item i, item j)
{
    return i.valor > j.valor;
};



int main()
{

    std::vector<item> v;
    int objetos;
    int pesoMax;

    cin >> objetos;
    cin >> pesoMax;

    for (int i = 0; i < objetos; i++)
    {
        item meu_item;
        double peso;
        double valor;

        cin >> peso;
        cin >> valor;

        meu_item.id = i;
        meu_item.peso = peso;
        meu_item.valor = valor;

        v.push_back(meu_item);
    }

    std::sort(v.begin(), v.end(), mais_caro); // invariante: elementos ordenados pelo peso


  
    double peso = 0;
    double valor = 0;
    std::vector<item> resposta;
    int T=0;

    for(int i=0; i<objetos; i++){

        if(peso+v[i].peso<=pesoMax){

            resposta.push_back(v[i]);
            peso+=v[i].peso;
            valor+=v[i].valor;
            T+=1;
        }


    }
    

    cout << peso << ", " << valor << ", " << 0 << endl;

    sort(resposta.begin(), resposta.end(), [](auto &i, auto &j)
         { return i.id < j.id; });

    for (int i = 0; i <T; i++)
    {
        cout << resposta[i].id << ", ";
    }
    return 0;
}