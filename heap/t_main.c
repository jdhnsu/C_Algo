#include <stdio.h>
#include "heap.h"


int main(void)
{
   heap *tree  =  heap_init();
   int flog_s = 0;
   scanf("%d",&flog_s);
   for (int i = 1;i<=flog_s;i++)
   {
      heap_push(tree,i);
   }
   heap_print(tree,0);
   return 0;
}