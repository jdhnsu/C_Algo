#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huffman.h"
;
node **init_huffman_tree()
{
    node **nums = (node**)malloc(MAX_FREQ * sizeof(node*)); // 修正类型
    char str[MAX_FREQ];
    fgets(str, MAX_FREQ, stdin);
    int w_flog = 0;
    int w_i = 0;
    int freq[MAX_FREQ];
    while (1)
    {
        scanf("%d", &w_flog);
        if (w_flog == -1)
            break;
        freq[w_i] = w_flog;
        w_i++;
    }
    int ii = 0;
    for (ii = 0; str[ii] != '\0' && str[ii] != '\n' && ii < w_i; ii++)
    {
        nums[ii] = (node*)malloc(sizeof(node)); // 分配内存
        nums[ii]->str = str[ii];
        nums[ii]->freq = freq[ii];
        nums[ii]->left = NULL;
        nums[ii]->right = NULL;
        nums[ii]->parent = NULL;
    }
    nums[ii] = (node*)malloc(sizeof(node));
    nums[ii]->str = '\0';
    nums[ii]->freq = 0;
    nums[ii]->left = NULL;
    nums[ii]->right = NULL;
    nums[ii]->parent = NULL;
    return nums;
}


void sort_huffman_tree(node **nums)
{
   for (int i = 0; nums[i]->str != '\0'; i++)
   {
       for (int j = i+1; nums[j]->str != '\0'; j++)
       {
           if (nums[i]->freq > nums[j]->freq)
           {
               node *temp = nums[i];
               nums[i] = nums[j];
               nums[j] = temp;
           }
       }
   }
}
int go = 0;
void build_huffman_tree(node **nums)
{ 
    sort_huffman_tree(nums);
    printf("go %d\n",go);
    go++;
    node *twep = (node*)malloc(sizeof(node));
    twep->left = NULL;
    twep->right = NULL;
    twep->parent = NULL;
    twep->str = '#';
    int flog  = 0;
    twep->freq = nums[flog]->freq + nums[flog+1]->freq;
    if (nums[flog]->freq > nums[flog+1]->freq)
    {
        twep->left = nums[flog+1];
        twep->right = nums[flog];
        nums[flog]->parent = twep;
        nums[flog+1]->parent = twep;
    }
    else
    {
        twep->left = nums[flog];
        twep->right = nums[flog+1];
        nums[flog]->parent = twep;
        nums[flog+1]->parent = twep;
    }
    nums[flog+1] = twep;
    // 数组删除第一个元素,并整体向前移动
    int f_i = 0;
    for (f_i = 0; nums[f_i]->str != '\0'; f_i++)
    {
        nums[f_i-1] = nums[f_i];
    }
    if (f_i == 1)
    {
        priint_huffman_tree(nums);
        return;
    }
    free(twep);
    build_huffman_tree(nums);
}

void priint_huffman_tree(node **nums)
{
    for (int i = 0; nums[i]->str != '\0'; i++)
    {
        printf("%c %d\n",nums[i]->str,nums[i]->freq);
    }
}