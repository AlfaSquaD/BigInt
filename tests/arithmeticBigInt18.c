#include "bigint.h"

int main(){
    char *assert = "34487448988547787781564780197449560878289953506360";
    char *str1 = "25125134865135446546152165846123875463123412341234";
    BigInt *bigInt1 = strtobigInt(str1);
    char *str2 = "9362314123412341235412614351325685415166541165126";
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
