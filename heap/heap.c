#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "heap.h"

void heap_swap(heap *tree,int x,int y)
{
    elem_t tt = tree->data[x];
    tree->data[x] = tree->data[y];
    tree->data[y] = tt;
}

heap* heap_init()
{
    heap *tree = (heap *)malloc(sizeof(heap));
    memset(tree,0,sizeof(heap));
    return tree;
}

int heap_get_right(heap *tree,int i)
{
    return 2 * i + 2;
}

int heap_get_left(heap *tree,int i)
{
   return 2 * i + 1;
}


int heap_get_parent(heap *tree,int i)
{
    return (i - 1)/2;
}

void heap_push(heap *tree,int val)
{
    if (tree->size == MAX_S-1)
        {
            printf("heap is full\n");
            return;
        }
    tree->data[tree->size] = val;
    int flog_i = tree->size;
    while(1)
    {
       int flog_p = heap_get_parent(tree,flog_i);
       if (tree->data[flog_i] <= tree->data[flog_p] || flog_p<0)
       {
        break;
       }
       heap_swap(tree,flog_i,flog_p);
       flog_i = flog_p;
    }
    tree->size++;
}


void heap_print(heap* tree,int root)
{
    int queue[3] = {0};
    int font = 0;
    int rear = 0;
    int flog = 0;
    while (flog < tree->size)
    {
        for (int i = 0;i<2;i++)
            {
               switch (i)
               {
               case 0:
               int  flog_l= heap_get_left(tree,queue[font]);
                if (flog_l > tree->size)
                    {
                        continue;
                    }
                queue[rear] = flog_l;
                rear = (rear+1) % 3;
                break;
                case 1:
                int flog_r = heap_get_right(tree,queue[font]);
                if (flog_r > tree->size)
                    {
                        continue;
                    }
                queue[rear] = flog_r;
                rear = (rear+1) % 3;
                break; 
               default:
                break;
               }
            } 
            printf("%d",tree->data[queue[font]]);
            font = (font+1) % 3;
            flog++;
    }
}
 