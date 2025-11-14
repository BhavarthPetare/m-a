#include <msp430.h>
#define relay BIT6

int main() {
  WDTCTL = WDTPW | WDTHOLD;
  P1DIR |= relay;
  P1OUT &= ~relay;
  while(1) {
    P1OUT |= relay;
    __delay_cycles(500);
    P1OUT &= ~relay;
    __delay_cycles(500);
  }
}
