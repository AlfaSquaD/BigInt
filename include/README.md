# blocks.h

## BigIntNode struct

```c
typedef struct bigintNode{
    long long number;
    struct bigintNode* next;
    struct bigintNode* prev;
}BigIntNode;
```

## BigInt Struct

```c
typedef struct bigIntStruct{
    bool isNegative;
    BigIntNode* root;
unsigned long long size;
}BigInt;
```

These two structs keeps BigInts(large numbers). There is no upper or lower limit for numbers
(other than your computers memory).

Nodes are store maximum 10 digits (lower than 10^10). After 10 digits, another node added to linked list and
extra digits stored there.

## BigInt Functions

* ```c 
  void addBigInt(BigInt* dest, BigInt* number);
  ```
    * Sums two BigInts.

* ```c 
  void subBigInt(BigInt* dest, BigInt* number);
  ```
    * Subtracts two BigInts.

* ```c 
  void addbi_internal(BigInt* dest, BigInt* number);
  ```
    * Sums two BigInts without signs.

* ```c 
  void subbi_internal(BigInt* dest, BigInt* number);
  ```
    * Subtracts two BigInts without signs.

* ```c 
  void tidyBigInt(BigInt* number);
  ```
    * Cleans unnecessary nodes from BigInt.

* ```c 
  int compare(BigInt* num1, BigInt* num2);
  ```
  * Compares two BigInts.

* ```c 
  int compareAbsVal(BigInt* num1, BigInt* num2);
  ```
  * Compares two BigInts absolute values.

* ```c 
  int compareNode(BigIntNode *node1, BigIntNode *node2);
  ```
  * Compares two BigIntNodes.(Including next nodes).

* ```c 
  void subbi_internal(BigInt* dest, BigInt* number);
  ```
  * Subtracts two BigInts without signs.

* ```c 
  void tidyBigInt(BigInt* number);
  ```
  * Cleans unnecessary nodes from BigInt.