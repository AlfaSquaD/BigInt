//
// Created by ensar on 6/20/2021.
//
#include "bigint.h"

int main(){
    char *assert = "-1";
    char *str1 = "3999";
    BigInt *bigInt1 = strtobigInt(str1);
    char *str2 = "3998";
    BigInt *bigInt2 = strtobigInt(str2);
    subBigInt(bigInt2, bigInt1);
    char *out = calloc(sizeof (char), strlen(assert) + 1);
    freopen("/dev/null", "a", stdout);
    setbuf(stdout, out);
    printBigInt(bigInt2);
    freeBigInt(bigInt1);
    freeBigInt(bigInt2);
    return strcmp(out, assert);
}

