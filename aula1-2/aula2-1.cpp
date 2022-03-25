#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int x;
    int a = 0;
    double s = 0;
    cout << "Digite um valor: " << endl;
    cin >> x;

    while (a <= x)
    {
        s += 1 / (pow(2, a));
        a++;
    }

    cout << fixed << setprecision(15) << s << endl;
    return 0;
}