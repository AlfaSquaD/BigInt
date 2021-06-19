//
// Created by ensar on 6/12/2021.
//

#include "../include/bigint.h"
#include <string.h>
#include <stdio.h>

int main(){
    char *num1 = "250";
    char *num2 = "251";
    char *out = malloc(4);
    bigint_sub(out, num2, num1);

    if(strcmp(out, "1") == 0) return 0;
    return 1;
}