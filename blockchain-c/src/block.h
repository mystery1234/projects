#ifndef BLOCK_H
#define BLOCK_H

#include <stdint.h>
#include <time.h>

typedef struct Block
{
    int index;
    time_t timestamp;
    char data[256];
    char prevHash[65];
    char hash[65];
    struct Block *next;
}Block;

Block *createGenesisBlock();
Block *createBlock(Block *prevBlock, const char *data);
void printBlock(const Block *block);
void printChain(const Block *head);
#endif