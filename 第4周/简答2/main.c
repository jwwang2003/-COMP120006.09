/*
  （一个月的天数）编写一个程序，提示用户输入一个年份，一个月份名称的前三个字母，与一个日期，显示一句话表示今天的日期。下面是一个运行示例：
  Enter a year: 2001 [enter]
  Enter a month: Jan [enter]
  Enter a day: 30[enter]
  Today is 30, Jan, 2001
*/

#include<stdio.h>

int main() {
  int year, day;
  char month[3];

  printf("Enter a year: ");
  scanf("%d", &year);

  printf("Enter a month: ");
  scanf("%3s", month);

  printf("Enter a day: ");
  scanf("%d", &day);

  printf("Today is %d, %s, %d\n", day, month, year);

  return 0;
}