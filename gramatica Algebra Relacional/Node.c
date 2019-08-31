#include <stdio.h>
#include "Node.h"
#include "Stack.c"

NodeChar *attribute = NULL;
NodeChar *attribute2 = NULL;
NodeChar *predicate = NULL;

Node* _allocate_node() {
    return (Node *) malloc(sizeof(Node));
}

/*Adicionando novos símbolos a lista de predicado*/
void _add_symbols_predicate(char *symbol) {

    NodeChar *node = (NodeChar *) malloc(sizeof(NodeChar));
    node->name = symbol;

    if (!predicate) {
        predicate = node;
    } else {

        NodeChar *aux = predicate;
        while (aux->next != NULL) {
            aux = aux->next;
        }

        aux->next = node;
    }

}

/*Adicionando novos símbolos a lista de atributos*/
void _add_symbols_attribute(char *symbol, int option) {

    NodeChar *aux;

    if (option == 1) {
        aux = attribute;
    } else {
        aux = attribute2;
    }

    NodeChar *node = (NodeChar *) malloc(sizeof(NodeChar));
    node->name = symbol;

    if (!aux) {
        aux = node;
    } else {

        NodeChar *temp = aux;
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = node;
    }

    if (option == 1) {
        attribute = aux;
    } else {
        attribute2 = aux;
    }
}

/*Adicionando nós na pilha para ao fim apenas reajustar a árvore através da pilha*/
void _add_node_stack(char *s) {

    Node *node;
    node = _allocate_node();

    _get_node_type(node,s);
    _build_node(node);

/*Se tipo do no a ser inserido na pilha for um ')'
     * entao deve-ser desempilhar e ajustar árvore no sentido a direita
     * até encontrar '(' e por fim desempilhar '(' */
    if (node->type == CL_P) {

        Node *temp, *aux;
        temp = aux = NULL;

        while (top->node->type != OP_P) {

            if (temp == NULL) {
                temp = _pop();
            } else {

                aux = temp;
                temp = _pop();
                temp->right = aux;
            }
        }

        _pop();
        _push(temp);

    } else if (node->type == ASSIGNMENT) {
        Node *temp = _pop();
        node->left = temp;
        _push(node);

/*Se tipo do no a ser inserido na pilha for uma operação binária
      * entao deve-ser desempilhar até encontrar '('
         * e ajustar a árvore para que o lado esquerdo
         * da operação binária já fique pronto*/
    } else if (node->type == UNION || node->type == JOIN || node->type == CARTESIAN_PRODUCT ||
               node->type == SUBTRACTION || node->type == NATURAL_JOIN || node->type == DIVISION ||
               node->type == LEFT_OUTER_JOIN || node->type == RIGHT_OUTER_JOIN ||
               node->type == COMPLETE_OUTER_JOIN || node->type == INTERSECTION
            ) {

        Node *temp, *aux;
        temp = aux = NULL;

        while (top != NULL && top->node->type != OP_P && top->node->type != ASSIGNMENT) {

            if (temp == NULL) {
                temp = _pop();
            } else {

                aux = temp;
                temp = _pop();
                temp->right = aux;
            }
        }

        node->left = temp;
        _push(node);

    } else {

        _push(node);
    }

}

void _show_node_list(NodeChar *nodeList) {

    NodeChar *aux = nodeList;
    while (aux != NULL) {
        printf("%s", aux->name);
        aux = aux->next;
    }
}

