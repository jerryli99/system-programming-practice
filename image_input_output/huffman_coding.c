#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//huffman tree struct
struct MinHeapNode
{
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};


struct MinHeap
{
    unsigned size;
    unsigned capacity;
    struct MinHeapNode **array;
};

/*

array will be like
idx              array[i]             Node (MinHeapNode)
0            Pointer to Node A         Data 'a', Freq: 5
1            Pointer to Node B         Data 'b', Freq: 9
2            Pointer to Node C         Data 'c', Freq: 12
...

*/


struct MinHeapNode *createNode(char data, unsigned freq)
{
    struct MinHeapNode* newNode = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
    newNode->data = data;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;

    return newNode;
};

struct MinHeap* createMinHeap(unsigned capacity)
{
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(capacity * sizeof(struct MinHeapNode*));
    
    return minHeap;
}