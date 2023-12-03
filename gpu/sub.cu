#include <stdio.h>
#include <cuda_runtime.h>
#include "inc/sub.cuh"

extern "C"  void  vector_sub_gpu_s(float *A, float *B, float *C, int n)
{
  dim3 grid, block;

  block.x = 256;
  grid.x = (n + block.x - 1) / block.x;
  printf("CUDA kernel launch with %d blocks of %d threads\n", grid.x, block.x);

  vector_sub_kernel<><<<grid, block>>>(A, B, C, n);
}

extern "C"  void  vector_sub_gpu_d(double *A, double *B, double *C, int n)
{
  dim3 grid, block;

  block.x = 256;
  grid.x = (n + block.x - 1) / block.x;
  printf("CUDA kernel launch with %d blocks of %d threads\n", grid.x, block.x);

  vector_sub_kernel<><<<grid, block>>>(A, B, C, n);
}
