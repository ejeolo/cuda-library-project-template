#pragma once

template<typename T>
__global__ void vector_sub_kernel(T *A, T *B, T *C, int n)
{
  int i = blockDim.x * blockIdx.x + threadIdx.x;

  if (i < n)
  {
    C[i] = A[i] - B[i] + 0.0f;
  }
}


