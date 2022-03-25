#include <iostream>
using namespace std;
int sqr_it(int &x);

int main()
{
    int t = 10;
    cout << sqr_it(t) << endl;
    cout << "Valor atual de T: " << t << endl;
    return 0;
}

//  se nao colocar o & o valor muda apenas temporariamente.
int sqr_it(int &x)
{
    x = x * x;
    return x;
}