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
#include <thrust/count.h>
using namespace std;


struct is_pos
{
  __host__ __device__
  bool operator()(const float &x)
  {
    return x > 0;
  }
};
struct is_less_than_zero
{
  __host__ __device__
  bool operator()(int x)
  {
    return x < 0;
  }
};


int main(){
    
    float x;
    thrust::host_vector<float> vec_cpu;

    
    int N=0;
    while (cin >> x) {
       vec_cpu.push_back(x);
       N++;
    }

    thrust::device_vector<float> vec_gpu(N);
    thrust::device_vector<float> vec_gpu_copy(N-1);

    thrust::device_vector<float> ganho_diario(N-1);



    vec_gpu=vec_cpu;
    is_less_than_zero pred;
    
   thrust::copy(vec_gpu.begin()+1, vec_gpu.end(), vec_gpu_copy.begin());
   thrust::transform(vec_gpu_copy.begin(), vec_gpu_copy.end(),vec_gpu.begin(),  ganho_diario.begin(), thrust::minus<float>());
   int result = thrust::count_if(ganho_diario.begin(), ganho_diario.end(), is_pos());
    thrust::replace_if(ganho_diario.begin(), ganho_diario.end(), pred, 0);

  float mean= thrust::reduce(ganho_diario.begin(), ganho_diario.end())/ result;

   cout<<mean<<endl;

  




    return 0;
}
