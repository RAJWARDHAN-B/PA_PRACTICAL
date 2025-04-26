// WRITE AN EMBEDDED C PROGRAM TO ADD ARRAY OF N NUMBERS.
// (SHOW OUTPUT IN SIMULATOR)
#include<xc.h>

int arr[] = {1,2,3,4,5};
int n=5;
int i=0,sum=0;

void main(void){

    TRISD = 0x00;
    PORTD = 0x00;

    for(i=0;i<n;i++){
        sum+=arr[i];
    }

    // LATD = sum also works
    PORTD = sum;
    while(1);
}
