// WRITE AN EMBEDDED C PROGRAM FOR PC TO PC SERIAL COMMUNICATION USING UART

#include<xc.h>
#define _XTAL_FREQ 4000000

void UART_Init(){
    TRISC6 = 0;
    TRISC7 =1;
    SPBRG = 0x04;
    BRGH = 1;
    SYNC = 0;
    SPEN = 1;
    TXEN = 1;
    CREN = 1;
}

void UART_TxChar(char data){
    while(!TXIF);
    TXREG = data;
}

char UART_RxChar(){
    while(!RCIF);
    return RCREG;
}

void main(void){
    UART_Init();

    while(1){
        char ch = UART_RxChar();
        UART_TxChar(ch);
        // IF EXCLAMATION AFTER EACH LETTER 
        // UART_TxChar('!');
    }
}