#include <stdio.h>
#include <stdlib.h>
# include "header.h"

p_node inserir_circular(p_node lista, int x)
{
    p_node novo;

    novo -> data = x;

    if(lista == NULL)
    {
        novo -> next = novo;
    }
    else
    {
        novo = lista -> next;
        lista -> next = novo;
    }

    return novo;
}

void remover_circular(p_node lista, p_node target)
{
    p_node anterior;
    if(target -> prox = target)
    {
        free(target);
        return NULL;
    }
    for(anterior = target -> next; anterior -> next != target; anterior = anterior -> next);
    anterior -> next = target -> next;
    if(lista == target)
    {
        lista = lista -> next;
    }
    free(target)
    return lista;
}

void print_circular(p_node lista)
{

    p_node p;
    p = lista;
    if(lista == NULL)
    {
        return;
    }

    do
    {
        printf("%d\n", p -> data);
        p = p -> next;
    }while (p != lista);

    return;
}

//o ponteiro lista sempre apontara para a cabeça
//cabeça nao tem dados
//lista vazia so possui a cabeça apontando para ela mesma
p_node inserir_c_cabeça(p_node lista; int x)
{
    p_node novo;
    novo = malloc(sizeof(Node));

    novo -> data = x;
    novo -> next = lista -> next;
    lista -> next = novo;

    return lista;
}

p_node remover_c_cabeça(p_node lista, p_node target)
{
    p_node anterior;
        for(anterior = target -> next; anterior -> next != target; anterior = anterior -> next);
    anterior -> next = target -> next;
    free(target);
    return(lista);
}

