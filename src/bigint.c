//
// Created by ensar on 6/12/2021.
//

#include "../include/bigint.h"

BigInt *createBigInt(char* str){
    char* number = str;
    BigInt *data = malloc(sizeof (BigInt));
    if(number[0] == '-'){
        data->isNegative = true;
        // Skipping minus sign
        number += 1;
    }else data->isNegative = false;
    data->number = calloc(sizeof (char), DIGITS);
    unsigned long len = strlen(number);
    if(len == 1 && number[0] == '0') data->number[0] = '0';
    else{
        for (int i = 0; i < len; i++){
            if(number[0] == '0') number+=1;
        }
        strcpy(data->number, number);
        for (int i = 0; i < strlen(number); i++){
            if(!(number[i] >= '0' && number[i] <= '9')){
                free(data->number);
                free(data);
                fprintf(stdout, "Not an integer value!\n");
                return NULL;
            }
        }
    }
    return data;
}

int compare(BigInt* num1, BigInt* num2){
    if(!num1->isNegative && num2->isNegative) return 1;
    else if(num1->isNegative && !num2->isNegative) return -1;
    unsigned long len1 = strlen(num1->number);
    unsigned long len2 = strlen(num2->number);
    if(len1 > len2) return 1;
    else if(len2 > len1) return -1;
    else{
        if(num1->isNegative && num2->isNegative){
            for (int i = 0; i < len1; ++i) {
                if(num1->number[i] > num2->number[i]) return -1;
                else if(num2->number[i] > num1->number[i]) return 1;
            }
            return 0;
        }
        else{
            for (int i = 0; i < len1; ++i) {
                if(num1->number[i] > num2->number[i]) return 1;
                else if(num2->number[i] > num1->number[i]) return -1;
            }
            return 0;
        }
    }
}

void printBigInt(BigInt* number){
    if(number->isNegative) printf("-%s", number->number);
    else printf("%s", number->number);
}

void freeBigInt(BigInt* data){
    free(data->number);
    free(data);
}