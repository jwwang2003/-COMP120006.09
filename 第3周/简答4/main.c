#include <math.h>
#include <stdio.h>

/*
  （计算圆柱体的体积）编写程序，读入圆柱体的半径和高，并使用下列公式计算圆柱的体积：
  面积=半径*半径*pi
  体积=面积*高
*/

int main(void) {
  double radius, height;

  printf("请输入圆柱体的半径：");
  scanf("%lf", &radius);
  printf("高度：");
  scanf("%lf", &height);

  printf("圆柱的体积：%lf 单位^3\n", pow(radius, 2) * M_PI * height);

  return 0;
}