void _show_node(Node *node, int b) {

    if (!node) {
        printf("*");
    } else {

        int i;
        for (i = 0; i < b; i++) printf("          ");

        switch (node->type) {

            case SELECTION:
                printf("SIGMA ");
                _show_node_list(node->predicate);
                printf("\n");
                break;

            case RELATION:
                printf("%s ", node->name);
                _show_node_list(node->attribute);
                printf("\n");
                break;

            case PROJECTION:
                printf("PI ");
                _show_node_list(node->attribute);
                printf("\n");
                break;

            case ASSIGNMENT:
                printf("ATRIBUICAO ");
                _show_node_list(node->attribute);
                printf("\n");
                break;

            case ASSIGNMENT2:
                printf("RHO ");
                _show_node_list(node->attribute);
                printf("\n");
                break;

            case UNION:
                printf("UNIAO ");
                printf("\n");
                break;

            case INTERSECTION:
                printf("INTERSECCAO ");
                printf("\n");
                break;

            case SUBTRACTION:
                printf("SUBTRACAO ");
                printf("\n");
                break;

            case CARTESIAN_PRODUCT:
                printf("PRODUTO_CARTESIANO ");
                printf("\n");
                break;

            case NATURAL_JOIN:
                printf("JUNCAO_NATURAL ");
                printf("\n");
                break;

            case JOIN:
                printf("JUNCAO ");
                _show_node_list(node->predicate);
                printf("\n");
                break;

            case DIVISION:
                printf("DIVISAO ");
                printf("\n");
                break;

            case F_SCRIPT:
                _show_node_list(node->attribute);
                printf(" FSCRIPT ");
                _show_node_list(node->attribute2);
                printf("\n");
                break;

            case LEFT_OUTER_JOIN:
                printf("JUNCAO_EXTERNA_ESQUERDA ");
                _show_node_list(node->predicate);
                printf("\n");
                break;

            case RIGHT_OUTER_JOIN:
                printf("JUNCAO_EXTERNA_DIREITA ");
                _show_node_list(node->predicate);
                printf("\n");
                break;

            case COMPLETE_OUTER_JOIN:
                printf("JUNCAO_EXTERNA_COMPLETA ");
                _show_node_list(node->predicate);
                printf("\n");
                break;

            default:
                return;
        }
    }
}

void _get_node_type(Node *node, char *s) {

    if (!strcmp("SIGMA", s)) {
        node->type = SELECTION;
    } else if (!strcmp("PI", s)) {
        node->type = PROJECTION;
    } else if (!strcmp("ATRIBUICAO", s)) {
        node->type = ASSIGNMENT;
    } else if (!strcmp("RHO", s)) {
        node->type = ASSIGNMENT2;
    } else if (!strcmp("JUNCAO", s)) {
        node->type = JOIN;
    } else if (!strcmp("UNIAO", s)) {
        node->type = UNION;
    } else if (!strcmp("INTERSECCAO", s)) {
        node->type = INTERSECTION;
    } else if (!strcmp("SUBTRACAO", s)) {
        node->type = SUBTRACTION;
    } else if (!strcmp("PRODUTO_CARTESIANO", s)) {
        node->type = CARTESIAN_PRODUCT;
    } else if (!strcmp("JUNCAO_NATURAL", s)) {
        node->type = NATURAL_JOIN;
    } else if (!strcmp("DIVISAO", s)) {
        node->type = DIVISION;
    } else if (!strcmp("FSCRIPT", s)) {
        node->type = F_SCRIPT;
    } else if (!strcmp("JUNCAO_EXTERNA_ESQUERDA", s)) {
        node->type = LEFT_OUTER_JOIN;
    } else if (!strcmp("JUNCAO_EXTERNA_DIREITA", s)) {
        node->type = RIGHT_OUTER_JOIN;
    } else if (!strcmp("JUNCAO_EXTERNA_COMPLETA", s)) {
        node->type = COMPLETE_OUTER_JOIN;
    } else if (!strcmp("(", s)) {
        node->type = OP_P;
    } else if (!strcmp(")", s)) {
        node->type = CL_P;
    } else {
        node->type = RELATION;
        node->name = s;
    }
}

void _build_node(Node *node){

    node->attribute = attribute;
    node->attribute2 = attribute2;
    node->predicate = predicate;
    node->right = node->left = NULL;

    //Restaurando variáveis globais para NULL, para usalás posteriormente.
    attribute = attribute2 = predicate = NULL;
}
