#include <stdio.h>

/*
  2022-09-21

  美国人口调查局基于以下假设进行人口估算：
  ·每7秒就有一个人诞生
  ·每13秒就有一个人死亡
  ·每45秒就有一个移民迁入
  编写一个程序，显示未来5年每年人口数。假设当前的人口是312 032
  486，每年有365天。
*/

const int daysInYear = 365;
const int secondsInDay = 86400;
const int secondsInYear = secondsInDay * daysInYear;
const int initial = 312032486;

int main() {
  int yearsToSimulate = 5;

  int population = initial;

  int newBornLeftover = 0;
  int deathLeftover = 0;
  int imigrantLeftover = 0;

  for (int i = 0; i < yearsToSimulate; ++i) {
    int old = population;

    population += (secondsInYear + newBornLeftover) / 7;
    newBornLeftover = secondsInYear % 7;

    population -= (secondsInYear + deathLeftover) / 13;
    deathLeftover = secondsInYear % 13;

    population += (secondsInYear + imigrantLeftover) / 45;
    imigrantLeftover = secondsInYear % 45;

    printf("New population: %d | Delta: %d\n", population, (population - old));
  }

  return 0;
}