#include<stdio.h>
#include<string.h>

int main(void) {
    int n;
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

        char *ptr = strtok(webpage[i], delim);

        int j = 0;
        while(ptr != NULL) {
            wordBank[i][j] = ptr;
            ptr = strtok(NULL, delim);
            ++j;
        }
    }

    

    return 0;
}