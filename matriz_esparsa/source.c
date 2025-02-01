#include <stdio.h>
#include <stdlib.h>

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
    lista -> coluna = NULL;
    lista -> Coluna = NULL;
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

    return novo;
}

p_node add_node_linha(p_node lista, int linha, p_node elemento)
{
    p_node maior;
    p_node menor;

    if(elemento_existe == 1)
    {
        //caso o elemento exista
    }

    maior = maior_elemento(lista, linha);
    menor = menor_elemento(lista, linha);

    elemento -> next = menor;
    maior -> next = elemento;
}

p_node maior_elemento(p_node lista, int linha)
{
    p_node maior;
    p_node maioratual;
    maior = lista;
    if(maior -> next = lista)
    {
        return maior;
    }

    while(maior -> next != lista)
    {
        maior = maior -> next;

        //busca começa pelo maior elemento sempre
        //talvez de pra achar o menor por essa mesma busca
        //parei aqui***************************************
        if(maior -> linha > linha)
        {
            maioratual = maior;
        }
    }

}
