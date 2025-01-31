#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "Func.c"


int main()
{
    int n;
    p_node lista;
    p_node nlista;
    lista = criar_lista();
    do
    {
        printf("Adicionar elemento: ");
        scanf("%d", &n);
        if(n > 0)
        {
            lista = add_elemento(lista, n);
        }
    }while(n > 0);
    print_list(lista);
    lista = inverter_lista(lista);
    print_list(lista);
    destruir_lista(lista);
    return 0;
}
