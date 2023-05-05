#include<stdio.h>
#include<string.h>

int main(void) {
    int hash[100] = { 0 };
    char word[100][7];

    char t[7];

    int count = 0;

    scanf("%6s", t);
    while(strcmp(t, "XXXXXX") != 0) {
        for(int i = 0; i < strlen(t); ++i) {
            hash[count] += t[i];
        }
        strcpy(word[count], t);
        ++count;
        scanf("%6s", t);
    }

    int count2 = 0;
    int inHash[100] = { 0 };
    
    scanf("%6s", t);
    while(strcmp(t, "XXXXXX") != 0) {
        for(int i = 0; i < strlen(t); ++i) {
            inHash[count2] += t[i];
        }
        ++count2;
        scanf("%6s", t);
    }

    for(int i = 0; i < count2; ++i) {
        int flag = 0;
        for(int j = 0; j < count; ++j) {
            if(inHash[i] == hash[j]) {
                printf("%s\n", word[j]);
                flag = 1;
            }
        }
        if(flag == 0) printf("NOT A VALID WORD\n");
        printf("******\n");
    }

    return 0;
}