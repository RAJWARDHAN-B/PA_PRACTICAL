// WRITE AN EMBEDDED C PROGRAM TO INTERFACE PIC18FXXX WITH LED AND BLINKING IT USING SPECIFIED DELAY

#include<xc.h>
#include<stdio.h>
#include<stdlib.h>
#define _XTAL_FREQ 4000000

void delay(unsigned int time){
    int i,j;
    for(i=0;i<time;i++){
        for(j=0;j<5000;j++);
    }
}

void main(void){
    TRISB = 0x00;
    LATB = 0x00;

    while(1){
        for(int i=1;i<4;i++){
            switch(i){
                case 1:
                    LATB=0xAA;
                    break;
                case 2:
                    LATB=0xFF;
                    break;
                case 3:
                    LATB=0x00;
                    break;
            }
            delay(100);
            // BUILT IN DELAY __delay_ms(500);
        }
    }
}