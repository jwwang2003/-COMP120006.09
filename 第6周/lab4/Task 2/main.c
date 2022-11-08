#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int checkOverlap(double Xc, double Yc, double R, double X1, double Y1, double X2, double Y2);

int main(void) {

  // simluation?
  time_t T;
  srandom((unsigned) time(&T));

  int m, n, t, c;
  // rows, columns, block size, c size (c < t)
  scanf("%d %d %d %d", &m, &n, &t, &c);

  int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
  int tot = 1000000;

  int bX = n*t, bY = m*t;
  int _bX = (n + 2)*t, _bY = (m + 2)*t;

  for(int i = 0; i < tot; ++i) {
    double randX = (double)random()/(double)(RAND_MAX/(bX + 2*c)) - c;
    double randY = (double)random()/(double)(RAND_MAX/(bY + 2*c)) - c;

    int blockX = floor(randX/(t)) * (t);
    int blockY = floor(randY/(t)) * (t);

    // printf("%lf %lf\n", randX, randY);
    // printf("%d %d\n", blockX, blockY);

    int sum = 0;

    sum++;
    if(checkOverlap(randX, randY, c/2, blockX + t, blockY, blockX + 2*t, blockY + t)) sum++;
    if(checkOverlap(randX, randY, c/2, blockX + t, blockY + t, blockX + 2*t, blockY + 2*t)) sum++;
    if(checkOverlap(randX, randY, c/2, blockX, blockY + t, blockX + t, blockY + 2*t)) sum++;
    if(checkOverlap(randX, randY, c/2, blockX - t, blockY + t, blockX - 2*t, blockY + 2*t)) sum++;
    if(checkOverlap(randX, randY, c/2, blockX - t, blockY, blockX - 2*t, blockY + t)) sum++;
    if(checkOverlap(randX, randY, c/2, blockX - t, blockY - t, blockX - 2*t, blockY - 2*t)) sum++;
    if(checkOverlap(randX, randY, c/2, blockX, blockY - t, blockX - t, blockY - 2*t)) sum++;
    if(checkOverlap(randX, randY, c/2, blockX + t, blockY - t, blockX + 2*t, blockY - 2*t)) sum++;
    if(sum == 1) c1++;
    if(sum == 2) c2++;
    if(sum == 3) c3++;
    if(sum == 4) c4++;

    // printf("%d\n", sum);
  }

  // printf("%d %d %d %d\n", c1, c2, c3, c4);
  // printf("%lf %lf %lf %lf", (c1/(double)tot)*100, (c2/(double)tot)*100, (c3/(double)tot)*100, (c4/(double)tot)*100);

  printf("Probability of covering 1 block = %f%%\n", (c1/(double)tot)*100);
  printf("Probability of covering 2 block = %f%%\n", (c2/(double)tot)*100);
  printf("Probability of covering 3 block = %f%%\n", (c3/(double)tot)*100);
  printf("Probability of covering 4 block = %f%%\n", (c4/(double)tot)*100);

  // for(int i = 0; i < 10000; ++i) {
  //   double randX = (double)rand()/(double)(RAND_MAX/((n + 2) * (t/n))) - 1;
  //   double randY = (double)rand()/(double)(RAND_MAX/((m + 2) * (t/m))) - 1;

  //   int blockX = floor(randX/(t/n)) * (t/n);
  //   int blockY = floor(randY/(t/m)) * (t/m);

  //   printf("%lf %lf\n", randX, randY);

  //   printf("%d %d\n", blockX, blockY);
  //   printf("%d %d\n", blockX + (t/n), blockY);
  //   printf("%d %d\n", blockX + 2*(t/n), blockY + (t/m));

  //   printf("%d\n", checkOverlap(randX, randY, c/2, blockX + (t/n), blockY, blockX + 2*(t/n), blockY + (t/m)));
  //   printf("%d\n", checkOverlap(randX, randY, c/2, blockX + (t/n), blockY, blockX + 2*(t/n), blockY + (t/m)));
  // }

  return 0;
}

int checkOverlap(double Xc, double Yc, double R, double X1, double Y1, double X2, double Y2) {
  int Xn = fmax(X1, fmin(Xc, X2));
  int Yn = fmax(Y1, fmin(Yc, Y2));
  int Dx = Xn - Xc;
  int Dy = Yn - Yc;
  return (Dx * Dx + Dy * Dy) <= R * R;
}