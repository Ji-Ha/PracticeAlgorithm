#include <stdio.h>

int main(){
    int a = 0;

    printf("a의 주소값은 ? : %d\n\n", &a);

    int *p = &a; // a의 주소를 p가 가지고 있는 것.

    int *p2;
    p2 = p; // p2에 p의 값인 a의 주소를 주는 것.

    printf("p가 가리키고 있는 주소값 : %d p가 가리키고 있는 주소의 값 : %d\n\n", p, *p);

    // printf("p2의 주소값은 %d, 주소가 가르키고 있는 값은 %d\n\n", p2, *p2);

    return 0;
}