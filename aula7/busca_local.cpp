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
std::vector<item> create_copy(std::vector<item> const &vec)
{
    std::vector<item> v;
    v = vec;

    return v;
}
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

    std::vector<item> v_cp;
    std::vector<item> mochila;

    v_cp = create_copy(v);
    // std::sort(v.begin(), v.end(), mais_caro); // invariante: elementos ordenados pelo peso

    double peso = 0;
    double valor = 0;
    std::vector<int> resposta(pesoMax);
    int T = 0;

    double numero = 0;
    std::default_random_engine generator;
    generator.seed(10);
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    // if (peso + v[i].peso <= pesoMax)
    // {
    //     resposta[T] = v[i].id;
    //     peso += v[i].peso;
    //     valor += v[i].valor;
    //     T += 1;
    //     objetos--;
    // }

    for (int i = 0; i <= objetos; i++)
    {

        numero = distribution(generator); // gera número
        if (numero > 0.5 && i < objetos)
        {
            if (peso + v_cp[i].peso <= pesoMax)
            {
                item meu_item = {};
                resposta[T] = v_cp[i].id;
                peso += v_cp[i].peso;
                valor += v_cp[i].valor;
                T += 1;

                meu_item.id = v_cp[i].id;
                meu_item.peso = v_cp[i].peso;
                meu_item.valor = v_cp[i].valor;

                mochila.push_back(meu_item);

                v_cp.erase(v_cp.begin() + i);
                objetos--;
            }
        }
    }

    cout << peso << ", " << valor << ", " << 0 << endl;

    sort(mochila.begin(), mochila.end(), [](auto &i, auto &j)
         { return i.id < j.id; });

    for (int i = 0; i <= objetos; i++)
    {
        cout << mochila[i].id << " ";
    }
    return 0;
}