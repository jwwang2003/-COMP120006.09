#include<stdio.h>
#include<math.h>

int main(void) {
    printf("Loan amount: ");
    double loan;
    scanf("%lf", &loan);

    printf("Number of Years: ");
    int years;
    scanf("%d", &years);

    double increment = 1/8.0; // 0.125
    double current = 5.000;

    printf("Interest Rate\tMonthly Payment\tTotal Payment\n");
    while(current <= 8.000) {
        double month = loan * ((current/(100 * 12)) * pow((1 + current/(100 * 12)), 12 * years))/(pow(1 + (current/100)/12, 12 * years) - 1);
        printf("%.3lf%%\t\t%.2lf\t\t%.2lf\n", current, month, month * (12 * years));
        current += increment;
    }
    
    return 0;
}