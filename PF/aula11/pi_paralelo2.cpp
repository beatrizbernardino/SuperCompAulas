
#include <iostream>
#include <cmath>
#include <omp.h>
using namespace std;

int main(){

    int N=10000000;

 

    float pi=0;

  
    #pragma omp parallel for reduction(+:pi)
    for (int i=0; i<N; i++){
        
        pi+= pow((-1),i)/ (2*i +1 );
    }


    



    cout<<pi<< endl;

    return 0;
}