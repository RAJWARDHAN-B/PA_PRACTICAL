// WRITE AN EMBEDDED C MENU DRIVEN PROGRAM BY USING INPUT OF MENU CHOICE AS A VARIABLE FOR:
//     i) MULTIPLY 8 BIT BY 8 BIT NUMBER
//     ii) DIVIDE 8 BIT BY 8 BIT NUMBER
// (SHOW THE OUTPUT IN THE SIMULATOR)

#include<xc.h>

int a=8,b=4,c;

int ch=1;

void main(void){
    TRISD=0x00;
    PORTD=0x00;

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