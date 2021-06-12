//
// Created by ensar on 6/12/2021.
//

#include "../include/bigint.h"
#include <string.h>
#include <stdio.h>
int main(){
    BigInt *data;
    char* num = "000000003";
    data = createBigInt(num);
    if(data == NULL) return 1;
    char *out = calloc(sizeof (char), strlen(num) + 1);
    freopen("/dev/null", "a", stdout);
    setbuf(stdout, out);
    printBigInt(data);
    free(data);
    if(strcmp(out, "3") == 0) return 0;
    else return 1;
}
