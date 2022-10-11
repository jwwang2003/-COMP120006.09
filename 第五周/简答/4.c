#include<stdio.h>
#include<math.h>

int main(void) {
  int a1, a2, a3, a4;
  int c = 0;

  scanf("%d", &a1);
  if(a1) ++c;

  scanf("%d", &a2);
  if(a2) ++c;

  scanf("%d", &a3);
  if(a3) ++c;

  scanf("%d", &a4);
  if(a4) ++c;

  if(c > 3) {
    printf("Contemporary Xu Xiake\n");
  } else if(c == 3) {
    printf("Excellent Traveller\n");
  } else if(c == 2) {
    printf("Young Traveller\n");
  } else if(c == 1) {
    printf("Eye-opener\n");
  } else {
    printf("Typically Otaku\n");
  }

  return 0;
}