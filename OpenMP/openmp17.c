
#include <stdio.h>
#include <omp.h>

int main()
{
  int i, j, k;
  int m1[100][100], m2[100][100], mul[100][100];
  //omp_set_num_threads(8);
  omp_set_nested(1);
  for (i = 0; i < 100; i++)
    for (j = 0; j < 100; j++)
      m1[i][j]=i+j;
  
  for (i = 0; i < 100; i++)
    for (j = 0; j < 100; j++)
      m2[i][j]=i-j;

  for (i = 0; i < 100; i++)
    for (j = 0; j < 100; j++)
      mul[i][j]=0;

  #pragma omp parallel for 
  for (i = 0; i < 100; i++) {
    #pragma omp parallel for //2nd case
    for (j = 0; j < 100; j++) {
      //#pragma omp parallel for //(3rd case)
      for (k = 0; k < 100; k++) {
        mul[i][j] += m1[i][k]*m2[k][j];
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
