#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <math.h>

char nthdigit(int x) {
    while (x > 0) {
        x /= 10;
    }
    return (x % 10);
}

void lazysort(char *c) {
    char temp;
    int i, j;

    for (i = 0; i < 4; i++) {
      for (j = i+1; j < 4; j++) {
         if (c[i] < c[j]) {
            temp = c[i];
            c[i] = c[j];
            c[j] = temp;
         }
      }
   }
}

int getMax(char *c) {
    int sum = 0;
    for(int i = 0; i < 3; ++i) {
        sum += (c[i] - '0') * pow(10, 2-i);
    }
    return sum;
}

int getMin(char *c) {
    int sum = 0;
    for(int i = 2; i >= 0; --i) {
        sum += (c[i] - '0') * pow(10, i);
    }
    return sum;
}

int main(void) {

    char in[4];

    scanf("%s", in);

    int n = 1;
    while(strcmp(in, "495") != 0) {
        for(int i = 0; i < 3; ++i)
            if(!in[i]) in[i] = '0';
        
        lazysort(in);
    
        int max = getMax(in);
        int min = getMin(in);
        sprintf(in, "%d", max - min); 

        printf("%d:%d-%d=%s\n", n, max, min, in);
        ++n;
    }

    return 0;
}