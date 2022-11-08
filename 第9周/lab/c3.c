#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void) {
    int n;
    
    char index[500][100];
    int indexCounter = 0;
    int wordCounter[500] = { 0 };
    int wordPos[500][100][2];

    char webpage[50][500];
    char *wordBank[50][250];

    scanf("%d", &n);
    scanf("\n");

    for(int i = 0; i < n; ++i) {
        fgets(webpage[i], sizeof webpage[i], stdin);
    }

    char serach[2][100];
    scanf("%s %s", serach[0], serach[1]);
    
    for(int i = 0; i < n; ++i) {
        webpage[i][strcspn(webpage[i], "\n")] = 0;
        webpage[i][strcspn(webpage[i], ".")] = 0;
    
        int init_size = strlen(webpage[i]);
	    char delim[] = " ";

        // printf("%s\n", webpage[i]);
        char *ptr = strtok(webpage[i], delim);

        int j = 0;
        while(ptr != NULL) {
            // printf("%s %d %d\n", ptr, i, j);
            int ind = -1;

            for(int z = 0; z < indexCounter; ++z) {
                if(strcmp(ptr, index[z]) == 0) {
                    ind = z;
                }
            }

            if(ind == -1) {
                strcpy(index[indexCounter - 1], ptr);
                ind = indexCounter - 1;
                ++indexCounter;
            }

            wordPos[ind][wordCounter[ind]][0] = i;
            wordPos[ind][wordCounter[ind]][1] = j;
            // printf("%s %d %d\n", ptr, wordPos[ind][wordCounter[ind]][0], wordPos[ind][wordCounter[ind]][1]);
            wordCounter[ind]++;

            ptr = strtok(NULL, delim);

            ++j;
        }
    }

    for(int i = 0; i < indexCounter; ++i) {
        printf("%s ", index[i]);
        for(int j = 0; j < wordCounter[i]; ++j) {
            printf("%d-%d ", wordPos[i][j][0] + 1, wordPos[i][j][1] + 1);
        }
        if(i != indexCounter -1) printf("\n");
    }

    int t1 = 0, t2 = 0;
    
    for(int i = 0; i < indexCounter; ++i) {
        if(strcmp(serach[0], index[i]) == 0) {
            t1 = i;
        }
        else if(strcmp(serach[1], index[i]) == 0) {
            t2 = i;
        }
    }

    int best = 0;
    int diff = 999999999;
    int p1 = 0, p2 = 0;
    while(p1 < wordCounter[t1] && p2 < wordCounter[t2]) {
        int temp = abs(wordPos[t1][p1][1] - wordPos[t2][p2][1]);
        if(diff > temp) {
            diff = temp;
            if(wordPos[t1][p1][0] == wordPos[t2][p2][0]) {
                best = wordPos[t1][p1][0];
            } else if(wordPos[t1][p1][0] > wordPos[t2][p2][0]) {
                best = wordPos[t2][p2][0];
            } else {
                best = wordPos[t1][p1][0];
            }
        }

        if(wordPos[t1][p1][0] == wordPos[t2][p2][0]) {
            ++p1; ++p2;
        } else if(wordPos[t1][p1][0] > wordPos[t2][p2][0]) {
            ++p2;
        } else {
            ++p1;
        }
    }

    printf("%d\n", best + 1);

    return 0;
}