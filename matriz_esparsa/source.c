#include <stdio.h>
#include <stdlib.h>
#include "header.h"

//criar lista ligada com cabeça
//criar elemento
//add elemento em lista ligada linha e coluna com cabeça
//remover elemento lista ligada com cabeça
//apagar lista

p_node criar_lista_linha()
{
    p_node lista;
    lista = malloc(sizeof(Node));
    lista -> linha = -1;
    lista -> Linha = lista;
    lista -> coluna = 21;
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

    if(p == elemento)
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
//procura elemento compativel
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

//para fazer isso é importante
//acessar cada coluna onde a linha passa
//e excluir o elemento de maneira q a coluna
//nao fique com ponteiros para o nada
//next step ''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''
void delete_lista_linha(p_node lista)
{
    p_node p = lista -> Linha;
    p_node tmp;
    while(p -> Linha != lista)
    {


    }
}

void delete_lista(p_node lista)
{
    p_node p = lista;
    p_node tmp;

    while(p -> Linha != lista)
    {
        tmp = p;
        p = p -> Linha;
        free(tmp);
    }
}

void print_list(p_node lista)
{
    p_node p = lista;

    while(p -> Linha != lista)
    {
        p = p -> Linha;
        printf("%d ", p -> data);
    }
}
