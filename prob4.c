#include <stdio.h>
#include <stdlib.h>
#include "clock.h"

#define N 64

int src[N][N];
int dst[N][N];

void rotate(int n, int src[n][n], int dst[n][n]) {
  int i,j;
  int a = n-1;
  int b = n-2;
  int c = n-3;
  int d = n-4;
  int e = n-5;
  int f = n-6;
  int g = n-7;
  int h = n-8;

  for(i=0;i<n;i++){
    for(j=0;j<n;j=j+8){
      dst[a-j][i] = src[i][j];
      dst[b-j][i] = src[i][j+1];
      dst[c-j][i] = src[i][j+2];
      dst[d-j][i] = src[i][j+3];
      dst[e-j][i] = src[i][j+4];
      dst[f-j][i] = src[i][j+5];
      dst[g-j][i] = src[i][j+6];
      dst[h-j][i] = src[i][j+7];
    }
  }
}

int main(void){
  FILE *fp;
  char *fname = "prob64no.csv";
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
