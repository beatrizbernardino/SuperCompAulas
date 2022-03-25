#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int x;
    vector<int> nums;
    float valor;
    cout << "Digite um valor: " << endl;
    float mi = 0;
    float sigma = 0;

    cin >> x;

    for (int i = 0; i < x; i++)
    {

        cout << "Digite um número:" << endl;
        cin >> valor;
        nums.push_back(valor);
    }
    for (int i = 0; i <= x; i++)
    {

        mi += nums[i];
    }

    mi = mi / nums.size();

    for (int i = 0; i <= int(nums.size()); i++)
    {
        sigma += pow((nums[i] - mi), 2);
    }

    sigma = sigma / nums.size();

    cout << "MU:" << fixed << setprecision(10) << mi << endl;
    cout << "SIGMA:" << fixed << setprecision(10) << sigma << endl;

    return 0;
}