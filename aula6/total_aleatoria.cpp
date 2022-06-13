#include <random>
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

    for (int i = 0; i <= objetos; i++)
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
    std::default_random_engine generator;


    // std::sort(v.begin(), v.end(), mais_caro); // invariante: elementos ordenados pelo peso

    for(int p=0; p<10; p++){

        int objetos_c=objetos;
        vector<item> v_c=v;
        
        double peso = 0;
        double valor = 0;
        std::vector<item> resposta;
        int T=0;
        double numero = 0;
        // generator.seed(10);
        std::uniform_real_distribution<double> distribution(0.0, 1.0);
        

        for(int i=0; i<objetos_c; i++){

            numero = distribution(generator); // gera número

            if(numero>0.5 && i<objetos_c){
                if(peso+v_c[i].peso<=pesoMax){

                    resposta.push_back(v_c[i]);
                    peso+=v_c[i].peso;
                    valor+=v_c[i].valor;
                    T+=1;
                }
        
            }
            
        

            // cout<<numero<<endl<<endl;
            // if (numero > 0.75 && i < objetos_c)
            // {

            //     if (peso + v_c.back().peso <= pesoMax)
            //     {
            //         resposta.push_back(v_c.back());
            //         peso += v_c.back().peso;
            //         valor += v_c.back().valor;
            //         T += 1;

            //         v_c.erase(v_c.end());
            //         objetos_c--;
            //     }
            // }
        }

        cout << peso << ", " << valor << ", " << 0 << endl;

        sort(resposta.begin(), resposta.end(), [](auto &i, auto &j)
            { return i.id < j.id; });

        for (int i = 0; i < T; i++)
        {
            cout << resposta[i].id << " ";
        }

        cout<<endl;
    }
        return 0;
    
}