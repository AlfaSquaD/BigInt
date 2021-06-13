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

bool bigint_add(char* out, char* num1, char* num2){
    char* tmp = calloc(1 ,DIGITS);
    char *shortNum, *longNum;
    unsigned long len1 = strlen(num1);
    unsigned long len2 = strlen(num2);
    unsigned long shortest;
    int diff;
    int carry = 0;
    int sum;
    if(len1 > DIGITS || len2 > DIGITS){
        fprintf(stdout, "Number larger than %d Digits!\nOperation stopped!\n", DIGITS);
        return false;
    }
    if(len1 <= len2){
        shortest = len1;
        diff = (int)(len2 - len1);
        shortNum = num1;
        longNum = num2;
    }
    else{
        shortest = len2;
        diff = (int)(len1 - len2);
        shortNum = num2;
        longNum = num1;
    }
    for (int i = (int)shortest - 1; i >= 0; i--){
        sum = ((shortNum[i] - '0') + (longNum[i + diff] - '0')) + carry;
        if(sum > 9){
            tmp[i + diff] = (char)('0' + (sum % 10));
            carry = 1;
        } else{
            tmp[i+diff] = (char)(sum + '0');
            carry = 0;
        }
    }
    for(int i = diff - 1; i >= 0; i--){
        sum = (longNum[i] - '0') + carry;
        if(sum > 9){
            tmp[i] = (char)('0' + (sum % 10));
            carry = 1;
        } else{
            tmp[i] = (char)(sum + '0');
            carry = 0;
        }
    }
    if(carry == 1){
        if (strlen(tmp) == DIGITS) {
            fprintf(stdout, "Number larger than %d Digits!\nOperation stopped!\n", DIGITS);
            return false;
        }
        for (int i = (int) strlen(tmp) - 1; i >= 0; i--) tmp[i + 1] = tmp[i];
        tmp[0] = '1';
    }
    strcpy(out, tmp);
    free(tmp);
    return true;
}

void printBigInt(BigInt* number){
    if(number->isNegative) printf("-%s", number->number);
    else printf("%s", number->number);
}

void freeBigInt(BigInt* data){
    free(data->number);
    free(data);
}