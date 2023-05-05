#include<stdio.h>

int leapYear(int y) {
    return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) ? 1 : 0;
}

int whatDay(int year, int month) {
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    year -= month < 3;
    return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + 1) % 7;
}

void printMonth(int year, int month) {
    printf("一 二 三 四 五 六 日\n");
    int lim;
    int theDay = whatDay(year, month);

    switch(month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            lim = 31;
            break;
        case 4: case 6: case 9: case 11:
            lim = 30;
            break;
        case 2:
            lim = leapYear(year) ? 29 : 28;
            break;
        default:
            lim = 0;
    }

    int d = 1;
    int flag = 0;
    for(int i = 1; i <= 6 && !flag; ++i) {
        for(int j = 1; j <= 7 && !flag; ++j) { 
            if((i - 1)*7 + j >= theDay) {
                printf("%d  ", d++);
            } else printf("   ");
            if(d > lim) flag = 1;
        }
        printf("\n");
    }
}

int main(void) {

    printMonth(2022, 11);

    return 0;
}