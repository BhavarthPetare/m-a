#include <msp430.h>

int main() {
  WDTCTL = WDTPW | WDTHOLD;
  P1DIR |= BIT6;
  P1SEL |= BIT6;
  TB0CCR0 = 1000-1;
  TB0CCTL1 = OUTMOD_7;
  TB0CCR1 = 500;
  TB0CTL = TBSSEL_2+MC_1;
  while(1) {
    for(int i=0; i<=1000; i++) {
      TB0CCR1=i;
      __delay_cycles(5000);
    }
    for(int i=1000; i>=0; i--) {
      TB0CCR1=i;
      __delay_cycles(500);
    }
  }
  return 0;
}
