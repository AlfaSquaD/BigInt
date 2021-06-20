//
// Created by ensar on 6/20/2021.
//
#include "bigint.h"

int main(){
    char *str = "-000000064564564564564564500045454264564856456748867486456789648645678464564545";
    char *assert = "-64564564564564564500045454264564856456748867486456789648645678464564545";
    BigInt *bigInt = strtobigInt(str);
    char *out = calloc(sizeof (char), strlen(str) + 1);
    freopen("/dev/null", "a", stdout);
    setbuf(stdout, out);
    printBigInt(bigInt);
    freeBigInt(bigInt);
    return strcmp(out, assert);
}

