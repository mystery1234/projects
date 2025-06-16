#include "block.h"
#include <stdio.h>
#include <stdlib.h>
int main(){
    Block *head = createGenesisBlock();
    Block *current = head;
    current = createBlock(current, "ruksana created this!!\n");
    current = createBlock(current, "another cool block!\n");
    current = createBlock(current, "yet another one..\n");
    printf("Ruksana's Mini Block");
    printChain(head);
    return 0;

}