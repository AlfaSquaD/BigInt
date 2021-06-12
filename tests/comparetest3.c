//
// Created by ensar on 6/12/2021.
//

#include "../include/bigint.h"
#include <string.h>
#include <stdio.h>

int main(){
    char *num1 = "-250";
    char *num2 = "-251";
    BigInt *data1 = createBigInt(num1);
    BigInt *data2 = createBigInt(num2);
    int result = compare(data1, data2);
    freeBigInt(data1);
    freeBigInt(data2);
    if(result == 1) return 0;
    return 1;
}