// WRITE AN EMBEDDED C MENU DRIVEN PROGRAM BY USING INPUT OF MENU CHOICE AS DIGITAL PINS FOR:
//     i) MULTIPLY 8 BIT BY 8 BIT NUMBER
//     ii) DIVIDE 8 BIT BY 8 BIT NUMBER
// (SHOW THE OUTPUT IN THE SIMULATOR)


// IF YOU WANT TO SIMULATE THE PRESSING OF BUTTONS

#include <xc.h>
#define _XTAL_FREQ 4000000

int a=8,b=4,c;

int ch=1;

void main(void){
    TRISA = 0xFF;  // PORTA as Input (even if we simulate)
    TRISD = 0x00;  // PORTD as Output
    PORTD = 0x00;

    // IF WE HAVE TO TAKE INPUT FROM THE USER
    // TRISB = 0xFF;
    // TRISC = 0xFF;
    // LATB = 8;
    // LATC = 4;
    // a = LATB;
    // b = LATC;

    // Simulate digital inputs
    LATAbits.LATA0 = 1;  // Simulate pressing button on RA0
    LATAbits.LATA1 = 0;  // No button press on RA1

    PORTAbits.RA0 == 1;

    if (PORTAbits.RA0 == 1) {
        ch = 1;  // Multiply
    } 
    else if (PORTAbits.RA1 == 1) {
        ch = 2;  // Divide
    } 
    else {
        ch = 0;
    }

    switch(ch){
        case 1:
            c=a*b;
            break;
        case 2:
            c=a/b;
            break;
        default:
            c=0;
            break;
    }
    PORTD=c;
    while(1);
}




// THIS ALSO CORRECT 

/*

#include <xc.h>
#include <stdio.h>

// Function to multiply two numbers and display result on PORTD
void multiply(int n1, int n2){
    int result = n1 * n2;
    LATD = result & 0xFF;  // Output result to PORTD (limit to 8 bits)
}

// Function to divide two numbers and display result on PORTD
void divide(int n1, int n2){
    if (n2 != 0) {  // Avoid division by zero
        int ans = n1 / n2;  // Perform integer division
        LATD = ans & 0xFF;   // Output result to PORTD (limit to 8 bits)
    } else {
        LATD = 0;  // Output 0 if division by zero occurs
    }
}

void main() {
    int n1 = 0, n2 = 0, op = 0;  // Variables to hold inputs and operation code

    // Configure direction registers:
    // 1 = input, 0 = output
    TRISA = 0xFF;  // PORTA as input for first number (n1)
    TRISB = 0xFF;  // PORTB as input for second number (n2)
    TRISC = 0xFF;  // PORTC as input for operation choice (op)
    TRISD = 0x00;  // PORTD as output to show result

    // Read inputs from respective ports
    n1 = PORTA;   // Read first number from PORTA
    n2 = PORTB;   // Read second number from PORTB
    op = PORTC;   // Read operation code from PORTC

    // Perform operation based on the value of 'op'
    switch(op){
        case 1:
            multiply(n1, n2);   // Call multiply function
            break;
        case 2:
            divide(n1, n2);     // Call divide function
            break;
        default:
            LATD = 0;           // Default case: output 0 if invalid operation
            break;
    }    
}


*/





// IF YOU WANT TO SHOW ON THE KIT

// #include <xc.h>

// // CONFIGURATION BITS (Example for PIC18F)
// #pragma config FOSC = INTOSCIO
// #pragma config WDTE = OFF
// #pragma config PWRTE = OFF
// #pragma config MCLRE = ON
// #pragma config CP = OFF
// #pragma config CPD = OFF
// #pragma config BOREN = ON
// #pragma config IESO = OFF
// #pragma config FCMEN = OFF
// #pragma config LVP = OFF

// #define _XTAL_FREQ 4000000

// void main(void) {
//     unsigned char a = 8, b = 4, c = 0;
//     unsigned char ch = 0;

//     TRISA = 0xFF;   // PORTA as input
//     TRISD = 0x00;   // PORTD as output
//     PORTD = 0x00;

//     while(1){
//         // Read the menu choice from RA0 and RA1
//         if(RA0 == 1){    // If RA0 is HIGH => Multiply
//             ch = 1;
//         }
//         else if(RA1 == 1){ // If RA1 is HIGH => Divide
//             ch = 2;
//         }
//         else{
//             ch = 0;   // No valid choice
//         }

//         // Perform operation based on choice
//         switch (ch) {
//             case 1: // Multiply
//                 c = a * b;
//                 break;
//             case 2: // Divide
//                 c = a / b;
//                 break;
//             default:
//                 c = 0;
//                 break;
//         }

//         PORTD = c;  // Display result on LEDs

//         __delay_ms(200);  // Small delay for stability
//     }
// }
