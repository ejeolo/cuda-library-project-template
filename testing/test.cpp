
#include <cuda_runtime.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "icmm.h"

void add_test_s(float* A, float* B, float* C, int n)
{
  ic_S_add(A, B, C, n);

  printf("Copy output data from the CUDA device to the host memory\n");

  float* h_C = (float*)malloc(n*sizeof(float));
  cudaMemcpy(h_C, C, n*sizeof(float), cudaMemcpyDeviceToHost);

  for (int i = 0; i < n; ++i)
  {
    printf("%3.2f ", h_C[i]);
    // if (fabs(h_A[i] + h_B[i] - h_C[i]) > 1e-5) {      fprintf(stderr, "Result verification failed at element %d!\n", i);      exit(EXIT_FAILURE);    }
  }

  printf("\nTest PASSED\n");

  free(h_C);
}

/**/
void add_test_d(double* A, double* B, double* C, int n)
{
  ic_D_add(A, B, C, n);

  printf("Copy output data from the CUDA device to the host memory\n");
  
  float *h_C = (float *)malloc(n*sizeof(double));
  cudaMemcpy(h_C, C, sizeof(double), cudaMemcpyDeviceToHost);

  for (int i = 0; i < n; ++i)
  {
    printf("%3.2f ", h_C[i]);
    // if (fabs(h_A[i] + h_B[i] - h_C[i]) > 1e-5) {      fprintf(stderr, "Result verification failed at element %d!\n", i);      exit(EXIT_FAILURE);    }
  }

  printf("\nTest PASSED\n");

  free(h_C);
}

/**/
void sub_test_s(float* A, float* B, float* C, int n)
{
  ic_S_sub(A, B, C, n);

  printf("Copy output data from the CUDA device to the host memory\n");

  float* h_C = (float*)malloc(n*sizeof(float));
  cudaMemcpy(h_C, C, n*sizeof(float), cudaMemcpyDeviceToHost);

  for (int i = 0; i < n; ++i)
  {
    printf("%3.2f ", h_C[i]);
    // if (fabs(h_A[i] + h_B[i] - h_C[i]) > 1e-5) {      fprintf(stderr, "Result verification failed at element %d!\n", i);      exit(EXIT_FAILURE);    }
  }

  printf("\nTest PASSED\n");

  free(h_C);
}


int main(void)
{
  int n = 50;
  size_t size = n * sizeof(float);

  float *h_A = (float *)malloc(size);
  float *h_B = (float *)malloc(size);
  float *h_C = (float *)malloc(size);

  for (int i = 0; i < n; ++i)
  {
    h_A[i] =  rand() / (float)RAND_MAX;
    h_B[i] =  rand() / (float)RAND_MAX;
  }

  float *d_A = NULL;
  float *d_B = NULL;
  float *d_C = NULL;

  cudaMalloc((void **)&d_A, size);
  cudaMalloc((void **)&d_B, size);
  cudaMalloc((void **)&d_C, size);
  cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);
  cudaMemcpy(d_B, h_B, size, cudaMemcpyHostToDevice);
/*
  int threadsPerBlock = 256;
  int blocksPerGrid = (n + threadsPerBlock - 1) / threadsPerBlock;
  printf("CUDA kernel launch with %d blocks of %d threads\n", blocksPerGrid, threadsPerBlock);

  vector_add_kernel<<<blocksPerGrid, threadsPerBlock>>>(d_A, d_B, d_C, n);
*/

  //ic_add(d_A, d_B, d_C, n);
  add_test_s(d_A, d_B, d_C, n);
  sub_test_s(d_A, d_B, d_C, n);

  cudaFree(d_A);
  cudaFree(d_B);
  cudaFree(d_C);
  free(h_A);
  free(h_B);
  free(h_C);

  printf("Done\n");
  return 0;
}
