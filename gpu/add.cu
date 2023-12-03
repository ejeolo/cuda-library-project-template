#include <stdio.h>
#include <cuda_runtime.h>

__global__ void vector_add_kernel(float *A, float *B, float *C, int n)
{
  int i = blockDim.x * blockIdx.x + threadIdx.x;

  if (i < n)
  {
    C[i] = A[i] + B[i] + 0.0f;
  }
}

extern "C"  void  vector_add_gpu(float *A, float *B, float *C, int n)
{
  dim3 grid, block;

  block.x = 256;
  grid.x = (n + block.x - 1) / block.x;
  printf("CUDA kernel launch with %d blocks of %d threads\n", grid.x, block.x);

  vector_add_kernel<<<grid, block>>>(A, B, C, n);
}
