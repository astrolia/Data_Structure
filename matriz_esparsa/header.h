#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

typedef struct Node
{
    int linha;
    int coluna;
    int data;
    struct Node* Linha;
    struct Node* Coluna;
}Node;

typedef struct Node* p_node;
p_node criar_lista_linha();
p_node criar_lista_coluna();
p_node new_node(int ll, int cc, int x);
p_node add_node_linha(p_node lista, p_node elemento);
p_node maior_elemento_linha(p_node lista, p_node novoelemento);
p_node elemento_existe_linha(p_node lista, p_node elemento);
void delete_lista(p_node lista);
void print_list(p_node lista);
p_node add_node_coluna(p_node lista, p_node elemento);
p_node maior_elemento_coluna(p_node lista, p_node novoelemento);
p_node elemento_existe_coluna(p_node lista, p_node elemento);
void delete_lista_coluna(p_node lista);
void print_list_coluna(p_node lista);
p_node deletar(p_node lista, int linha, int coluna);


#endif // HEADER_H_INCLUDED
