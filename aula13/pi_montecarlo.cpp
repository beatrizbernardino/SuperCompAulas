#include <omp.h>
#include <iostream>
#include <iomanip>
#include <random>
#include <math.h>

using namespace std;

int main(){


    int N = 100000;

    double sum=0.0;

    double init_time, final_time;

  
    default_random_engine generator;
    uniform_real_distribution<double> distribution(0.0, 1.0);

    init_time = omp_get_wtime();

    double x=0;
    double y=0;

    #pragma omp parallel for reduction(+:sum) 
    for (int i=0; i < N; i++){

        #pragma omp critical
        double x= distribution(generator); // gera número
        double y= distribution(generator); // gera número

        if (pow(x,2) + pow(y,2) <=1){
            sum++;
        }

    }

    final_time = omp_get_wtime() - init_time;

    

    double result= 4* double(sum /  N);

    cout << fixed << result << " " << final_time;

    
    return 0;


}