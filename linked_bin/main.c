#include <stdio.h>
#include <stdlib.h>

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
struct node* NewPrisma(struct node* newnode)
{
    struct prisma* newprisma = (struct node*)malloc(sizeof(struct node*));

    scanf("%s", tipo);
    scanf("%f", &altura);
    scanf("%f", &largura);
    scanf("%f", &profundidade);

    newnode -> data = newprisma;

    return newnode;
};

//novo node ao head
struct node* InsertHead(struct node* head, struct node* newnode)
{
    newnode -> next = head -> next;

    return newnode;
};

void PrintItens(struct node* head)
{
    while(head != NULL)
    {
        printf("%s", tipo);
        printf("%f", altura);
        printf("%f", largura);
        printf("%f", profundidade);
    }
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
    printf("Hello world!\n");
    return 0;
}
