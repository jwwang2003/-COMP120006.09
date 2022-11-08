/**
  （求一个整数各位数的和）编写程序，读取一个0和1000之间的整数，并将该整数的各位数字相加。例如：整数是932，各位数字之和为14.
  提示：利用操作符%提取数字，然后使用操作符/移除提取出来的数字。例如：932%10=2，932/10=93 。下面是一个运行示例：
  Enter a number between 0 and 1000: 999 [enter]
  The sun of the digits is 27
 */

#include<stdio.h>

int main() {
  int in;
  scanf("%d", &in);

  int sum = 0;

  do sum += in % 10; while((in /= 10) > 0);

  printf("%d\n", sum);

  return 0;
}