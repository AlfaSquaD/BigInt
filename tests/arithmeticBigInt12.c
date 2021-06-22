#include "bigint.h"

int main(){
    char *assert = "-61881579277099549562214407300447443406651518718580360050668989001166";
    char *str1 = "62354652135241684561326854134685125134865135446546152165846123875463";
    BigInt *bigInt1 = strtobigInt(str1);
    char *str2 = "-124236231412341234123541261435132568541516654165126512216515112876629";
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
