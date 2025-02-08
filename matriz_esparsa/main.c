#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "source.c"

int main()
{
    int op = 1;
    int x;
    int linha;
    int coluna;
    p_node lista = criar_lista_linha();
    p_node novo;

    while(op != 0)
    {
        printf("\nop: ");
        scanf("%d", &op);

        if(op == 1)
        {
            printf("\ninfo: ");
            scanf("%d", &x);
            printf("\nlinha: ");
            scanf("%d", &linha);
            printf("\ncoluna: ");
            scanf("%d", &coluna);

            novo = new_node(linha, coluna, x);
            add_node_linha(lista, novo);
        }
        if(op == 2)
        {
            print_list(lista);
        }
    }
    delete_lista(lista);
    print_list(lista);
    return 0;
}
