#include <stdio.h>
#include <omp.h>
#include <stdlib.h>

void vectorSum(float* a, float*b, float* result, int N) {
  #pragma omp parallel for
  for (int i = 0; i < N; i++) {
    result[i] = a[i] + b[i];
  }
}

void dotProduct(float* a, float*b, int N) {
  float sum = 0.0;
//  #pragma omp parallel for reduction(+:sum)
  for (long i = 0; i < N; i++) {
    printf("thread num: %d\n",0);// omp_get_thread_num());
    sum += a[i] * b[i];
  }
}



void printVector(float* vec, int N) {
  for (int i = 0; i < N; i++) {
    printf("[%d] = %f\n", i, vec[i]);
  }
}

int main() {
  int N = 9000;
  float* a = (float *) malloc(sizeof(float) * N);
  float* result = (float *) malloc(sizeof(float) * N);
srand(0);
  for (int i = 0; i < N; i++) {
    a[i] = rand();
  }
  dotProduct(a, a, N);
  //vectorSum(a, a, result, N);
  //printf("a: \n");
  //printVector(a, N);
  
  //printf("b: \n");
  //printVector(b, N);
  
  //printf("result: \n");
  //printVector(result, N);
  free(a);
  free(result);
  return 0;
}

