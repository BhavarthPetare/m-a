#include <reg51.h>   // For 8051, change header for other MCU

// Define stepper motor pins
sbit IN1 = P2^0;   // Coil A
sbit IN2 = P2^1;   // Coil B
sbit IN3 = P2^2;   // Coil C
sbit IN4 = P2^3;   // Coil D

// Delay function
void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for(i=0; i<ms; i++) {
        for(j=0; j<3000; j++);  // Adjust for your clock frequency
    }
}

// Full-step sequence for clockwise rotation

void main() {
    unsigned char half_step_seq[4] = {0x09, 0xC, 0x6, 0x3};
		unsigned char full_step_seq[8] = {0x08, 0x09, 0x04, 0x0C, 0x02, 0x06, 0x01, 0x03};
    unsigned char i;

    while(1) {
        for(i=0; i<4; i++) {
            P2 = half_step_seq[i];   // Send half-step pattern. for full_step, select full_step_seq and i<8
            delay_ms(20);            // Adjust for speed
        }
    }
}
