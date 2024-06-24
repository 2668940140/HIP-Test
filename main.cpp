#include <hip/hip_runtime.h>
#include <iostream>

__global__ void add(int a, int b, int *c)
{
    *c = a + b;
}

int main()
{
    int c;
    int *d_c;
    hipMalloc(&d_c, sizeof(int));

    add<<<1,1>>>(2, 7, d_c);

    hipMemcpy(&c, d_c, sizeof(int), hipMemcpyDeviceToHost);

    std::cout << "2 + 7 = " << c << std::endl;

    hipFree(d_c);
    
    return 0;
}
