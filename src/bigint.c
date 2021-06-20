//
// Created by ensar on 6/12/2021.
//

#include "../include/bigint.h"

BigInt *strtobigInt(char* str){
    BigInt *result = malloc(sizeof (BigInt));
    BigIntNode *currNode = malloc(sizeof (BigIntNode));
    result->root = currNode;
    currNode->prev = NULL;
    result->size = 0;
    char* currStr = calloc(sizeof (char), DECIMAL_SEP + 1);
    char* str2long = currStr;
    if(str[0] == '-'){
        result->isNegative = true;
        str += 1;
    } else result->isNegative = false;
    while (str[0] == '0') str += 1;
    long long i = strlen(str) - 1;
    while (i >= 0) {
        result->size += 1;
        i -= DECIMAL_SEP;
        if(i < 0){
            strncpy(currStr, str, i + DECIMAL_SEP + 1);
        }
        else{
            strncpy(currStr, (str + i + 1), DECIMAL_SEP);
        }
        while (str2long[0] == '0') str2long += 1;
        currNode->number = strtoll(str2long, NULL, 0);
        if(i >= 0){
            currNode->next = malloc(sizeof (BigIntNode));
            currNode->next->prev = currNode;
        }
        else currNode->next = NULL;
        currNode = currNode->next;
        for (int j = 0; j < DECIMAL_SEP; ++j) {
            currStr[j] = 0;
        }
        str2long = currStr;
    }
    free(currStr);
    return result;
}

void addBigInt(BigInt* dest, BigInt* number){
    int carry = 0;
    BigIntNode *destNode = dest->root, *otherNode = number->root;
    if((dest->isNegative + number->isNegative) % 2 != 0){
        return subBigInt(dest, number);
    }
    while (otherNode){
        destNode->number += otherNode->number + carry;
        carry = 0;
        if(destNode->number >= NODE_MAX_VAL){
            destNode->number -= NODE_MAX_VAL;
            carry = 1;
        }
        if(destNode->next == NULL && otherNode->next){
            destNode->next = malloc(sizeof (BigIntNode));
            dest->size += 1;
        }
        destNode = destNode->next;
        otherNode = otherNode->next;
    }
    if(carry == 1){
        destNode->next = malloc(sizeof (BigIntNode));
        dest->size += 1;
        destNode->number = carry;
    }
    tidyBigInt(dest);
}

// TODO: Rewrite
void subBigInt(BigInt* dest, BigInt* number){
    if((dest->isNegative + number->isNegative) % 2 == 0){
        return addBigInt(dest, number);
    }
    BigInt *tdest, *tnumber;
    bool swap;
    if(compareAbsVal(dest, number) == -1){
        tdest = copyBigInt(number);
        tdest->isNegative = !dest;
        tnumber = dest;
        swap = true;
    } else{
        tdest = dest;
        tnumber = number;
        swap = false;
    }
    BigIntNode *destNode = tdest->root, *otherNode = tnumber->root;
    while (otherNode){
        destNode->number -= otherNode->number;
        if(destNode->number < 0){
            destNode->number += NODE_MAX_VAL;
            if(destNode->next)
                destNode->next->number -= 1;
            else{
                dest->isNegative = !dest->isNegative;
                destNode->number *= -1;
            }
        }
        if(destNode->next == NULL && otherNode->next){
            destNode->next = malloc(sizeof (BigIntNode));
            dest->size += 1;
        }
        if(otherNode->next) destNode = destNode->next;
        otherNode = otherNode->next;
    }
    if(destNode->number < 0){
        dest->isNegative = !dest->isNegative;
        destNode->number = destNode->number * -1;
    }
    tidyBigInt(tdest);
    if(swap){
        freeBigInt(dest);
        dest = malloc(sizeof (BigInt));
        dest->isNegative = tdest->isNegative;
        dest->size = tdest->size;
        dest->root = tdest->root;
        free(tdest);
    }
}

void printBigInt(BigInt* number){
    if(number->isNegative) printf("-");
    _printbigIntNode(number->root);
}

void _printbigIntNode(BigIntNode* node){
    if(node->next){
        _printbigIntNode(node->next);
        for (char i = digitCount(node->number); i < DECIMAL_SEP; ++i) printf("0");
    }
    printf("%lld", node->number);
}

char digitCount(long long num){
    if (num == 0) return 1;
    char result = 0;
    while (num != 0){
        num /= 10;
        result++;
    }
    return result;
}

void tidyBigInt(BigInt* number){
    BigIntNode *currNode = number->root;
    BigIntNode *temp = NULL;
    bool clean = false;
    while (currNode){
        if(currNode->number == 0){
            if(temp==NULL) temp = currNode;
            clean = true;
        } else{
            temp = NULL;
            clean = false;
        }
        currNode = currNode->next;
    }
    if(clean && temp){
        currNode = temp;
        if(currNode == number->root)
            currNode = currNode->next;
        currNode->prev->next = NULL;
        while (currNode){
            temp = currNode;
            currNode = currNode->next;
            free(temp);
        }
    }
}

BigInt *copyBigInt(BigInt *number){
    BigInt *result = malloc(sizeof (BigInt));
    result->isNegative = number->isNegative;
    result->size = 0;
    result->root = malloc(sizeof (BigIntNode));
    BigIntNode *numCurr = number->root;
    BigIntNode *copyCurr = result->root;
    while (numCurr){
        copyCurr->number = numCurr->number;
        if(numCurr->next){
            copyCurr->next = malloc(sizeof (BigIntNode));
            if(result->size == 0) copyCurr->prev = NULL;
            else copyCurr->next->prev = copyCurr;
            result->size += 1;
        }
        else copyCurr->next = NULL;
        numCurr = numCurr->next;
    }
    return result;
}

int compare(BigInt* num1, BigInt* num2){
    if(!num1->isNegative && num2->isNegative) return 1;
    if(num1->isNegative && !num2->isNegative) return -1;
    if(num1->isNegative){
        if(num1->size > num2->size) return -1;
        else if(num1->size < num2->size) return 1;
        else return _compareNode(num1->root, num2->root) * -1;

    }
    else{
        if(num1->size > num2->size) return 1;
        else if(num1->size < num2->size) return -1;
        else return _compareNode(num1->root, num2->root);
    }
}

int compareAbsVal(BigInt* num1, BigInt* num2){
    if(num1->size > num2->size) return 1;
    else if(num1->size < num2->size) return -1;
    else return _compareNode(num1->root, num2->root);
}

int _compareNode(BigIntNode *node1, BigIntNode *node2){
    int result;
    if(node1->next && node2->next){
        result = _compareNode(node1->next, node2->next);
    }
    else{
        if(node1->number == node2->number) result = 0;
        else result = node1->number > node2->number?1:-1;
    }
    if(result != 0) return result;
    else{
        if(node1->number == node2->number) result = 0;
        else result = node1->number > node2->number?1:-1;
        return result;
    }
}

void freeBigInt(BigInt* number){
    BigIntNode *curr, *temp;
    curr = number->root;
    while (curr){
        temp = curr;
        curr = curr->next;
        free(temp);
    }
    free(number);
}
