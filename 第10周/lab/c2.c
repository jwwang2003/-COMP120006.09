#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char switchToLetter(int num) {
    switch (num) {
    case 10:
        return 'A';
    case 11:
        return 'B';
    case 12:
        return 'C';
    case 13:
        return 'D';
    case 14:
        return 'E';
    case 15:
        return 'F';
    }
}

char *conv(int num) {
    char *ans = malloc(4 * sizeof(char));
    int i = 3;
    while(num) {
        ans[i--] = num % 10 + '0';
        num /= 10;
    }
    return ans;
}

int getSum(char *s, int len) {
    int sum = 0;
    for(int i = 0; i < len; ++i) {
        if(s[i] >= 48 && s[i] <= 57) {
            sum += s[i] - '0';
        } else {
            sum += s[i] - 'a' + 1 + 9;
        }
    }
    return sum;
}



int main(void) {
    for(int i = 2991; i < 9999; ++i) {
        char result[4];
        int t = 0;
        int num = i;
        while (num) {
            int digit = num % 16;
            num = num / 16;
        
            switch (digit)
            {
                case 0: case 1: case 2: case 3: case 4:
                case 5: case 6: case 7: case 8: case 9:
                    result[t] = '0' + digit;
                    break;
                case 10:
                    result[t] = 'a';
                    break;
                case 11:
                    result[t] = 'b';
                    break;
                case 12:
                    result[t] = 'c';
                    break;
                case 13:
                    result[t] = 'd';
                    break;
                case 14:
                    result[t] = 'e';
                    break;
                case 15:
                    result[t] = 'f' ;
                    break;
            }
            ++t;
        }
        
        int hexSum = getSum(result, t);
        
        t = 0;
        num = i;
        while (num) {
            int digit = num % 12;
            num = num / 12;
            switch (digit)
            {
                case 0: case 1: case 2: case 3: case 4:
                case 5: case 6: case 7: case 8: case 9:
                    result[t] = '0' + digit;
                    break;
                case 10:
                    result[t] = 'a';
                    break;
                case 11:
                    result[t] = 'b';
                    break;
                case 12:
                    result[t] = 'c';
                    break;
            }
            ++t;
        }

        int otherSum = getSum(result, t);
        int decSum = getSum(conv(i), 4);

        if(decSum == hexSum && hexSum == otherSum) printf("%d\n", i);
    }
    return 0;
}