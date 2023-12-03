#include <stdio.h>
#include <cuda_runtime.h>

#include "gpu/sub.h"
//extern void vector_add_gpu(float *A, float *B, float *C, int n);
void ic_S_sub(float* A, float* B, float *C, int n)
{
  vector_sub_gpu_s(A, B, C, n);
}

void ic_D_sub(double* A, double* B, double *C, int n)
{
  vector_sub_gpu_d(A, B, C, n);
}


