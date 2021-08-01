#include <stdio.h>

void swapNumber(int first, int second){
    //함수를 통한 swap 불가능.
}

void pswapNumber(int *first, int *second){
    int temp;

    temp = *first;
    *first = *second;
    *second = temp;
}

int main()
{
    int num1 = 10;
    int num2 = 20;

    
    pswapNumber(&num1, &num2);

    printf("%d %d\n", num1, num2);


    return 0;
}