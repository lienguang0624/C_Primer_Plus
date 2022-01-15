#include <stdio.h>

void main(){
    int a  = 6; //位模式为00000110
    int b = 11; //位模式为00001011
    int c = 0;

    c = a&b;
    printf("a&b:%d\n",c);//a&b:2

    c = a|b;
    printf("a&b:%d\n",c);//a&b:15

    c = a^b;
    printf("a^b:%d\n",c);//a^b:13

    c = ~a;
    printf("~a:%d\n",c);//~a:-7

    unsigned long n = 0xB,     // 位模式： 0 ... 0 0 0 1 0 1 1
    result = 0;
    result = n << 2;          //              0 ... 0 1 0 1 1 0 0
    printf("result:%d\n",result);
    result = n >> 2;          //              0 ... 0 0 0 0 0 1 0
    printf("result:%d\n",result);
}