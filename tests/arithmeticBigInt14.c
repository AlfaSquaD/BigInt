#include "bigint.h"

int main(){
    char *assert = "5536841445800900875571185399105113186696962660067001888389225175601999999991760";
    char *str1 = "12354652135241684561326854134685125134865135446546152165846123875463123412341234";
    BigInt *bigInt1 = strtobigInt(str1);
    char *str2 = "-6817810689440783685755668735580011948168172786479150277456898699861123412349474";
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
