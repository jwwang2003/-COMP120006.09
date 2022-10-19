#include<stdio.h>

int main(void) {
    int n;

    int xpos = 1, ypos = 1;
    scanf("%d", &n);
    printf("当前位置 (%d,%d)\n", xpos, ypos);

    while(xpos != n || ypos != n) {
        char c;
        int dx;
        scanf("\n%c,%d", &c, &dx);

        switch(c) {
            case 'w':
                ypos -= dx;
                break;
            case 's':
                ypos += dx;
                break;
            case 'd':
                xpos += dx;
                break;
            case 'a':
                xpos -= dx;
                break;
            default:
                break;
        }
        
        if(xpos > n) xpos = n;
        if(xpos <= 0) xpos = 1;
        if(ypos > n) ypos = n;
        if(ypos <= 0) ypos = 1;

        printf("当前位置 (%d,%d)\n", xpos, ypos);
    }

    return 0;
}