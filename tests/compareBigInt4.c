//
// Created by ensar on 6/20/2021.
//
#include "bigint.h"

int main(){
    char *assert = "-1";
    char *str1 = "64856457897864869789646456748978564674896787896786534545345633452124";
    BigInt *bigInt1 = strtobigInt(str1);
    char *str2 = "64856457897864869789646456748978564674896787896786534545345633452123";
    BigInt *bigInt2 = strtobigInt(str2);
    if(compare(bigInt1, bigInt2) == 1) return 0;
}

