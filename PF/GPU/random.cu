#include<iostream>
#include<cmath>
#include <math.h> 
#include <iomanip>
#include <cstdlib>
#include <chrono>
#include <algorithm>
#include <random>
#include<vector>
#include<thrust/sequence.h>
#include<thrust/device_vector.h>
#include<thrust/host_vector.h>
#include<thrust/fill.h>
#include<thrust/transform.h>
#include<thrust/functional.h>
#include <thrust/extrema.h>
#include <thrust/execution_policy.h>
#include <thrust/count.h>
#include <thrust/random.h>
#include <thrust/iterator/counting_iterator.h>

using namespace std;

struct rng_gpu {
  
    __device__ __host__
    double operator() (const int &i) {
        
      thrust::default_random_engine eng(i*18998);
      thrust::uniform_real_distribution<double> d(25, 41);
      return d(eng);
        //RETORNE AQUI O VALOR ALEATORIO
    }
};



 int main(){
 
    thrust::device_vector<double> d_random(10);
    thrust::transform(thrust::make_counting_iterator<int>(0),
                  thrust::make_counting_iterator<int>(10),
                  d_random.begin(),
                 rng_gpu());

    for(int i=0; i<10; i++){
        
        cout<< d_random[i]<<endl;

    }


     

     return 0;
     
 }