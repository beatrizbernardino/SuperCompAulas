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
    //thrust::device_vector<float> vec_mean(N);
    thrust::device_vector<float> vec_var(N);
    thrust::device_vector<float> vec_sq(N);





    vec_gpu_app=vec_cpu_app;
    vec_gpu_ms=vec_cpu_ms;
    
    thrust::transform(vec_gpu_app.begin(), vec_gpu_app.end(), vec_gpu_ms.begin(), vec_diff.begin(), thrust::minus<float>());
    

    float mean = thrust::reduce(vec_diff.begin(), vec_diff.end())/N;
    //thrust::fill(vec_diff.begin(), vec_diff.end(), mean);

   thrust::transform(vec_diff.begin(), vec_diff.end(), thrust::make_constant_iterator(mean), vec_var.begin(), thrust::minus<float>());

    thrust::transform(vec_var.begin(), vec_var.end(), vec_sq.begin(), thrust::square<float>());
    float var = thrust::reduce(vec_var.begin(), vec_var.end())/N;


    cout<< var<<endl;
  




    return 0;
}
