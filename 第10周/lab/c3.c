#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main(void) {
    char s[50];
    int ind[50][2];
    memset(ind, -1, 50 * 2 * sizeof (int));

    int i = 0;
    int j = 0;
    ind[j][0] = 0;
    char c = getchar();
    while(c != '\n') {
        if(isalpha(c) == 0 && ind[j][1] == -1) {
            ind[j][1] = i;
        } else if(isalpha(c) == 0) {

        } else {
            if(ind[j][1] != -1) ++j;
            if(ind[j][0] == -1) {
                ind[j][0] = i;
            }
        }
        s[i] = c;
        ++i;
        c = getchar();
    }

    // for(int x = 0; x < i; ++x) {
    //     printf("%c", s[x]);
    // }

    ind[j][1] = i;

    int t = 0;
    int flag = 0;
    for(int x = 0; x < i || t <= j; ++x) {
        
        if(ind[t][0] == x) {
            if(s[x] == 'a' || s[x] == 'e' || s[x] == 'i' || s[x] == 'o' || s[x] == 'u') {
                printf("%c", s[x]);
                flag = 2;
            }
            else {
                printf("");
                flag = 1;
            }
        } else if(ind[t][1] == x + 1) {
            if(flag == 1) {
                flag = 0;
                printf("%cay", s[ind[t][0]]);
            } else if(flag == 2) {
                flag = 0;
                printf("ay");
            }
            ++t;
        }
        else printf("%c", s[x]);
    }

    printf("\n");
    
    return 0;
}