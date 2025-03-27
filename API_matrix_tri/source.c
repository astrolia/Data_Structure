#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef int** Matriz_Int; //tipo e matriz na heap

//Inicia uma Matriz Triangular desejada
// Inline para alocar a função na linha de execução do programa
inline static Matriz_Int InitMatrix(int linhas, Matriz_Int(*func)(Matriz_Int, int))
{
    int i;
    Matriz_Int Matriz;

    Matriz = (int**)malloc(sizeof(int*) * linhas);

    Matriz = func(Matriz, linhas);

    return Matriz;
}

//aloca superior
Matriz_Int Triangular_Superior(Matriz_Int M, int linhas)
{
    for(i = 0; i < linhas; i++)
    {
        M[i] = (int*)malloc(sizeof(int) * linhas - i)
    }

    return M;
}

//aloca inferior
Matriz_Int Triangular_Inferior (Matriz_Int M, int linhas)
{
    for(i = 1; i <= linhas; i++)
    {
        M[i] = (int*)malloc(sizeof(int) * i)
    }

    return M;
}

//Libera a mratiz
inline static void Liberar_Matriz(Matriz_Int M, int linhas)
{
    int i;

    for(i = 0; i < linahs; i++)
    {
        free(M[i]);
    }

    free(M);
}


//COloca um valor na matriz
inline static Put_Value(Matriz_Int M, int linha, int coluna, int valor, void(*func)(int, int))
{
    func(linha, coluna);

    M[linha][coluna];
}

//verifica inferior
void Put_V_Inf(int i, int j)
{
    assert(i >= j);
}

//verifica superior
void Put_V_Sup(int i, int j)
{
    assert(i <= j);
}

//Imprime uma matriz triangualr
inline static void Imprimir_Matriz(Matriz_Int Matriz, int linhas, int colunas int(*func)(Matriz_Int, int, int))
{
    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            Val = func(Matriz, i, j);

            printf(" %d ", Val);
        }
    }
}

//retorna valor triangular inferior
int take_Inf(Matriz_Int M, int i, int j)
{
    if(i >= j)
        return M[i][j];

    return 0;
}

//retorna valor triangular superior
int take_Sup(Matriz_Int M, int i, int j)
{
    if(i <= j)
        return M[i][j];

    return 0;
}
