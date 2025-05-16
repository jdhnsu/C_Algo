#ifndef HUFFMAN_H
#define HUFFMAN_H
#define MAX_FREQ 256
typedef struct node
{
    char str;
    int freq;
    struct node *left;
    struct node *right;
    struct node *parent; 
}node;
void build_huffman_tree();
node **init_huffman_tree();
void priint_huffman_tree(node **nums);
// 排序函数
void sort_huffman_tree(node **nums);
#endif
// cmd /c chcp 65001>nul && C:\TDM-GCC-64\bin\gcc.exe -fdiagnostics-color=always -g L:\code\C++_AND_C\C\C_Algo\huffman\*.c -o L:\code\C++_AND_C\C\C_Algo\huffman\main