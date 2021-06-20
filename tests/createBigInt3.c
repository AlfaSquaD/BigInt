//
// Created by ensar on 6/20/2021.
//
#include "bigint.h"

int main(){
    char *str = "-321000000000000000000000000005444564645648567854600000000000000987456345600000000000000000000000006456456457856785454567867854646456456450000000000000000543210";
    BigInt *bigInt = strtobigInt(str);
    char *out = calloc(sizeof (char), strlen(str) + 1);
    freopen("/dev/null", "a", stdout);
    setbuf(stdout, out);
    printBigInt(bigInt);
    freeBigInt(bigInt);
    return strcmp(out, str);
}

