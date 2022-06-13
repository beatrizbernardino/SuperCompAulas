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
    int operator() ( int i) {
        
      thrust::default_random_engine eng(i*18998);

      thrust::uniform_real_distribution<float> d(0, 1);

      float x= d(eng);
      float y=d(eng);

      if(pow(x,2)+pow(y,2)<=1){
          return 1;
      }else{
          
        return 0;
      }
     
    }
};



 int main(){

    int N=100000000;
    thrust::device_vector<int> d_random(N);

    int sum=thrust::transform_reduce(thrust::make_counting_iterator<int>(0),
                  thrust::make_counting_iterator<int>(N),
                 rng_gpu(), 0.0, thrust::plus<float>());
          
            
  

    float res=  4.0* (sum/ N);

    cout<< fixed<<setprecision(15) <<res<<endl;
            

  


  

     return 0;
     
 }