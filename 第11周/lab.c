#include<stdio.h>
#include<string.h>

#define STRINGSIZE 31
#define MAX 10000

int min(int a, int b) {
    return a < b ? a : b;
}

void exchange(char *c1, char *c2) {
    char temp[STRINGSIZE];
    strcpy(temp, c1);
    memset(c1, 0, STRINGSIZE*(sizeof (char)));
    strcpy(c1, c2);
    memset(c2, 0, STRINGSIZE*(sizeof (char)));
    strcpy(c2, temp);
}

void sort(char trees[MAX][STRINGSIZE], int count[MAX], int size) {
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            for(int c = 0; c < min(strlen(trees[i]), strlen(trees[j])); ++c) {
                if(trees[i][c] < trees[j][c]) {
                    exchange(trees[i], trees[j]);
                    int t = count[i];
                    count[i] = count[j];
                    count[j] = t;
                    break;
                } else if(trees[i][c] == trees[j][c]) {
                    continue;
                } else { break; }
            }
        }
    }
}

int main(void) {
    int tot = 0;
    int counter[MAX] = { 0 };
    char trees[MAX][STRINGSIZE];

    int line = 0;
    int ch = 0;

    char c;
    while(c = getchar()) {
        if(ch == 0 && c == '\n') break;
        if(ch != 0 && c == '\n') {
            int flag = 0;
            for(int i = 0; i < line; ++i) {
                if(strcmp(trees[i], trees[line]) == 0) {
                    memset(trees[line], 0, sizeof trees[0]);
                    counter[i]++;
                    tot++;
                    flag = 1;
                    break;
                }
            }

            if(flag == 0) {
                counter[line] = 1;
                tot++;
                line++;
            }

            ch = 0;
            continue;
        }

        

        trees[line][ch] = c;
        ch++;
    }

    sort(trees, counter, line);

    for(int i = 0; i < line; ++i) {
        printf("%s %lf\n", trees[i], counter[i]/(double)tot*100);
    }

    return 0;
}