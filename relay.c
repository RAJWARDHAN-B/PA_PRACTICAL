// WRITE AN EMBEDDED C PROGRAM FOR EXTERNAL INPUT SWITCH PRESS, OUTPUT AS RELAY

#include<xc.h>
#define _XTAL_FREQ 4000000
#define RELAY_PIN LATAbits.LATA4

void __interrupt() extint_isr(void){
    unsigned int i;
    if(INT1IF){
        INT1IF = 0;
        INT1IE = 0;
        RELAY_PIN =~ RELAY_PIN;
        for(int i=0;i<10000;i++);
        INT1IE = 1;
    }
}

void main(void){

    ADCON1 = 0x0F;
    TRISAbits.TRISA4 = 0;
    TRISBbits.TRISB1 = 1;
    RELAY_PIN = 1;

    INT1IE = 1;
    INTEDG1 = 0;
    GIE = 1;

    while(1);

}

// CHATGPT ONE
/*
#include <xc.h>
#define _XTAL_FREQ 4000000
#define RELAY_PIN LATAbits.LATA4

void __interrupt() extint_isr(void) {
    if (INTCON3bits.INT1IF) {    // Correct INT1IF usage inside INTCON3bits
        INTCON3bits.INT1IF = 0;   // Clear interrupt flag
        INTCON3bits.INT1IE = 0;   // Disable external interrupt temporarily
        
        RELAY_PIN = ~RELAY_PIN;   // Toggle Relay output (RA4)

        // Simple software delay to debounce
        for (unsigned int i = 0; i < 10000; i++);

        INTCON3bits.INT1IE = 1;   // Re-enable external interrupt
    }
}

void main(void) {
    ADCON1 = 0x0F;               // Set all ports to digital
    TRISAbits.TRISA4 = 0;         // Set RA4 (Relay) as output
    TRISBbits.TRISB1 = 1;         // Set RB1 (Switch) as input

    RELAY_PIN = 1;                // Initially Relay ON

    INTCON3bits.INT1IE = 1;       // Enable External Interrupt 1
    INTCON2bits.INTEDG1 = 0;      // Interrupt on falling edge (button press)
    INTCONbits.GIE = 1;           // Enable Global Interrupt

    while (1);                    // Infinite loop
}
*/