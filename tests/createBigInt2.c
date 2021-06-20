//
// Created by ensar on 6/20/2021.
//
#include "bigint.h"

int main(){
    char *str = "-32109245645634536456458765432109874563456345456543210";
    BigInt *bigInt = strtobigInt(str);
    char *out = calloc(sizeof (char), strlen(str) + 1);
    freopen("/dev/null", "a", stdout);
    setbuf(stdout, out);
    printBigInt(bigInt);
    freeBigInt(bigInt);
    return strcmp(out, str);
}

