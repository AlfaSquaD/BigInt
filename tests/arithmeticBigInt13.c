#include "bigint.h"

int main(){
    char *assert = "58118420722900450437785592699552556593348481330033500944194612587801";
    char *str1 = "64856457897864869789646456748978564674896787896786534545345633452123";
    BigInt *bigInt1 = strtobigInt(str1);
    char *str2 = "-4236231412341234123541261435132568541516654116512651221651511287662";
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
