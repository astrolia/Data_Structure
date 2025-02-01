#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

typedef struct Node* p_node;

p_node criar_lista();
void destruir_lista(p_node lista);
p_node add_elemento(p_node lista, int x);
void print_list(p_node lista);
p_node copiar_lista(p_node lista);
p_node inverter_lista(p_node lista);
p_node concatenar_lista(p_node primeira, p_node segunda);


#endif // HEADER_H_INCLUDED
