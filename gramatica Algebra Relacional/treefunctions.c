#include <stdio.h>
#include "treefunctions.h"
#include "stackNodes.c"

NodeList *attribute = NULL;
NodeList *attribute2 = NULL;
NodeList *predicate = NULL;

/*Inicializando a ferramenta*/
void _tool_initialize() {

    printf("Initializing...\n\n\n");
    create_stack();
    create_tree();

    return;
}

void create_tree() {
    root = NULL;
}

NodeTree *allocate_node() {
    return (NodeTree *) malloc(sizeof(NodeTree));
}

/*Adicionando novos símbolos a lista de predicado*/
void _add_symbols_predicate(char *symbol) {

    NodeList *node = (NodeList *) malloc(sizeof(NodeList));
    node->name = symbol;

    if (!predicate) {
        predicate = node;
    } else {

        NodeList *aux = predicate;
        while (aux->nodeNext != NULL) {
            aux = aux->nodeNext;
        }

        aux->nodeNext = node;
    }

}

/*Adicionando novos símbolos a lista de atributos*/
void _add_symbols_attribute(char *symbol, int option) {

    NodeList *aux;

    if (option == 1) {
        aux = attribute;
    } else {
        aux = attribute2;
    }

    NodeList *node = (NodeList *) malloc(sizeof(NodeList));
    node->name = symbol;

    if (!aux) {
        aux = node;
    } else {

        NodeList *temp = aux;
        while (temp->nodeNext != NULL) {
            temp = temp->nodeNext;
        }

        temp->nodeNext = node;
    }

    if (option == 1) {
        attribute = aux;
    } else {
        attribute2 = aux;
    }
}

/*Adicionando nós na pilha para ao fim apenas reajustar a árvore através da pilha*/
void _add_node_stack(char *s) {

    NodeTree *node;
    node = allocate_node();

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

    node->attribute = attribute;
    node->attribute2 = attribute2;
    node->predicate = predicate;
    node->nodeRight = node->nodeLeft = NULL;

//Restaurando variáveis globais para NULL, para usalás posteriormente.

    attribute = attribute2 = predicate = NULL;

/*Se tipo do no a ser inserido na pilha for um ')'
     * entao deve-ser desempilhar e ajustar árvore no sentido a direita
     * até encontrar '(' e por fim desempilhar '(' */

    if (node->type == CL_P) {

        NodeTree *temp, *aux;
        temp = aux = NULL;

        while (top->nodeTree->type != OP_P) {

            if (temp == NULL) {
                temp = pop();
            } else {

                aux = temp;
                temp = pop();
                temp->nodeRight = aux;
            }
        }

        pop();
        push(temp);

/*Se tipo do no a ser inserido na pilha for uma operação binária
      * entao deve-ser desempilhar até encontrar '('
         * e ajustar a árvore para que o lado esquerdo
         * da operação binária já fique pronto*/

    } else if (node->type == UNION || node->type == JOIN || node->type == CARTESIAN_PRODUCT ||
               node->type == SUBTRACTION || node->type == NATURAL_JOIN || node->type == DIVISION ||
               node->type == LEFT_OUTER_JOIN || node->type == RIGHT_OUTER_JOIN ||
               node->type == COMPLETE_OUTER_JOIN || node->type == ASSIGNMENT || node->type == INTERSECTION) {

        NodeTree *temp, *aux;
        temp = aux = NULL;

        while (top != NULL && top->nodeTree->type != OP_P && top->nodeTree->type != ASSIGNMENT) {

            if (temp == NULL) {
                temp = pop();
            } else {

                aux = temp;
                temp = pop();
                temp->nodeRight = aux;
            }
        }

        node->nodeLeft = temp;
        push(node);

    } else {
        push(node);
    }

}

/*
void _add_node_stack(NodeTreeType type, char *s, char *attribute,char *attribute2, char *predicate){

    NodeTree *node;
    node = allocate_node();

    node->type = type;
    node->name = s;
    node->attribute = attribute;
    node->attribute2 = attribute2;
    node->predicate = predicate;
    node->nodeRight = node->nodeLeft = NULL;

    */
/*Restaurando variáveis globais para NULL, para usalás posteriormente.*//*

    attribute = attribute2 = predicate = NULL;

    */
