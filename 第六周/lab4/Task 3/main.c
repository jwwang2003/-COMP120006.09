#include<stdio.h>
#include<string.h>

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
  int a, b;
  scanf("%s", cmd);
  if(strcmp(cmd, "exit") != 0) {
    scanf(" %d", &a);

    if(strcmp(cmd, "reverse") != 0) {
    scanf(" %d", &b);
    }
  }

  while(strcmp(cmd, "exit") != 0) {
    a--;
    if(b) b--;

    if(strcmp(cmd, "reverse") == 0) {
      for(int i = 0; i < 10; ++i) printf("%d ", bits[a][i] = !bits[a][i]);
    } else if(strcmp(cmd, "and") == 0) {
      for(int i = 0; i < 10; ++i) printf("%d ", bits[a][i] == bits[b][i]);
    } else if(strcmp(cmd, "or") == 0) {
      for(int i = 0; i < 10; ++i) printf("%d ", bits[a][i] || bits[b][i]);
    } else if(strcmp(cmd, "diff") == 0) {
      for(int i = 0; i < 10; ++i) printf("%d ", bits[a][i] == bits[b][i] ? 1 : 0);
    }
    printf("\n");

    scanf("%s", cmd);
    if(strcmp(cmd, "exit") != 0) {
      scanf(" %d", &a);

      if(strcmp(cmd, "reverse") != 0) {
      scanf(" %d", &b);
      }
    }
  }

  return 0;
}
