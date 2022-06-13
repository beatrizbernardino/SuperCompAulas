#include <iostream>
#include <unistd.h>
#include <omp.h>
#include <vector>
#include <random>


using namespace std;

int main(){

    int inicio= omp_get_wtime();

    float sum=0.0;
    int N= 100000;
    float pi=0;
  
    uniform_real_distribution<double> distribution(0.0, 1.0);
    int i=0;
    double x, y;
    
    #pragma omp parallel for private(i, x, y) reduction(+:sum)
    for(i=0; i<N; i++){
        default_random_engine generator;
        generator.seed(i);

        #pragma omp critical
        {

            x= distribution(generator); // gera número
            y= distribution(generator); // gera número
            //  x e y geram dependencias. 
            // Precisam ser um processo sequencial
        }

        if(pow(x,2) + pow(y,2) <=1){
            sum +=1;
        }





    }
    pi=4*sum/N;
    cout << pi<< endl;
    cout<< omp_get_wtime()-inicio <<endl;


    return 0;
}