// WRITE AN EMBEDDED C PROGRAM FOR GENERATING PWM SIGNAL FOR SERVO MOTOR/DC MOTOR.

#include<xc.h>
#define FREQ_PWM 50

void initPWM(){
    TRISCbits.TRISC1 = 0;
    TRISCbits.TRISC2 = 0;

    T2CONbits.T2CKPS = 0b11;
    T2CONbits.TMR2ON = 1;

    PR2 = 150;

    CCP1CONbits.CCP1M = 0b1100;
    CCP1CONbits.CCP2M = 0b1100;

    TRISCbits.TRISC1 = 0;
    TRISCbits.TRISC2 = 0;

    CCPR1L = 128;
    CCPR2L = 128;

    INTCONbits.GIE = 1;
}

void setPWMDutyCycle(unsigned char motor,unsigned char dutyCycle){
    if(motor == 1){
        CCPR1L = dutyCycle;
    } else if(motor == 2){
        CCPR2L = dutyCycle;
    }
}

void delay_ms(unsigned int ms){
    unsigned int i,j;
    for(i=0;i<ms;i++){
        for(j=0;j<1000;j++);
    }
}

void main(void){
    initPWM();

    setPWMDutyCycle(1,128);
    setPWMDutyCycle(2,128);

    while(1){
        for(unsigned char duty = 0; duty<255;duty++){
            setPWMDutyCycle(1,duty);
            delay_ms(50);
        }

        for(unsigned char duty = 255; duty>=0;duty--){
            setPWMDutyCycle(1,duty);
            delay_ms(50);
        }

        for(unsigned char duty = 0; duty<255;duty++){
            setPWMDutyCycle(2,duty);
            delay_ms(50);
        }

        for(unsigned char duty = 255; duty>=0;duty--){
            setPWMDutyCycle(2,duty);
            delay_ms(50);
        }
    }
}




// GPT GAVE THIS, ONLY FOR 1 MOTOR



/*
#include <xc.h>
#define _XTAL_FREQ 4000000   // 4 MHz

void initPWM(){
    TRISCbits.TRISC2 = 0;    // CCP1 output pin (PWM)
    
    T2CONbits.T2CKPS = 0b01; // Timer2 Prescaler = 4
    PR2 = 124;               // Set PWM period (~8 kHz)
    
    CCP1CONbits.CCP1M = 0b1100; // PWM mode on CCP1
    CCPR1L = 0;                  // Initial 0% duty cycle
    
    T2CONbits.TMR2ON = 1;    // Turn ON Timer2
}

void setPWMDutyCycle(unsigned char dutyCycle){
    CCPR1L = dutyCycle;  // Set duty cycle (0–255)
}

void delay_ms(unsigned int ms){
    while(ms--) __delay_ms(1);
}

void main(void){
    initPWM();

    while(1){
        // Slowly increase speed
        for(unsigned char duty = 0; duty < 255; duty++){
            setPWMDutyCycle(duty);
            delay_ms(10);
        }

        // Slowly decrease speed
        for(int duty = 254; duty >= 0; duty--){
            setPWMDutyCycle((unsigned char)duty);
            delay_ms(10);
        }
    }
}
    */





// FOR CLOCKWISE AND ANTICLOCKWISE ROTATION




/*
#include <xc.h>
#define _XTAL_FREQ 4000000   // 4 MHz crystal

// Define motor control pins
#define MOTOR_IN1 LATAbits.LATA0   // Motor Input 1
#define MOTOR_IN2 LATAbits.LATA1   // Motor Input 2

void initPWM(){
    TRISCbits.TRISC2 = 0;       // CCP1 output pin (PWM) as output
    T2CONbits.T2CKPS = 0b01;    // Timer2 Prescaler = 4
    PR2 = 124;                  // PWM frequency around 8 kHz
    CCP1CONbits.CCP1M = 0b1100; // Enable PWM mode on CCP1
    CCPR1L = 128;               // Initial 50% duty cycle
    T2CONbits.TMR2ON = 1;       // Turn ON Timer2
}

void setPWMDutyCycle(unsigned char dutyCycle){
    CCPR1L = dutyCycle;
}

void delay_ms(unsigned int ms){
    while(ms--) __delay_ms(1);
}

void rotateCW(){
    MOTOR_IN1 = 1;
    MOTOR_IN2 = 0;
}

void rotateACW(){
    MOTOR_IN1 = 0;
    MOTOR_IN2 = 1;
}

void stopMotor(){
    MOTOR_IN1 = 0;
    MOTOR_IN2 = 0;
}

void main(void){
    // Setup
    ADCON1 = 0x0F;             // Set PORTA digital
    TRISAbits.TRISA0 = 0;       // RA0 output
    TRISAbits.TRISA1 = 0;       // RA1 output

    initPWM();                 // Initialize PWM
    setPWMDutyCycle(128);       // 50% duty cycle

    while(1){
        // Rotate Clockwise
        rotateCW();
        delay_ms(3000);         // Rotate for 3 seconds

        // Small stop (optional)
        stopMotor();
        delay_ms(500);

        // Rotate Anti-Clockwise
        rotateACW();
        delay_ms(3000);         // Rotate for 3 seconds

        // Small stop (optional)
        stopMotor();
        delay_ms(500);
    }
}

*/





// BHAVIKA MOTOR

/*

#include <xc.h>
#include<pic18f4550.h>

void msdelay(unsigned int time){
    unsigned int i,j;
    for(i=0;i<time;i++){
        for(j=0;j<710;j++);
    }
}

void main(void) {
    TRISCbits.TRISC2=0;         //set RC2 as output to control CCP1 module
    LATCbits.LATC2=0;           //high all pins of RC2
    TRISCbits.TRISC6=0;         //set RC6 as output to control motor
    TRISCbits.TRISC7=0;         //set RC7 as output to control motor
    
    PR2=0xBA;                   //set pwm freq to 4KHz
    CCP1CON=0x0C;               //set CCP1 module in pwm mode
    T2CON=0x07;                 //configures timer 2 
    
    PORTCbits.RC6=1;            //turn on motor
    PORTCbits.RC7=0;            //turn of motor
    
    while(1){
        //-----duty cycle 80%----
        CCP1CONbits.DC1B0=0;
        CCP1CONbits.DC1B1=0;
        CCPR1L=0x96;
        msdelay(2000);
        
        //----duty cycle 60%----
        CCP1CONbits.DC1B0=0;
        CCP1CONbits.DC1B1=1;
        CCPR1L=0x70;
        msdelay(2000);
        
        //----duty cycle 40%----
        CCP1CONbits.DC1B0=0;
        CCP1CONbits.DC1B1=0;
        CCPR1L=0x4B;
        msdelay(2000);
        
        //----duty cycle 20%----
        CCP1CONbits.DC1B0=0;
        CCP1CONbits.DC1B1=1;
        CCPR1L=0x25;
        msdelay(2000);
    }
}

*/
