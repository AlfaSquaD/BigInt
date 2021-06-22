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
  void openBlock(BlockKeeper *blockKeeper, long long int *loopCounter, unsigned int line, unsigned long long int fPointer,
   bool isIntConstant, bool isShortHandLoop);
  ```
    * Opens a new block. Nests new block if already a block opened.

* ```c 
  bool closeBlock(BlockKeeper *blockKeeper);
  ```
    * Closes the deepest block. If there is no block to close, returns false.

* ```c 
  unsigned int closeBlockAndGetLine(BlockKeeper *blockKeeper);
  ```
    * Closes the deepest block and returns its startLine. If there is no block to close, returns -1.

* ```c 
  BlockKeeper *createBlockKeeper()
  ```
    * Creates a BlockKeeper and returns its pointer.

* ```c 
  void freeBlockKeeper(BlockKeeper *blockKeeper)
  ```
    * Frees given BlockKeeper.