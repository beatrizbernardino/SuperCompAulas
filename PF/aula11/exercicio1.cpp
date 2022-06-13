
#include <iostream>
#include <unistd.h>
#include <omp.h>

using namespace std;

double funcao1() {
    sleep(4);
    return 47;
}

double funcao2() {
    sleep(6);
    return -11.5;
}

int main() {
    double res_func1, res_func2;

    double inicio= omp_get_wtime();

    // res_func1 = funcao1();
    // res_func2 = funcao2();

    #pragma omp parallel
    {
        #pragma omp single
        {
            #pragma omp task
                res_func1 = funcao1();
            #pragma omp task
                res_func2 = funcao2();
        }


    }
    double fim= omp_get_wtime();
    
    

    cout << res_func1 << " " << res_func2 << endl << fim-inicio<<  "\n";
}