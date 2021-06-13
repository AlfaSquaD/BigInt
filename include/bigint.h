//
// Created by ensar on 6/12/2021.
//

#ifndef BIGINT_BIGINT_H
#define BIGINT_BIGINT_H
#define DIGITS 100
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct bigintStruct{
    bool isNegative;
    char* number;
}BigInt;

bool bigint_add(char* out, char* num1, char* num2);

bool bigint_sub(char* out, char* num1, char* num2);

bool addBigInt(BigInt* dest, BigInt* number);

bool subBigInt(BigInt* dest, BigInt* number);

int compare(BigInt* num1, BigInt* num2);

BigInt *createBigInt(char* str);

void printBigInt(BigInt* number);

void freeBigInt(BigInt* data);

#endif //BIGINT_BIGINT_H
