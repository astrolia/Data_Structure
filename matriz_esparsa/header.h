#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct Node
{
    int linha;
    int coluna;
    int data;
    struct Node* Linha;
    struct Node* Coluna;
}Node;

typedef struct Node* p_node;

#endif // HEADER_H_INCLUDED
