### Thrust


- device_vector (GPU) 
- host_vector (CPU)
- Transform (n->n)
- Reduce (n->1)
- iterators : melhoram a alocação da GPU (constant, counting, zip)
- sequence, fill, prfix sum (inclusive scan): modos de preencher o vetor
- functors: transformações personalizadas
- kernel fusion: otimização de acesso

#### Prefix Sum

#include <thrust/scan.h>

int data[6]= {1,0,2,2,1,3};

Usa inclusive a posição que está 
thrust::inclusive_scan(data, data+6, data); -> data[2]= data[0]+data[1]+data[2]; {1,1,3,5,6,9} 

Só usa as posições anteriores
thrust::exclusive_scan(data, data+6, data); -> data[2]= data[0]+data[1]; {0,1,1,3,5,6}

#### Fusion

```
Transformando
for(int i=0; i<n; i++){
    y[i]= F(x[i])

}

Reduzindo
for(int i=0; i<n; i++){
    sum+= y[i]
}
```

Esses dois fors podem ser otimizados: FUSION

```

for(int i=0; i<N; i++){

    sum+=F(x[i]);
}

Desse modo, o acesso a memória é dimuída.

```

#### Functors + Fusion

essa função pode ser usada com os vetores do thrust
```
struct square 
{
    __host__ __device__ ( indica que pode rodar na cpu e gpu)

    float operator()(float x)
    {
        return x*x;
    }
}
```

**Versão Lenta**
```
    device_vector<float> temp(x.size());
    transform(x.begin(), x.end(), temp.begin(), square());
    sqrt(reduce(temp.begin(), temp.end()))
```

**Versão Rápida**
```
        Kernel Fusion                        Unária          Binária
            ^                                   ^               ^               
            |                                   |               |
    sqrt(transform_reduce(x.begin(), x.end(), square(), 0.0f, plus<float>()))
```


**Exemplo**

    **Sort Functor**


    struct compare
    {
        __host__ __device__
        bool operator()(float a, float b)
        {
            return a<b;
        }
    }

    thrust::sort(vec.begin(), vec.end(), compare());

