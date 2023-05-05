#include<stdio.h>
#include<string.h>

int main(void) {
    int n;
    char strings[50][50];

    scanf("%d", &n);

    for(int i = 0; i < n; ++i)  {
        scanf("%s", strings[i]);
    }

    for(int i = 0; i < n; ++i)  {
        printf("String #%d\n", i + 1);
        for(int j = 0; j < strlen(strings[i]); ++j) {
            if(strings[i][j] + 1 > 'Z')
                printf("A");
            else
                printf("%c", strings[i][j] + 1);
        }
        printf("\n");
    }

    return 0;
}