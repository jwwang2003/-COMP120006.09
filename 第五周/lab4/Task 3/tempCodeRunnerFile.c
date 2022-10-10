#include<stdio.h>

int main(void) {
  int bits[11][11];

  for(int i = 0; i < 10; ++i) {
    char buf[11];
    if(i != 9) scanf("%s\n", buf);
    else scanf("%s", buf);
    
    for(int j = 0; j < 10; ++j) {
      bits[i][j] = buf[j] - '0';
    }
  }

  char cmd[50] = "";

  while(cmd != "exit") {
    int a, b;
    scanf("%s %d ", cmd, a);
    if(cmd != "reverse") scanf("%d\n", b);

    switch(cmd) {
      case "reverse":
        for(int i = 0; i < 10; ++i) printf("%d ", bits[a][i] = ~bits[a][i]);
        break;
      default:
        break;
    }
  }

  return 0;
}
