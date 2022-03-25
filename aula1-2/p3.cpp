#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int x;
    int w[] = {1, 2, 3};
    cout << w[0] << endl;
    vector<int> v;
    cout << "Entre quantos números desejar " << endl;

    while (cin >> x)
    {
        v.push_back(x);
    }

    // for e in v
    int a = v[0];
    int b = v[0];

    for (auto &e : v)
    {
        if (e > a)
        {
            a = e;
        }
        if (e < b)
        {
            b = e;
        }
    }
    cout << "Maior número " << a << endl;
    cout << "Menor número " << b << endl;
    return 0;
}

// size_t i = 0;
// size_t greatest_index = 0;
// size_t least_index = 0;

// while (i < v.size())
// {
//     if (v[i] > v[greatest_index])
//     {
//         greatest_index = i;
//     }
//     if (v[i] < v[least_index])
//     {
//         least_index = i;
//     }
//     i += 1;
// }

// if (v.empty())
// {
//     cout << "O vetor é vazio" << endl;
// }
// else
// {
//     cout << "Maior elemento: " << v[greatest_index] << endl;
//     cout << "Menor elemento: " << v[least_index] << endl;
// }

// return 0;
// }