#include<iostream>
#include <omp.h>
// #include<vector>
// #include<algorithm>

using namespace std;


int main(){

    int a=0;

    #pragma omp parallel
    {
        #pragma omp critical // semaforo de sequencial, uma thread por vez (a= thread 0+ thread 1 +thread 2 +thread 3 = 6)
        a+=omp_get_thread_num();
    }
    cout <<a<<endl;
    return 0;
}