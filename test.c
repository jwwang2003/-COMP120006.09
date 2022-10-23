#include<stdio.h>

int main(void) {

    int t[7] = { 1, 2, 3, 4, 4, 5, 5 };

    int c[9999] = { 0 };

    int new[sizeof(t)/sizeof(t[0])];
    int count = 0;

    for(int i = 0; i < sizeof(t)/sizeof(t[0]); ++i) {
        if(c[t[i]]) continue;
        
        new[count] = t[i];
        count++;
        c[t[i]] = 1;
    }

    for(int i = 0; i < count; ++i) {
        printf("%d\n", new[i]);
    }

    return 0;
}