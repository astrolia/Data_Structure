#include <stdio.h>
#include <stdlib.h>
#include "header.h"


p_node criar_lista_linha()
{
    p_node lista;
    lista = malloc(sizeof(Node));
    lista -> linha = -1;
    lista -> Linha = lista;
    lista -> coluna = NULL;
    lista -> Coluna = NULL;
    lista -> data = -1;
    return lista;
}

p_node criar_lista_coluna()
{
    p_node lista;
    lista = malloc(sizeof(Node));
    lista -> linha = NULL;
    lista -> Linha = NULL;
    lista -> coluna = -1;
    lista -> Coluna = lista;
    lista -> data = -1;
    return lista;
}

p_node new_node(int ll, int cc, int x)
{
    if(x == 0)
        return NULL;
    p_node novo;
    novo = malloc(sizeof(Node));
    novo -> linha = ll;
    novo -> coluna = cc;
    novo -> Linha = NULL;
    novo -> Coluna = NULL;
    novo -> data = x;

    return novo;
}

//adiciona novo node
//acha o antecessor e o sucessor e adiciona
//novo node entre eles
p_node add_node_linha(p_node lista, p_node elemento)
{
    p_node maior;
    p_node menor;
    p_node p = elemento_existe_linha(lista, elemento);

    if(p != NULL)
    {
        p -> data = elemento -> data;
        free(elemento);
        return lista;
    }

    maior = maior_elemento_linha(lista, elemento);
    menor = maior -> Linha;

    if(maior == lista)
    {
        elemento -> Linha = lista;
        lista -> Linha = elemento;
    }

    else if(maior == elemento)
    {
        menor = lista -> Linha;
        elemento -> Linha = menor;
        lista -> Linha = elemento;
    }

    //maior esta caindo no sucessor do novo node
    else
    {
        elemento -> Linha = menor;
        maior -> Linha = elemento;
    }
    return lista;
}

//acha o antecessor do novo node
p_node maior_elemento_linha(p_node lista, p_node novoelemento)
{
    p_node maior;
    p_node maioratual = NULL;
    maior = lista;

    //se lista vazia
    if(maior -> Linha == lista)
    {
        return lista;
    }

    //percorre a lista em busca do antecessor
    while(maior -> Linha != lista)
    {
        maior = maior -> Linha;

        if(maior -> coluna > novoelemento -> coluna)
        {
            maioratual = maior;
        }
    }
    //se novo node for o maior
    if (maioratual == NULL)
    {
        return novoelemento;
    }
    // se algum node for o maior
    return maioratual;

}
//procura elemento compativel em coluna
p_node elemento_existe_linha(p_node lista, p_node elemento)
{
    p_node p = lista;
    while(p -> Linha != lista)
    {
        p = p -> Linha;

        if(p -> coluna == elemento -> coluna)
        {
            return p;
        }
    }
    return NULL;
}

void print_list(p_node lista)
{
    p_node p = lista;

    if(p -> Linha -> coluna == NULL)
    {
        printf("%d ", p -> data);
        return;
    }

    print_list(p -> Linha);
    if(p -> coluna == NULL)
    {
        return;
    }
    printf("%d ", p -> data);
    return;
}

p_node add_node_coluna(p_node lista, p_node elemento)
{
    p_node maior;
    p_node menor;
    p_node p = elemento_existe_coluna(lista, elemento);

    if(p != NULL)
    {
        p -> data = elemento -> data;
        free(elemento);
        return lista;
    }

    maior = maior_elemento_coluna(lista, elemento);
    menor = maior -> Coluna;

    if(maior == lista)
    {
        elemento -> Coluna = lista;
        lista -> Coluna = elemento;
    }

    else if(maior == elemento)
    {
        menor = lista -> Coluna;
        elemento -> Coluna = menor;
        lista -> Coluna = elemento;
    }

    //maior esta caindo no sucessor do novo node
    else
    {
        elemento -> Coluna = menor;
        maior -> Coluna = elemento;
    }
    return lista;
}

//acha o antecessor do novo node
p_node maior_elemento_coluna(p_node lista, p_node novoelemento)
{
    p_node maior;
    p_node maioratual = NULL;
    maior = lista;

    //se lista vazia
    if(maior -> Coluna == lista)
    {
        return lista;
    }

    //percorre a lista em busca do antecessor
    while(maior -> Coluna != lista)
    {
        maior = maior -> Coluna;

        if(maior -> linha > novoelemento -> linha)
        {
            maioratual = maior;
        }
    }
    //se novo node for o maior
    if (maioratual == NULL)
    {
        return novoelemento;
    }
    // se algum node for o maior
    return maioratual;

}
//procura elemento compativel em linha
p_node elemento_existe_coluna(p_node lista, p_node elemento)
{
    p_node p = lista;
    while(p -> Coluna != lista)
    {
        p = p -> Coluna;

        if(p -> linha == elemento -> linha)
        {
            return p;
        }
    }
    return NULL;
}


void print_list_coluna(p_node lista)
{
    p_node p = lista;

    while(p -> Coluna != lista)
    {
        p = p -> Coluna;
        printf("%d ", p -> data);
    }
}

p_node deletar(p_node lista, int linha, int coluna)
{
    p_node busca;
    p_node ant = NULL;
    p_node ant_coluna;
    busca = lista;

    while(busca -> Linha != lista)
    {
        ant = busca;
        busca = busca -> Linha;
        if(busca -> linha == linha && busca -> coluna == coluna)
        {
            break;
        }
    }
    if(busca == lista)
    {
        return NULL;
    }
    ant_coluna = busca;
    while(ant_coluna -> Coluna != busca)
    {
        ant_coluna = ant_coluna -> Coluna;
    }

    ant -> Linha = busca -> Linha;
    ant_coluna -> Coluna = busca -> Coluna;
    free(busca);
    return lista;

}


