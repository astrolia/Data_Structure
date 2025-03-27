#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "Func.c"


int main()
{
    int n;
    p_node lista;
    p_node nlista;
    p_node glista;
    lista = criar_lista();
    do
    {
        printf("Adicionar elemento: ");
        scanf("%d", &n);
        if(n > 0)
        {
            lista = add_elemento_inicio(lista, n);
            //lista = add_elemento_final(lista, n);
        }
    }while(n > 0);
    nlista = copiar_lista(lista);
    glista = concatenar_lista(lista, nlista);
    print_list(glista);
    destruir_lista(glista);
    //destruir_lista(nlista);
    //destruir_lista(lista);
    return 0;
}
