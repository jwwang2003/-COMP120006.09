#include<stdio.h>

int main(void) {
    double m;
    int n;
    scanf("%lf,%d", &m, &n);

    double sum = 0;

    for(int i = 0; i < n; ++i) {
        double temp = m/2.0;
        sum += m + temp;

        m = temp;
    }

    printf("%.1lf,%.1lf\n", m, sum);

    return 0;
}