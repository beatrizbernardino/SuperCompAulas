#include<iostream>
#include<cmath>
#include<vector>
#include<thrust/sequence.h>
#include<thrust/device_vector.h>
#include<thrust/host_vector.h>
#include<thrust/fill.h>
#include<thrust/transform.h>
#include<thrust/functional.h>
#include <thrust/extrema.h>
#include <thrust/execution_policy.h>

using namespace std;
int main(){
    
    float x;
    float y;
    thrust::host_vector<float> vec_cpu_app;
    thrust::host_vector<float> vec_cpu_ms;

    
    int N=0;
    while (cin >> x >>y) {
       vec_cpu_app.push_back(x);
       vec_cpu_ms.push_back(y);

       N++;
    }

    thrust::device_vector<float> vec_gpu_app(N);
    thrust::device_vector<float> vec_gpu_ms(N);

    thrust::device_vector<float> vec_diff(N);


    vec_gpu_app=vec_cpu_app;
    vec_gpu_ms=vec_cpu_ms;
    
    thrust::transform(vec_gpu_app.begin(), vec_gpu_app.end(), vec_gpu_ms.begin(), vec_diff.begin(), thrust::minus<float>());
    
    double mean = thrust::reduce(vec_diff.begin(), vec_diff.end())/N;

    cout<< mean<<endl;
  




    return 0;
}
