#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[200];
    char prontuario[50];
    float media;
}estudante;

//***********************************************
estudante* definir_classe(int tamanho)
{
    int i;
    estudante *classe = malloc(sizeof(estudante)*tamanho);

    for(i = 0; i < tamanho; i++)
    {
        printf("---Novo Aluno---\n");
        printf("nome: ");
        scanf("%s", classe[i].nome);
        printf("prontuario: ");
        scanf("%s", classe[i].prontuario);
        printf("media: ");
        scanf("%fl", &classe[i].media);
        printf("\n");
    }

    return classe;
}

//********************************************
void print_classe(estudante *classe, int tamanho)
{
    int i;

    printf("\n--------------------------------------------\n");
    for(i = 0; i < tamanho; i ++)
    {
        printf(" Nome: %s | ", classe[i].nome);
        printf(" Prontuario: %s |", classe[i].prontuario);
        printf(" Media: %.2f", classe[i].media);
        printf("\n--------------------------------------------\n");
    }

}

//**********************************************
//func para comparar duas stringas
int compProntuario(void* ptr1, void* ptr2)
{
    // casting para definir o ponteiro void
    //para ponteiro estudante
    // faz o ponteiro str apontar para a string encontrada
    char* str1 = ((estudante* )ptr1) -> prontuario;
    char* str2 = ((estudante* )ptr2) -> prontuario;

    /*
    caso strcomp() retorne:
    0: as duas strings são iguais
    < 0: str1 é menor que str2 (lexicograficamente, ou seja, ordem "ASCIIticamente")
    > 0: str1 é maior que str2
    */
    return strcmp(str1, str2);
}

//*********************************************


int main()
{
    int num = 4;
    estudante *classe = NULL;

    classe = definir_classe(num);
    printf("\n\n");

    print_classe(classe, num);

    //usa algoritmo Quick Sort, recursivo, log(n), divide a partir de um pivo
    //a função e comparação deve ser no seguinte molde:
    //int comparar(const void *a, const void *b); fazer as devidas alterações para cada tipo
    // se < 0 a deve vir antes de b
    // se > 0 a deve vir depois de b
    // se 0 a e b são iguais
    qsort(classe, num, sizeof(estudante), compProntuario);

    print_classe(classe, num);

    return 0;
}
