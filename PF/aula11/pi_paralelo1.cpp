
#include <iostream>
#include <cmath>
#include <omp.h>
using namespace std;

int main(){

    int N=10000000;

    omp_set_num_threads(2);

    float pi=0;
    int i=0;
    #pragma omp parallel  private(i)
    {
        int id;
        int Nthrds;
        int istart;
        int iend;
    #pragma omp critical
    {
        id= omp_get_thread_num();
        Nthrds= omp_get_num_threads();
        istart= id*N/Nthrds;
        iend= (id+1 ) *N/Nthrds;
    }
    if(id ==Nthrds-1) iend=N;

        for (i=istart; i<iend; i++){
            
            pi+= pow((-1),i)/ (2*i +1 );
        }


    }



    cout<<pi<< endl;

    return 0;
}