#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "heap.h"

void swap(heap *tree,int x,int y)
{
    elem_t twep = tree->data[x];
    tree->data[x] = tree->data[y];
    tree->data[y] = twep;
}

heap* heap_init()
{
    heap *tree = (heap *)malloc(sizeof(heap));
    tree->size = 0;
    return tree;
}

int heap_get_left(heap *tree,int i)
{ 
    return  2 * i + 1;
}

int heap_get_right(heap *tree,int i)
{
    return 2 * i + 2;
}

int heap_get_prent(heap *tree,int i)
{
    return (i-1) / 2;
}

void heap_push(heap *tree,elem_t val)
{
  if (tree->size == 0)
    { tree->data[0] = val;tree->size++; return;}
  tree->data[tree->size] = val;
  
  if (tree->data[tree->size] > tree->data[heap_get_prent(tree,tree->size)])
    {
       swap(tree,heap_get_prent,tree->size); 
    }
 }
