#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "source.c"

int main()
{
    int op = 1;
    int d;
    int l;
    int c;
    int linhas;
    int colunas;
    int i;
    p_node novo;

    printf("linhas: ");
    scanf("%d", &linhas);
    printf("\n");
    printf("colunas: ");
    scanf("%d", &colunas);
    printf("\n");

    p_node linha_matriz[linhas];
    p_node coluna_matriz[colunas];

    for(i = 0; i < linhas; i++)
    {
        linha_matriz[i] = criar_lista_linha();
    }

    for(i = 0; i < colunas; i++)
    {
        coluna_matriz[i] = criar_lista_coluna();
    }

    while(op != 0)
    {
        printf("\nop: ");
        scanf("%d", &op);

        if(op == 1)
        {
            printf("\ninfo: ");
            scanf("%d", &d);
            printf("\nlinha: ");
            scanf("%d", &l);
            printf("\ncoluna: ");
            scanf("%d", &c);

            if(l > linhas || c > colunas || l < 1 || c < 1)
            {
                printf("\nSua matriz eh %d x %d, insira uma posicao adequada\n", linhas, colunas);
            }

            novo = new_node(l, c, d);

            add_node_linha(linha_matriz[l - 1], novo);
            add_node_coluna(coluna_matriz[c - 1], novo);
        }
        if(op == 2)
        {
            for(i = 0; i < linhas; i++)
            {
                print_list(linha_matriz[i]);
                printf("\n");
            }
        }

        if(op == 3)
        {
            for(i = 0; i < colunas; i++)
            {
                print_list_coluna(coluna_matriz[i]);
                printf("\n");
            }
        }
    }
    for(i = 0; i < linhas; i++)
    {
        delete_lista(linha_matriz[i]);
    }

    for(i = 0; i < linhas; i++)
    {
        print_list(linha_matriz[i]);
        printf("\n");
    }
    return 0;
}
