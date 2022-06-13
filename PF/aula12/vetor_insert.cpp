#include <iostream>
#include <unistd.h>
#include <omp.h>
#include <vector>
int conta_complexa(int i){

    return i*2 + i*3;
}

using namespace std;
int main(){

    float inicio= omp_get_wtime();
    
    int N=10;
    vector<double> vec(N);
    int i;
    // int a=0;


    #pragma omp parallel for default(none) shared(vec) private(i) firstprivate(N) 
   for (i=0; i < N; i++) {
        vec[i]=conta_complexa(i);
        // a= conta_complexa(i);
        // #pragma omp critical
        // {
        //     vec.push_back(a);
        // }
    }


	for (int i = 0; i < N; i++) {
		std::cout << vec[i] << " " ;
	}

	std::cout <<omp_get_wtime()-inicio<<endl;
    return 0;


}
