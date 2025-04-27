// MEMORY TRANSFER

#include <xc.h>
#include <string.h>  // Include string.h for memcpy and memmove

#define _XTAL_FREQ 4000000
#define ARR_SIZE 5

int arr1[ARR_SIZE] = {1, 20, 3, 4, 5};
int arr2[ARR_SIZE] = {6, 7, 8, 9, 10};
int temp[ARR_SIZE], t[ARR_SIZE];
int i;
int choice = 1;

void main(void) {
    TRISD = 0x00;  // Set PORTD as output
    PORTD = 0x00;  // Initialize PORTD

    switch (choice) {
        case 1:
            memcpy(temp, arr1, ARR_SIZE * sizeof(int));  // Use memcpy
            break;

        case 2:
            memmove(t, arr1, ARR_SIZE * sizeof(int));  // Use memmove
            break;

        case 3:
            for (i = 0; i < ARR_SIZE; i++) {
                int swapTemp = arr1[i];
                arr1[i] = arr2[i];
                arr2[i] = swapTemp;
            }
            break;

        default:
            break;
    }

    for (i = 0; i < ARR_SIZE; i++) {
        PORTD = arr1[i] & 0xFF;  // Mask to ensure it's within 8 bits
        __delay_ms(100);  // Add delay between each value
    }

    while(1);
}


/*

#include <xc.h>
#define _XTAL_FREQ 4000000

int arr1[5] = {1, 2, 3, 4, 5};
int arr2[5] = {6, 7, 8, 9, 10};
int temp[5];
int t[5];
int choice = 1;  // Set 1: memcpy, 2: memmove, 3: swap

void my_memcpy(int *dest, int *src, int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

void my_memmove(int *dest, int *src, int size) {
    if (dest < src) {
        for (int i = 0; i < size; i++) {
            dest[i] = src[i];
        }
    } else {
        for (int i = size - 1; i >= 0; i--) {
            dest[i] = src[i];
        }
    }
}

void main(void) {
    TRISD = 0x00;  // Set PORTD as output
    PORTD = 0x00;

    switch (choice) {
        case 1:
            my_memcpy(temp, arr1, 5);  // Copy arr1 to temp
            break;

        case 2:
            my_memmove(t, arr1, 5);    // Move arr1 to t
            break;

        case 3:
            for (int i = 0; i < 5; i++) {
                int swap_temp = arr1[i];
                arr1[i] = arr2[i];
                arr2[i] = swap_temp;
            }
            break;

        default:
            // Do nothing
            break;
    }

    // Output the result on PORTD
    for (int i = 0; i < 5; i++) {
        if (choice == 1) {
            PORTD = temp[i];
        } else if (choice == 2) {
            PORTD = t[i];
        } else if (choice == 3) {
            PORTD = arr1[i];  // After swapping
        }
        __delay_ms(1000);
    }

    while(1);
}


*/
