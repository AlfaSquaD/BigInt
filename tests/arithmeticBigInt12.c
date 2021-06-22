#include "bigint.h"

int main(){
    char *assert = "-62354652135241561148972727991171868280713470030033500931770989446567";
    char *str1 = "62354652135241684561326854134685125134865135446546152165846123875463";
    BigInt *bigInt1 = strtobigInt(str1);
    char *str2 = "-12423623141234123412354126143513256854151665416512651221651511287662";
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
