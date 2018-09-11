
#include <stdio.h>
#include <omp.h>
#pragma omp_set_nested(true)

int main()
{
  int i, j, k;
  int m1[100][100], m2[100][100], mul[100][100];
  //omp_set_num_threads(8);
 
  for (i = 0; i < 100; i++)
    for (j = 0; j < 100; j++)
      m1[i][j]=i+j;
  
  for (i = 0; i < 100; i++)
    for (j = 0; j < 100; j++)
      m2[i][j]=i-j;

  for (i = 0; i < 100; i++)
    for (j = 0; j < 100; j++)
      mul[i][j]=0;

  #pragma omp parallel for collapse(3)
  for (i = 0; i < 100; i++) {
    for (j = 0; j < 100; j++) {
      for (k = 0; k < 100; k++) {
        mul[i][j] += m1[i][k]*m2[k][j];
        printf("\nInside thread %d\n",omp_get_thread_num());
      }
    }
  }

  printf("Product of the matrices:\n");
 
  for (i = 0; i < 100; i++) {
    for (j = 0; j < 100; j++) {
      printf("%d\t", mul[i][j]);
    }
    printf("\n");
  }
  return 0;
}
