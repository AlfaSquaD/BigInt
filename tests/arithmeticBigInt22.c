#include "bigint.h"

int main(){
    char *assert = "1";
    char *str1 = "10000000000";
    BigInt *bigInt1 = strtobigInt(str1);
    char *str2 = "-9999999999";
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
