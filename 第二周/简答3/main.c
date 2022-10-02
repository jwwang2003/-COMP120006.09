#include <stdio.h>

/*
  2022-09-21

  编写程序，读入英尺数，将其转化为米数并显示结果（1英尺等于0.305米）
*/

int main() {
  double feet;
  
  printf("请输入英尺数：");
  scanf("%lf", &feet);

  printf("  米：%lf\n", feet*0.305);

  return 0;
}