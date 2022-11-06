#include<stdio.h>

int main(void) {
    int n;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    char names[50][50];
    int grades[50][2];
    
    for(int i = 0; i < n; ++i) {
        
        printf("Enter the student's name: ");
        scanf("%s", names[i]);
        printf("Enter the student's grade: "); 
        scanf("%d", &grades[i][0]);
        grades[i][1] = i;
    }

    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(grades[i][0] < grades[j][0]) {
                int temp[2];
                temp[0] = grades[j][0];
                temp[1] = grades[j][1];

                grades[j][0] = grades[i][0];
                grades[j][1] = grades[i][1];

                grades[i][0] = temp[0];
                grades[i][1] = temp[1];
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        printf("%s\t%d\n", names[grades[i][1]], grades[i][0]);
    }

    return 0;
}