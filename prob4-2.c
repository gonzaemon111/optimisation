#include <stdio.h>
#include <stdlib.h>
#include "clock.h"

#define N 2048
#define BLOCK 8

int src[N][N];
int dst[N][N];

void rotate(int n, int src[n][n], int dst[n][n]) {
  int i,j, ii, jj;
  int a = n-1;
  int b = n-2;
  int c = n-3;
  int d = n-4;
  int e = n-5;
  int f = n-6;
  int g = n-7;
  int h = n-8;

  for (i = 0; i <N; i+=BLOCK){
    for(j = 0; j < N; j+=BLOCK){
      for(ii = i; ii < (i + BLOCK); ii++){
        for(jj = j; jj < (j + BLOCK); jj=jj+8){
          dst[a-jj][ii] = src[ii][jj];
          dst[b-jj][ii] = src[ii][jj+1];
          dst[c-jj][ii] = src[ii][jj+2];
          dst[d-jj][ii] = src[ii][jj+3];
          dst[e-jj][ii] = src[ii][jj+4];
          dst[f-jj][ii] = src[ii][jj+5];
          dst[g-jj][ii] = src[ii][jj+6];
          dst[h-jj][ii] = src[ii][jj+7];
        }
      }
    }
  }
}

int main(void){
  FILE *fp;
  char *fname = "prob2048.csv";
  int i;
  double d[11];
  double sum = 0;

  fp = fopen( fname, "w" );
  if( fp == NULL ){
    printf( "%sファイルが開けません¥n", fname );
    return -1;
  }

  for(i=0;i<11;i++){
    start_counter();
    rotate(N, dst, src);
    d[i] = get_counter();
    printf("%lf\n", d[i]/(N*N));
    fprintf( fp, "%d,%lf\n", N,d[i]/(N*N));
    if(i>0){
      sum += d[i]/(N*N);
    }
  }
  fclose( fp );
  printf("\n");
  printf("平均は%lf\n", sum / 10);
  return 0;
}
