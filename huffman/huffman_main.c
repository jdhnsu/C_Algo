#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "huffman.h"


int main(void)
{
  node **nums =  init_huffman_tree();
  build_huffman_tree(nums);
  return 0;
}
