//
// Created by ensar on 6/20/2021.
//
#include "bigint.h"

int main(){
    char *assert = "1132424235345654752349384610003";
    char *str1 = "1132424235345654752349284620000";
    BigInt *bigInt1 = strtobigInt(str1);
    char *str2 = "99990003";
    BigInt *bigInt2 = strtobigInt(str2);
    addBigInt(bigInt1, bigInt2);
    char *out = calloc(sizeof (char), strlen(assert) + 1);
    freopen("/dev/null", "a", stdout);
    setbuf(stdout, out);
    printBigInt(bigInt1);
    freeBigInt(bigInt1);
    freeBigInt(bigInt2);
    return strcmp(out, assert);
}

