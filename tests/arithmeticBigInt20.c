#include "bigint.h"

int main(){
    char *assert = "-23762820741723105310739551494798190047956871176108";
    char *str1 = "-25125134865135446546152165846123875463123412341234";
    BigInt *bigInt1 = strtobigInt(str1);
    char *str2 = "1362314123412341235412614351325685415166541165126";
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
