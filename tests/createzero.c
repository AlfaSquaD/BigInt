//
// Created by ensar on 6/12/2021.
//

#include "../include/bigint.h"
#include <string.h>
#include <stdio.h>
int main(){
    BigInt *data;
    char* num = "0";
    data = createBigInt(num);
    if(data == NULL) return 1;
    char *out = calloc(sizeof (char), DIGITS);
    freopen("/dev/null", "a", stdout);
    setbuf(stdout, out);
    printBigInt(data);
    free(data);
    if(strcmp(out, num) == 0) return 0;
    else return 1;
}
