#include "block.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Block *createGenesisBlock(){
    Block *block = (Block*)malloc(sizeof(Block));
    block->index = 0;
    block->timestamp = time(NULL);
    strcpy(block->data, "Genesis Block");
    strcpy(block->prevHash, "0");
    strcpy(block->hash, "GENESIS_HASH");
    block->next = NULL;
    return block;
}

Block *createBlock(Block *prevBlock, const char *data){
    Block *block = (Block *)malloc(sizeof(Block));
    block->index = prevBlock->index+1;
    block->timestamp = time(NULL);
    strncpy(block->data,data, sizeof(block->data));
    strncpy(block->prevHash, prevBlock->hash, sizeof(block->prevHash));
    strcpy(block->hash, "DUMMY_HASH");
    block->next = NULL;
    prevBlock ->next = block;
    return block;
}

void printBlock(const Block *block){
    printf("Index: %d\n", block->index);
    printf("Timestamp: %s", ctime(&block->timestamp));
    printf("Data: %s\n", block->data);
    printf("Hash: %s\n", block->hash);
    printf("----------------------------\n");
}
void printChain(const Block *head){
    const Block *current = head;
    while (current != NULL)
    {
        printBlock(current);
        current = current->next;
    }    
}