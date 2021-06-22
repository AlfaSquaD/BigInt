#include "bigint.h"

int main(){
    char *assert = "-890068971005992438851027272008828131719286529969966499055805387412199";
    char *str1 = "62354652135241684561326854134685125134865135446546152165846123875463";
    BigInt *bigInt1 = strtobigInt(str1);
    char *str2 = "-952423623141234123412354126143513256854151665416512651221651511287662";
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
