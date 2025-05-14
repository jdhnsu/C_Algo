#ifndef HUFFMAN_H
#define HUFFMAN_H

typeddef struct node
{
    char str;
    int freq;
    struct node *left;
    struct node *right;
    struct node *parent; 
}node;


#endif