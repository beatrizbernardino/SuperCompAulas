#include <omp.h>
#include <iostream>
#include <iomanip>
#include <random>
#include <math.h>

using namespace std;

int main(){

    vector<int> x,y,z;

    int N=1000000000;

    for( int i=0; i<N;i++){
        x.push_back(i);
    }

    for(int i=0; i<N; i++){
        y.push_back(-x[i]);
    }


    for(int i=0; i<N; i++){

        z.push_back(2);
    }

    for(int i=0; i<N; i++){

        y[i]=x[i]%z[i];
    }

    return 0;

}