#include <stdio.h>
#include <cuda_runtime.h>
#include "gpu/add.h"
//extern void vector_add_gpu(float *A, float *B, float *C, int n);

void hello_print()
{
  printf("hello world!\n");
}

void ic_add(float* A, float* B, float *C, int n)
{
  vector_add_gpu(A, B, C, n);
}


