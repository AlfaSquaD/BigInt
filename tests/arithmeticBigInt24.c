#include "bigint.h"

int main(){
    char *assert = "9999999993";
    char *str1 = "-9";
    BigInt *bigInt1 = strtobigInt(str1);
    char *str2 = "-10000000002";
    BigInt *bigInt2 = strtobigInt(str2);
    subBigInt(bigInt1, bigInt2);
    char *out = calloc(sizeof (char), strlen(assert) + 1);
    freopen("/dev/null", "a", stdout);
    setbuf(stdout, out);
    printBigInt(bigInt1);
    freeBigInt(bigInt1);
    freeBigInt(bigInt2);
    return strcmp(out, assert);
}
