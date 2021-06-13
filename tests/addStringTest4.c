//
// Created by ensar on 6/12/2021.
//

#include "../include/bigint.h"
#include <string.h>
#include <stdio.h>

int main(){
    char *num1 = "13546154654231";
    char *num2 = "5415315235";
    char *out = calloc(1, DIGITS);
    bigint_add(out, num1, num2);
    if(strcmp(out, "13551569969466") == 0) return 0;
    return 1;
}