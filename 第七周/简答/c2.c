#include<stdio.h>

int main(void) {
    printf("Loan amount: ");
    double loan;
    scanf("%lf", &loan);

    printf("Number of Years: ");
    int years;
    scanf("%d", &years);

    double increment = 1/8.0; // 0.125
    double current = 5.000;

    while(current >= 8.000) {
        printf("%.3lf%%\t")
    }
    
    return 0;
}