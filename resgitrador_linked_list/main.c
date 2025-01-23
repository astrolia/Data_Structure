#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
  char name[20];
  int idade;
  float altura;
};

struct node
{
    struct person *data;
    struct node *next;
};

//cria node
struct node* NewNode()
{
    struct node* ptr = (struct node* )malloc(sizeof(struct node));

    return ptr;
};

//adiciona no inicio
struct node *InsertAtHead(struct node* head, struct node* newnode, struct person* newdata)
{

    newnode -> data = newdata;
    newnode -> next = head;

    return newnode;
};

//cria nova pessoa
struct person *New_Person()
{
    struct person *ptr = (struct person*)malloc(sizeof(struct person));

    printf("\nnome:");
    scanf("%s", ptr -> name);
    printf("\nidade:");
    scanf("%d", &ptr -> idade);
    printf("\naltura:");
    scanf("%f", &ptr -> altura);

    return ptr;
};

//exibe a lista
void print(struct node *head, void (*fptr)(void *))
{
    while(head != NULL)
    {
        (*fptr)(head -> data);
        head = head -> next;
    }
};

//exibe pessoa
void printPerson(struct person *ptr)
{
    printf("\n%s", ptr -> name);
    printf("\n%d", ptr -> idade);
    printf("\n%.2f\n", ptr -> altura);
}

//insere no final
struct node* InsertAtEnd(struct node* head, struct node* new_node, struct person* newdata)
{
    struct node* past = NULL;

    while(head != NULL)
    {
        past = head;
        head = head -> next;
    }
    past -> next = new_node;
    new_node -> data = newdata;
    new_node -> next = NULL;

    return new_node;
}

// fazer func free

struct node* InsertAtSomeplace(struct node* head, struct node* new_node, struct person* newdata)
{
    struct node* after = NULL;

    while(strcmp(head -> data -> name, destino) != 0);
    {
        head = head -> next;
        after = head -> next;
    }
    if(head -> next == NULL)
    {
        InsertAtEnd();
        return;
    }
    // em fazedura
    past -> next = new_node;
    new_node -> next =
    return new_node;
}

void freelist(struct node* head)
{
    struct node* past = NULL;
    while(head != NULL)
    {
        free(head -> data);
        past = head;
        head = head -> next;
        free(past);
    }
}

int main()
{
    int option = 9;
    struct node *head = NULL;
    struct node *newnode = NULL;
    struct person *ptr = NULL;

    while(option != 0)
    {
        printf("Escolha uma Opcao\n");
        scanf("%d", &option);

        if(option == 1)
            {
                newnode = NewNode();
                ptr = New_Person();
                head = InsertAtHead(head, newnode, ptr);
            }
        else if(option == 2)
        {
            print(head, printPerson);
        }
        else if(option == 3)
        {
            freelist(head);
            head = NULL;
        }
        else if(option == 4)
        {
            newnode = NewNode();
            ptr = New_Person();
            InsertAtEnd(head, newnode, ptr);
        }
    }

    freelist(head);

    return 0;
}
