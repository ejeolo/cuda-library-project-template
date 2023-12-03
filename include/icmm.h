
#pragma once
#include<cuda_runtime.h>

void hello_print();
void ic_S_add(float* A, float* B, float *C, int n);
void ic_D_add(double* A, double* B, double* C, int n);

void ic_S_sub(float* A, float* B, float *C, int n);
void ic_D_sub(float* A, float* B, float *C, int n);


