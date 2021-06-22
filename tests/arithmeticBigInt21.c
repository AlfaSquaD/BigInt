#include "bigint.h"

int main(){
    char *assert = "-100748276099258858898";
    char *str1 = "-95125134865135446544";
    BigInt *bigInt1 = strtobigInt(str1);
    char *str2 = "-5623141234123412354";
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
