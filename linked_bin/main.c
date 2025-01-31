#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//criar, adicionar e excluir uma linked list

struct node
{
    struct medidas* data;
    struct node* next;
};

struct prisma
{
    char tipo[15];
    float altura;
    float largura;
    float profundidade;
};

//novo node
struct node* NewNode()
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node*));

    return newnode;
};

//novo node ao novo prisma
struct prisma* NewPrisma()
{
    struct prisma* newprisma = (struct node*)malloc(sizeof(struct node*));

    printf("\nNome: ");
    scanf("%s", newprisma -> tipo);
    printf("\nAltura: ");
    scanf("%f", &newprisma -> altura);
    printf("\nLargura: ");
    scanf("%f", &newprisma -> largura);
    printf("\nProfundidade: ");
    scanf("%f", &newprisma -> profundidade);

    return newprisma;
};

//novo node ao head
struct node* InsertHead(struct node* head, struct node* newnode, void* ptr)
{
    newnode -> data = ptr;
    newnode -> next = head;

    return newnode;
};

void PrintItens(struct node* head)
{
    while(head != NULL)
    {
        PrintPrisma(head -> data);
        head = head -> next;
    }
};

void PrintPrisma(struct prisma* prisma)
{
        printf("\n%s", prisma -> tipo);
        printf("\n%f", prisma -> altura);
        printf("\n%f", prisma -> largura);
        printf("\n%f", prisma -> profundidade);
};

//Free
void FreeList(struct node* head)
{
    struct node* tmp = NULL;
    while(head != NULL)
    {
        free(head -> data);
        tmp = head;
        head = head -> next;
        free(tmp);
    }
};

int main()
{
    int option = 0;
    struct node* head = NULL;
    void* novaforma;
    struct node* ptr = NULL;

    while(option != 10)
    {
        printf("\nOpcao: ");
        scanf("%d", &option);
        if(option == 1)
        {
            ptr = NewNode();
            novaforma = NewPrisma();
            head = InsertHead(head, ptr, novaforma);
        }

        if(option == 2)
        {
            PrintItens(head);
        }
        if(option == 3)
        {
            FreeList(head);
            head = NULL;
        }
    }

    FreeList(head);

    return 0;
}
