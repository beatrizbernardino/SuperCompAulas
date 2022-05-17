#include<iostream>
#include<cmath>
#include<vector>
#include<thrust/sequence.h>
#include<thrust/device_vector.h>
#include<thrust/host_vector.h>
#include<thrust/fill.h>
#include<thrust/transform.h>
#include<thrust/functional.h>


using namespace std;


int main(){


    thrust::device_vector<float> x(11);
    thrust::device_vector<float> var(11);
    thrust::device_vector<float> quad(11);

    thrust::sequence(x.begin(), x.end(), 1.0f);
    float media= thrust::reduce(x.begin(), x.end())/ 11;

    thrust::device_vector<int> mean(media);
  
    thrust::transform(x.begin(), x.end(), mean.begin(), var.begin(),
                  thrust::minus<float>());

    thrust::transform(var.begin(), var.end(), quad.begin(), thrust::square<float>());

    float variancia= thrust::reduce(quad.begin(), quad.end())/ 11;
    cout<< variancia; 

    return 0;
}