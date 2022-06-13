
#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int N=10000;

    float pi=0;
    for (int i=0; i<N; i++){
        
        pi+= pow((-1),i)/ (2*i +1 );
    }

    cout<<pi<< endl;

    return 0;
}