#include<stdio.h>
int main()
{
 int m,n;
 float t,c;
 float a,b,d,e;
 scanf("%d %d %f %f",&m,&n,&t,&c);
 
 a=(t-c)*(t-c)*(m-2)*(n-2)+4*(t-c/2)*(t-c/2)+(t-c)*(t-c/2)*(2*n+2*m-8);
 a=a/(m*n*t*t);
 d=(c/2)*(c/2)-(3.1415926/4)*(c/2)*(c/2);
 d=d*(m-1)*(n-1)*4/(m*n*t*t);
 e=(m-1)*(n-1)*(c/2)*(c/2)*3.1415926/(m*n*t*t);
 b=1-a-d-e;
 printf("Probability of covering 1 block =%f%%\n",100*a);
 printf("Probability of covering 2 block =%f%%\n",100*b);
 printf("Probability of covering 3 block =%f%%\n",100*d);
 printf("Probability of covering 4 block =%f%%\n",100*e);
 return 0;
}