/*Se tipo do no a ser inserido na pilha for um ')'
     * entao deve-ser desempilhar e ajustar árvore no sentido a direita
     * até encontrar '(' e por fim desempilhar '('*//*

    if (node->type == CL_P) {

        NodeTree *temp, *aux;
        temp = aux = NULL;

        while (top->nodeTree->type != OP_P) {

            if (temp == NULL) {
                temp = pop();
            } else {

                aux = temp;
                temp = pop();
                temp->nodeRight = aux;
            }
        }

        pop();
        push(temp);

        */
/*Se tipo do no a ser inserido na pilha for uma operação binária
      * entao deve-ser desempilhar até encontrar '('
         * e ajustar a árvore para que o lado esquerdo
         * da operação binária já fique pronto *//*

    } else if (node->type == UNION || node->type == JOIN || node->type == CARTESIAN_PRODUCT ||
               node->type == SUBTRACTION || node->type == NATURAL_JOIN || node->type == DIVISION ||
               node->type == LEFT_OUTER_JOIN || node->type == RIGHT_OUTER_JOIN ||
               node->type == COMPLETE_OUTER_JOIN || node->type == ASSIGNMENT) {

        NodeTree *temp, *aux;
        temp = aux = NULL;

        while (top != NULL && top->nodeTree->type != OP_P && top->nodeTree->type != ASSIGNMENT) {

            if (temp == NULL) {
                temp = pop();
            } else {

                aux = temp;
                temp = pop();
                temp->nodeRight = aux;
            }
        }

        node->nodeLeft = temp;
        push(node);

    } else {
        push(node);
    }

}
*/

/*Função de construção da árvore logo após regras de parênteses tiverem sido executadas*/
void _build_tree() {

    NodeTree *actual = NULL;

    /*Enquanto houver elementos na pilha, desempilhar e empilhar a direita*/
    while (top != NULL) {

        actual = pop();

        if (actual != NULL) {

            if (!root) {
                root = actual;
            } else {
                actual->nodeRight = root;
                root = actual;
            }
        }
    }

    _show_tree(root, 0);

}

void _show_node_list(NodeList *nodeList) {

    NodeList *aux = nodeList;
    while (aux != NULL) {
        printf("%s", aux->name);
        aux = aux->nodeNext;
    }
}

void _show_tree(NodeTree *root, int b) {

    if (root == NULL) {
        _show_node(root, b);
        return;
    } else {
        _show_tree(root->nodeRight, b + 1);
        _show_node(root, b);
        _show_tree(root->nodeLeft, b + 1);
    }
}

void _show_node(NodeTree *nodeTree, int b) {

    if (!nodeTree) {
        printf("*");
    } else {

        int i;
        for (i = 0; i < b; i++) printf("          ");

        switch (nodeTree->type) {

            case SELECTION:
                printf("SIGMA ");
                _show_node_list(nodeTree->predicate);
                printf("\n");
                break;

            case RELATION:
                printf("%s ", nodeTree->name);
                _show_node_list(nodeTree->attribute);
                printf("\n");
                break;

            case PROJECTION:
                printf("PI ");
                _show_node_list(nodeTree->attribute);
                printf("\n");
                break;

            case ASSIGNMENT:
                printf("ATRIBUICAO ");
                _show_node_list(nodeTree->attribute);
                printf("\n");
                break;

            case ASSIGNMENT2:
                printf("RHO ");
                _show_node_list(nodeTree->attribute);
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
                _show_node_list(nodeTree->predicate);
                printf("\n");
                break;

            case DIVISION:
                printf("DIVISAO ");
                printf("\n");
                break;

            case F_SCRIPT:
                _show_node_list(nodeTree->attribute);
                printf(" FSCRIPT ");
                _show_node_list(nodeTree->attribute2);
                printf("\n");
                break;

            case LEFT_OUTER_JOIN:
                printf("JUNCAO_EXTERNA_ESQUERDA ");
                _show_node_list(nodeTree->predicate);
                printf("\n");
                break;

            case RIGHT_OUTER_JOIN:
                printf("JUNCAO_EXTERNA_DIREITA ");
                _show_node_list(nodeTree->predicate);
                printf("\n");
                break;

            case COMPLETE_OUTER_JOIN:
                printf("JUNCAO_EXTERNA_COMPLETA ");
                _show_node_list(nodeTree->predicate);
                printf("\n");
                break;

            default:
                return;
        }
    }
}
