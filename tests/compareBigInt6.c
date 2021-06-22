#include "bigint.h"

int main(){
    char *assert = "-1";
    char *str1 = "-6485645789786486978964645674897856467489";
    BigInt *bigInt1 = strtobigInt(str1);
    char *str2 = "64856457897864869789646456748978564674896787896786534545345633452123";
    BigInt *bigInt2 = strtobigInt(str2);
    if(compare(bigInt1, bigInt2) == -1) return 0;
}
