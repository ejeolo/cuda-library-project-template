#include <stdio.h>
#include <cuda_runtime.h>

#include "inc/add.cuh"

// different name in this level for different typename, as extern "C" can not decorate template function that is in C++;

extern "C"  void  vector_add_gpu_s(float *A, float *B, float *C, int n)
{
  dim3 grid, block;

  block.x = 256;
  grid.x = (n + block.x - 1) / block.x;
  printf("CUDA kernel launch with %d blocks of %d threads\n", grid.x, block.x);

  vector_add_kernel<><<<grid, block>>>(A, B, C, n);
}

extern "C"  void  vector_add_gpu_d(double* A, double* B, double* C, int n)
{
  dim3 grid, block;

  block.x = 256;
  grid.x = (n + block.x - 1) / block.x;
  printf("CUDA kernel launch with %d blocks of %d threads\n", grid.x, block.x);

  vector_add_kernel<><<<grid, block>>>(A, B, C, n);
}
