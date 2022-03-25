#include <iostream>
using namespace std;

int main()
{
    int x;
    cout << "Entre com um número: ";
    cin >> x;
    if (!cin)
    {
        cout << "Você não digitou um numero válido!" << endl;
        return 1;
    }
    int y;
    cout << "Entre com outro numero: ";
    if (!(cin >> y))
    {
        cout << "Você não digitou um número válido" << endl;
        return 1;
    }

    cout << "Você digitou o valor " << x << endl;

    cout << "Digite dois números:" << endl;

    cin >> x >> y;
    cout << "x = " << x << endl
         << "y = " << y << endl;

    return 0;
}