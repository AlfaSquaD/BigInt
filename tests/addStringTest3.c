//
// Created by ensar on 6/12/2021.
//

#include "../include/bigint.h"
#include <string.h>
#include <stdio.h>

int main(){
    char *num1 = "99999999999999";
    char *num2 = "1";
    char *out = calloc(1, DIGITS);
    bigint_add(out, num1, num2);
    if(strcmp(out, "100000000000000") == 0) return 0;
    return 1;
}