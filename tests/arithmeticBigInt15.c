#include "bigint.h"

int main(){
    char *assert = "993623141234123327228991278377810307999499565527389659041738787532";
    char *str1 = "-85125134865135446546152165846123875463123412341234";
    BigInt *bigInt1 = strtobigInt(str1);
    char *str2 = "993623141234123412354126143513256854151665411651265122165151128766";
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
