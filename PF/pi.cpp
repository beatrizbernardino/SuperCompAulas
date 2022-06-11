
#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int N=1000000000;

    float pi=0;
    for (int i=0; i<N; i++){
        
        pi+= pow((-1),i)/ (2*N +1 );
    }

    cout<<pi<< endl;

    return 0;
}