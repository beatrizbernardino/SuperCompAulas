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

    std::sort(v.begin(), v.end(), mais_caro); // invariante: elementos ordenados pelo peso

    double peso = 0;
    double valor = 0;
    std::vector<int> resposta(pesoMax);
    int T = 0;

    double numero = 0;
    std::default_random_engine generator;
    generator.seed(10);
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    for (int i = 0; i <= objetos; i++)
    {

        if (peso + v[i].peso <= pesoMax)
        {
            resposta[T] = v[i].id;
            peso += v[i].peso;
            valor += v[i].valor;
            T += 1;
            objetos--;
        }

        numero = distribution(generator); // gera número
        if (numero > 0.75 && i < objetos)
        {

            if (peso + v.back().peso <= pesoMax)
            {
                resposta[T] = v.back().id;
                peso += v.back().peso;
                valor += v.back().valor;
                T += 1;

                v.erase(v.end());
                objetos--;
            }
        }
    }

    cout << peso << ", " << valor << ", " << 0 << endl;

    sort(v.begin(), v.end(), [](auto &i, auto &j)
         { return i.id < j.id; });

    for (int i = 0; i <= objetos; i++)
    {
        cout << v[i].id << " ";
    }
    return 0;
}