#include<stdio.h>

int main(void) {
    double initialDeposit;
    double yield;
    int months;

    printf("Enter the initial deposit amount: ");
    scanf("%lf", &initialDeposit);
    printf("Enter annual percentage yield: ");
    scanf("%lf", &yield);
    printf("Enter maturity period (number of months): ");
    scanf("%d", &months);

    printf("Month\tCD Value\n");
    double prev = initialDeposit;
    for(int i = 1; i <= months; ++i) {
        double current = prev + prev * yield / 1200;
        
        printf("%d\t%.2lf\n", i, current);

        prev = current;
    }

    return 0;
}