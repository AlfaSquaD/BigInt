//
// Created by ensar on 6/12/2021.
//

#include "../include/bigint.h"
#include <string.h>
#include <stdio.h>

int main(){
    char *num1 = "95465421248564";
    char *num2 = "12542412";
    char *out = calloc(1, DIGITS);
    bigint_add(out, num1, num2);
    if(strcmp(out, "95465433790976") == 0) return 0;
    return 1;
}