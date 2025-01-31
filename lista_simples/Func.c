#include <stdio.h>
#include <stdlib.h>
#include "header.h"


p_node criar_lista()
{
    return NULL;
}

void destruir_lista(p_node lista)
{
    p_node tmp = NULL;
    while(lista != NULL)
    {
        tmp = lista;
        lista = lista -> next;
        free(tmp);
    }

    return;
}

p_node add_elemento(p_node lista, int x)
{
    p_node novo = (p_node)malloc(sizeof(Node));

    novo -> data = x;
    novo -> next = lista;

    return novo;
}

void print_list(p_node lista)
{
    for(lista = lista; lista != NULL; lista = lista -> next)
    {
        printf("\n%d", lista -> data);
    }
    return;
}

p_node copiar_lista(p_node lista)
{
    p_node anterior = NULL;
    p_node nova_lista = NULL;
    p_node novo = NULL;

    while(lista != NULL)
    {
        novo = (p_node)malloc(sizeof(Node));

        if(nova_lista == NULL)
        {
            nova_lista = novo;
        }

        if(anterior != NULL)
        {
            anterior -> next = novo;
        }

        novo -> data = lista -> data;
        anterior = novo;
        lista = lista -> next;
        novo -> next = NULL;
    }
    return nova_lista;
}

p_node inverter_lista(p_node lista)
{
    p_node atual, anterior, invertida = NULL;
    if(lista == NULL)
    {
        return lista;
    }

    atual = lista;

    while(atual != NULL)
    {
        anterior = atual;
        atual = anterior -> next;
        anterior -> next = invertida;
        invertida = anterior;
    }
    return invertida;
}
