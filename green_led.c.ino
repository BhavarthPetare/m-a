#include <msp430.h>

void delay_ms(unsigned int ms) {
  volatile unsigned int i;
  while(ms--) {
    for(i=0; i<1000; i++);
  }
}

int main(){
  WDTCL = WDTPW|WDTHOLD;
  P1DIR |= BIT0 + BIT6;
  P1OUT &= ~(BIT0+BIT6);
  while(1) {
    P1OUT ^= BIT0;
    delay_ms(500);
    P1OUT ^= BIT6;
    delay_ms(500);
  }
  return 0;
}
