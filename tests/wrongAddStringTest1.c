//
// Created by ensar on 6/12/2021.
//

#include "../include/bigint.h"
#include <string.h>
#include <stdio.h>

int main(){
    char *num1 = "1000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000 ";
    char *num2 = "251";
    char *out;
    if(!bigint_add(out, num1, num2)) return 0;
    return 1;
}