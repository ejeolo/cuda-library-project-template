#include <stdio.h>
#include <cuda_runtime.h>
#include "gpu/sub.h"
//extern void vector_add_gpu(float *A, float *B, float *C, int n);

void ic_sub(float* A, float* B, float *C, int n)
{
  vector_sub_gpu(A, B, C, n);
}



