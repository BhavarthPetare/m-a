#include <msp430.h>
#define IR_Sensor BIT0
#define Buzzer BIT6

int main() {
  WDTCTL = WDTPW | WDTHOLD;
  P1DIR &= ~IR_Sensor;
  P1DIR |= Buzzer;
  P1OUT &= ~Buzzer;
  while(1) {
    if((P1IN & IR_Sensor)==0) {
      P1OUT |= Buzzer;
    } else {
      P1OUT &= ~Buzzer;
    }
  }
  return 0;
}
