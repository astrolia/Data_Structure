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
    int linhas = 0;
    int colunas = 0;
    int i;
    int linha_deletar;
    int coluna_deletar;
    int terminate = 0;

    p_node novo;

    while(terminate != 1)
    {
        printf("Continuar?(S = 0|N = 1): ");
        scanf("%d", &terminate);
        if(terminate == 1)
        {
            break;
        }
        printf("\n\n");
        printf("Informe o numero de linhas e colunas");
        printf("\n\n");

        while(linhas < 1)
        {
            printf("Linhas: ");
            scanf("%d", &linhas);
            printf("\n");
            if(linhas < 1)
            {
                printf("Valor invalido");
                printf("\n");
            }
        }

        while(colunas < 1)
        {
            printf("Colunas: ");
            scanf("%d", &colunas);
            printf("\n");
            if(colunas < 1)
            {
                printf("Valor invalido");
                printf("\n");
            }
        }

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

            printf("Novo elemento: 1");
            printf("\n");
            printf("Mostrar matriz por linhas: 2");
            printf("\n");
            printf("Mostrar matriz por colunas: 3");
            printf("\n");
            printf("Deletar elemento: 4");
            printf("\n");
            printf("Voltar: 0");

        while(op != 0)
        {

            printf("\n\n");
            printf("-->");
            scanf("%d", &op);
            printf("\n");

            if(op == 1)
            {
                printf("Informe o valor e a posicao");
                printf("\n\n");
                printf("\nValor: ");
                scanf("%d", &d);
                printf("\nLinha: ");
                scanf("%d", &l);
                printf("\nColuna: ");
                scanf("%d", &c);

                if(d != 0)
                {
                    if(l > linhas || c > colunas || l < 1 || c < 1)
                    {
                        printf("\nMatriz %d x %d, insira uma posicao adequada\n", linhas, colunas);
                    }

                    novo = new_node(l, c, d);

                    add_node_linha(linha_matriz[l - 1], novo);
                    add_node_coluna(coluna_matriz[c - 1], novo);
                }
            }
            if(op == 2)
            {
                for(i = 0; i < linhas; i++)
                {
                    if(linha_matriz[i] -> Linha != linha_matriz[i])
                    {
                        print_list(linha_matriz[i]);
                        printf("\n");
                    }
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

            if(op == 4)
            {
                printf("Informe a Linha para deletar: ");
                scanf("%d", &linha_deletar);
                printf("\n");
                printf("Informe a Coluna para deletar: ");
                scanf("%d", &coluna_deletar);
                printf("\n");
                deletar(linha_matriz[linha_deletar - 1], linha_deletar, coluna_deletar);
            }

            if(op == 0)
            {
                for(linha_deletar = 0; linha_deletar < linhas; linha_deletar++)
                {
                    for(coluna_deletar = 0; coluna_deletar < colunas; coluna_deletar++)
                    {
                       deletar(linha_matriz[linha_deletar], linha_deletar, coluna_deletar);
                    }
                }
            }
        }
    }
    return 0;
}
