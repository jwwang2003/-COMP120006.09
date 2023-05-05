#include<stdio.h>

int foldTimes(double dis, double thick);

int main(void) {
    float dis, thick;
    scanf("%f %f",&dis,&thick);
    printf("需要折叠%d次",foldTimes(dis,thick));
    return 0;
}

int foldTimes(double dis, double thick) {
    int times = 0;
    double cur = thick/1000000;
    while(cur < dis) {
        cur *= 2;
        ++times;
    }
    return times;
}