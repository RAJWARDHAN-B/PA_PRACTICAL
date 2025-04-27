// WRITE AN EMBEDDED C PROGRAM FOR SORTING THE NUMBERS IN ASCENDING AND DESCENDING ORDER.
// (SHOW OUTPUT IN MEMORY SECTION OF SIMULATOR)

#include<xc.h>
#include<stdio.h>
#include<stdlib.h>
// or we can do #include<pic18f4550.h>
#define _XTAL_FREQ 4000000

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int arr[] = {5,2,3,1,4};

int n=5;

int comp_asc(const void *a, const void *b){
    return(*(int *)a - *(int *)b);
}

int comp_desc(const void *a, const void *b){
    return(*(int *)b - *(int *)a);
}

int ch = 1;

void main(void){

    TRISB=0x00;
    TRISC=0x00;
    TRISD=0x00;


    // FOR DIGITAL PIN


    // TRISA = 0xFF;

    // LATAbits.LATA0 = 0;
    // LATAbits.LATA1 = 0;
    // LATAbits.LATA2 = 0;
    // LATAbits.LATA3 = 1;

    // REPLACE PORT BY LAT FOR INPUT SIMULATION

    // if (PORTAbits.RA0 == 1) {
    //     ch = 1;
    // }
    // else if (PORTAbits.RA1 == 1) {
    //     ch = 2;
    // }
    // else if (PORTAbits.RA2 == 1) {
    //     ch = 3;
    // }
    // else if (PORTAbits.RA3 == 1) {
    //     ch = 4;
    // }
    // else {
    //     ch = 0;
    // }

    switch(ch){
        case 1:
            for(int i=0;i<n;i++){
                for(int j=0;j<n-1-i;j++){
                    if(arr[j]>arr[j+1]){
                        swap(&arr[j], &arr[j+1]);
                    }
                }
            }
            break;

        case 2:
            qsort(arr,(size_t)n,sizeof(arr[0]),comp_asc);
            break;
        case 3:
            for(int i=0;i<n;i++){
                for(int j=0;j<n-1-i;j++){
                    if(arr[j]<arr[j+1]){
                        swap(&arr[j], &arr[j+1]);
                    }
                }
            }
            break;
        case 4:
            qsort(arr,(size_t)n,sizeof(arr[0]),comp_desc);
            break;
        default:
            break;
    }

    PORTB=(unsigned char)arr[0];
    PORTC=(unsigned char)arr[1];
    PORTD=(unsigned char)arr[2];

    while(1);

}
