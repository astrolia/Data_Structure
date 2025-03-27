#include <stdio.h>
#include <stdlib.h>
#include "header.h"


p_node criar_lista()
{
    return NULL;//retorna null para evitar lixo e apenas iniciar o ponteiro
    //boa pratica
}

//detroi lista inteira
void destruir_lista(p_node lista)
{
    p_node tmp = NULL;
    while(lista != NULL)
    {
        tmp = lista;// salva  o endereço do no atual
        lista = lista -> next;//passa para o seguinte
        free(tmp);//exclui o anterior
        //segue assim até o fim da lista
    }

    return;
}

//********************************pode ser melhorada para ficar mais generica
//**********permitindo structs q nao contenham apenas um int
//adciona no inicio da lista
p_node add_elemento_inicio(p_node lista, int x)
{
    //aloca e define os valores do novo no
    p_node novo = (p_node)malloc(sizeof(Node));

    novo -> data = x;
    novo -> next = lista;

    return novo;
}

//********************************pode ser melhorada para ficar mais generica
//**********permitindo structs q nao contenham apenas um int
//adciona no fim da lista
p_node add_elemento_final(p_node lista, int x)
{
    //aloca novo no e define um ptr para percorrer a lista
    p_node novo = (p_node)malloc(sizeof(Node));
    p_node ptr = NULL;
    ptr = lista;

    //define valores
    novo -> data = x;
    novo -> next = NULL;

    if(lista == NULL)
    {
        lista = novo;
        return lista;
    }

    //percorre a lista até o ultimo elemento
    while(ptr -> next != NULL)
    {
        ptr = ptr -> next;
    }

    //conecta o ultimo elemento ao novo no
    ptr->next = novo;

    return lista;

}

//printa a lista
void print_list(p_node lista)
{
    // um for para percorrer a lista
    for(lista = lista; lista != NULL; lista = lista -> next)
    {
        printf("\n%d", lista -> data);
    }
    return;
}

//copia uma lista
p_node copiar_lista(p_node lista)
{
    p_node anterior = NULL;
    p_node nova_lista = NULL;
    p_node novo = NULL;

    //percorre a lista original
    while(lista != NULL)
    {
        //criando um node
        novo = (p_node)malloc(sizeof(Node));

        //caso seja o primeiro elemento
        if(nova_lista == NULL)
        {
            nova_lista = novo;
        }

        //caso não seja o primeiro elemento
        if(anterior != NULL)
        {
            anterior -> next = novo;//conect o anterior ao novo no
        }

        // define o dado armazenado
        novo -> data = lista -> data;
        anterior = novo;//guarda o endereço do no criado
        lista = lista -> next;//avança na lista para a proxima copia
        novo -> next = NULL;//define o next do no para null, evita lixo de memoria
    }
    return nova_lista;// retorna um ponteiro para a copia
}

//inverte a lista
p_node inverter_lista(p_node lista)
{
    p_node atual, anterior, invertida = NULL;
    if(lista == NULL)//caso a lista nao tenha nada, retorna ela msm
    {
        return lista;
    }

    atual = lista;

    while(atual != NULL)//percorre lista atual
    {
    //inverte um a um até o fim
        anterior = atual;// salva endereço do atual
        atual = anterior -> next;// avança para proximo no
        anterior -> next = invertida;//faz o anterior apontar para o seu antecessor
        invertida = anterior;// antecessor vira o anterior
        // segue assim até o fim da lista
    }
    return invertida;
}

//concatena uma lista no fim dde outra
p_node concatenar_lista(p_node primeira, p_node segunda)
{
    p_node concatenada = NULL;
    concatenada = primeira;

    //casos em q uma das listas esteja vazia
    if(primeira == NULL)
    {
        return segunda;
    }
    if(segunda == NULL)
    {
        return primeira;
    }

    //avança até o ultimo no da primeira
    while(concatenada -> next != NULL)
    {
        concatenada = concatenada -> next;
    }
    //liga o ultimo no da primeira no primeiro da segunda lista
    concatenada -> next = segunda;

    return primeira;
}
