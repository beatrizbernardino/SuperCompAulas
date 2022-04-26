#include<iostream>
#include <omp.h>
// #include<vector>
// #include<algorithm>

using namespace std;


int main(){

    int iam;

    #pragma omp parallel private(iam)
    {
        iam=omp_get_thread_num();
        #pragma omp critical //cada thread executa uma vez
        cout<< "Olá, sou a Thread número "<< iam<< endl;
        
    }
    return 0;
}

// openmp vai criar 4 threads e mais rapido vence. As vezes o processador pode alocar a mesma thread 4 vezes.
// Para evitar isso, tem que usar o private com a omp critical.