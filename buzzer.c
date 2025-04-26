// WRITE AN EMBEDDED C PROGRAM FOR TIMER PROGRAMMING ISR BUZZER ON/OFF

#include <xc.h>
#define _XTAL_FREQ 4000000

void __interrupt() Timer0_ISR(void) {    // <-- Space needed between void and __interrupt
    if (INTCONbits.TMR0IF) {
        INTCONbits.TMR0IF = 0;   // Clear Timer0 Interrupt Flag
        TMR0L = 6;               // Reload Timer0 (adjust as needed)

        PORTB ^= 0x01;            // Toggle RB0 (just for fun maybe)

        LATAbits.LATA5 = ~LATAbits.LATA5;   // Toggle BUZZER pin (RA5)
    }
}

void main(void) {
    TRISAbits.TRISA5 = 0;   // Set RA5 as output
    PORTA = 0x00;           // Clear PORTA

    T0CON = 0b11000111;     // Enable TMR0, 8-bit mode, prescaler 1:256
    TMR0L = 6;              // Preload value (adjust for desired timing)

    INTCONbits.TMR0IE = 1;  // Enable Timer0 interrupt
    INTCONbits.GIE = 1;     // Enable Global interrupt

    while (1);              // Infinite loop
}
