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
    thrust::host_vector<double> vec_cpu;
    thrust::device_vector<double> vec_gpu;

  int N=0;
    while (cin >> x) {
       vec_cpu.push_back(x);
       N++;
    }

    vec_gpu=vec_cpu;
    

    float mean_ten = thrust::reduce(vec_gpu.begin(), vec_gpu.end()) / N;

    float mean_one = thrust::reduce(vec_gpu.begin(), vec_gpu.begin()+365)/ 365;

   thrust::detail::normal_iterator<thrust::device_ptr<double>> max = thrust::max_element(vec_gpu.begin(), vec_gpu.begin()+365);
   thrust::detail::normal_iterator<thrust::device_ptr<double>> min = thrust::min_element(vec_gpu.begin(), vec_gpu.begin()+365);

    cout<< " 10 anos: "<< mean_ten<< endl;
    cout<< " 1 ano: "<< mean_one << endl;
    cout<< " max: "<< *max<< endl;
    cout<< " min: "<< *min<< endl;




    return 0;
}
