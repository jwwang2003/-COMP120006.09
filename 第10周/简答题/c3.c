#include<stdio.h>

int dp[999999];

int fib(int input) {
    if(dp[input]) return dp[input];
    if(input == 0) return 0;
    if(input == 1) return 1;
    
    return dp[input] = fib(input - 1) + fib(input - 2);
}

int main(void) {

    printf("%d\n", fib(20));

    return 0;
}