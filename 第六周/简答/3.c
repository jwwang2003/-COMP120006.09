#include<stdio.h>
#include<math.h>

int getMode() {
  printf("Enter 0 to convert dollars to RMB and 1 vice versa: ");
  int mode;
  scanf("%d", &mode);
  if(!(mode == 0 || mode == 1)) {
    printf("Incorrect input\n");
    return getMode();
  }
  return mode;
}

int main(void) {
  double exchangeRate;
  double amount;

  printf("Enter the exchange rate from dollars to RMB: ");
  scanf("%lf", &exchangeRate);

  int mode = getMode();

  if(mode == 0) {
    printf("Enter the dollar amount: ");
    double dollar;
    scanf("%lf", &dollar);
    printf("$%.2lf is %.2lf yuan\n", dollar, dollar*exchangeRate);
  } else if(mode == 1) {
    printf("Enter the RMB amount: ");
    double rmb;
    scanf("%lf", &rmb);
    printf("%.2lf yuan is $%.2lf\n", rmb, rmb/exchangeRate);
  }

  return 0;
}