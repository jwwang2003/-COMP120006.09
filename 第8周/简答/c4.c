#include<stdio.h>

int main(void) {
    double rates[] = {0.10, 0.15, 0.25, 0.28, 0.33, 0.35};

    int brackets[][5] = {
        {8350, 33950, 82250, 171550, 372950}, //Single filer
        {16700, 67900, 137050, 20885, 372950}, //Married jointly
        {8350, 33950, 68525 , 10445, 186475}, //Married separately
        {11950, 45500, 117450, 190200, 372950} //Head of household
    };

    printf("1) Single filer\n");
    printf("2) Married jointly\n");
    printf("3) Married separately\n");
    printf("4) Head of household\n");
    printf("Enter your situation(1-4): ");
    
    int selection;
    scanf("%d", &selection);

    printf("Enter your income: ");
    double income;
    scanf("%lf", &income);

    double tax = 0;
    --selection;
    int i = 0;
    while(brackets[selection][i] < income && i <= 5) {
        if(i == 0) {
            if(brackets[selection][0] <= income) tax += brackets[selection][0]*rates[i];
            else tax += income*rates[i];
        } else if(i != 5) {
            if(brackets[selection][i] <= income) {
                tax += (brackets[selection][i] - brackets[selection][i - 1])*rates[i];
            } else {
                tax += income*rates[i];
            }
        } else {
            tax += (income - brackets[selection][i - 1])*rates[i];
        }
        ++i;
    }

    // printf("%.2lf\n", brackets[0][0]*rates[0]+
    //     (brackets[0][1] - brackets[0][0]) * rates[1] +
    //     (brackets[0][2] - brackets[0][1]) * rates[2] +
    //     (brackets[0][3] - brackets[0][2]) * rates[3] +
    //     (brackets[0][4] - brackets[0][3]) * rates[4] +
    //     (400000 - brackets[0][4]) * rates[5]);
    printf("The taxes u owe: %.2lf\n", tax);

    return 0;
}