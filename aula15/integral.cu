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


    thrust::device_vector<float> width(11,0.1f);
    thrust::device_vector<float> height(11);
    thrust::device_vector<float> area(11);
    thrust::device_vector<float> accum_areas(11);
    thrust::device_vector<float> x(11);

    

    thrust::sequence(x.begin(), x.end(),0.0f, 0.1f);

    thrust::transform(x.begin(), x.end(), height.begin(), thrust::square<float>());
   
    thrust::transform(width.begin(), width.end(), height.begin(), area.begin(), thrust::multiplies<float>());


    float total_area= thrust::reduce(area.begin(), area.end());

    cout<< total_area <<endl;

    thrust::inclusive_scan(area.begin(), area.end(), accum_areas.begin());
  
    // cout<< accum_areas.end() <<endl;

    return 0;
}