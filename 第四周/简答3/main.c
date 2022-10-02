/*
  （金融应用：酬金）编写一个程序，读取下面的信息，然后输出一个酬金声明：
  雇员姓名（如Smith）
  每周工作小时数（如10小时）
  每小时的酬金（如9.75美元）
  联邦所得税税率（如20%）
  州所得税率（如9%）
  下面是一个运行示例：

  Enter employee’s name: Smith [enter]
  Enter number of hours worked in a week:10 [enter]
  Enter hourly pay rate: 9.75 [enter]
  Enter fedral tax withholding rate:0.20 [enter]  // spelling mistake
  Enter state tax withholding rate: 0.09 [enter]

  Employee Name: Smith
  Hours Worked: 10.0
  Pay Rate: $9.75
  Gross Pay: $97.5
  Deductions: 
    Fedreal Withholding (20.0%): $19.5  // spelling mistake
    State Withholdings (9.0%): $8.77
    Total Deduction: $8.77              // wrong calculation
  Net Pay: $69.22
*/

#include<stdio.h>

int main() {

  char name[50];
  double hours, rate, federalRate, stateRate; // Are hours limited to whole numbers or could have decimals? Otherwise... int hours;

  printf("Enter employee's name: ");
  scanf("%s", name);
  printf("Enter number of hours worked in a week: ");
  scanf("%lf", &hours);
  printf("Enter hourly pay rate: ");
  scanf("%lf", &rate);
  printf("Enter fedral tax withholding rate: ");
  scanf("%lf", &federalRate);
  printf("Enter state tax withholding rate: ");
  scanf("%lf", &stateRate);

  double gross = hours*rate;
  double fedW = gross*federalRate;
  double stateW = gross*stateRate;
  double net = gross - (fedW + stateW);

  printf("Employee Name: %s\n", name);
  printf("Hours Worked: %.1lf\n", hours);
  printf("Pay Rate: $%.2lf\n", rate);
  printf("Gross Pay: $%.2lf\n", gross);
  printf("Deductions:\n");
  printf("\tFederal Withholding (%.1lf%%): $%.2lf\n", federalRate*100.0, fedW);
  printf("\tState Withholding (%.1lf%%): $%.2lf\n", stateRate*100.0, stateW);
  printf("\tTotal Deductions: $%.2lf\n", fedW + stateW);
  printf("Net Pay: $%.2f\n", net);

  return 0;
}