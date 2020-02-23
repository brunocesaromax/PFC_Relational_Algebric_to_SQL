#include <stdio.h>
#include "Node.h"
#include "Stack.c"

NodeChar *attribute = NULL;
NodeChar *attribute2 = NULL;
NodeChar *predicate = NULL;

Node *_allocate_node() {
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

    _get_node_type(node, s);
    _build_node(node);

/*Se tipo do no a ser inserido na pilha for um ')'
     * entao deve-ser desempilhar e ajustar árvore no sentido a direita
     * até encontrar '(' e por fim desempilhar '(' */
    if (node->type == CLOSE_PARENTHESES) {
        Node *temp, *aux;
        temp = aux = NULL;

        while (top->node->type != OPEN_PARENTHESES) {
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

    } else if (node->type == RELATION) {
        if (_stack_is_empty()) {
            _push(node);
        } else {
            Node *temp = _pop();

            if (temp->type == ASSIGNMENT_RHO) {
                temp->left = node;
                _push(temp);
            } else {
                _push(temp);
                _push(node);
            }
        }

/*Se tipo do no a ser inserido na pilha for uma operação binária
      * entao deve-ser desempilhar até encontrar '('
         * e ajustar a árvore para que o lado esquerdo
         * da operação binária já fique pronto*/
    } else if (_node_type_is_operation_binary(node->type)) {
        Node *temp, *aux;
        temp = aux = NULL;

        while (top != NULL && top->node->type != OPEN_PARENTHESES && top->node->type != ASSIGNMENT) {
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
                printf("ASSIGNMENT ");
                _show_node_list(node->attribute);
                printf("\n");
                break;

            case ASSIGNMENT_RHO:
                printf("RHO ");
                _show_node_list(node->attribute);
                printf("\n");
                break;

            case UNION:
                printf("UNION ");
                printf("\n");
                break;

            case INTERSECTION:
                printf("INTERSECTION ");
                printf("\n");
                break;

            case SUBTRACTION:
                printf("SUBTRACTION ");
                printf("\n");
                break;

            case CARTESIAN_PRODUCT:
                printf("PRODUCT_CARTESIAN ");
                printf("\n");
                break;

            case NATURAL_JOIN:
                printf("NATURAL_JOIN ");
                printf("\n");
                break;

            case JOIN:
                printf("JOIN ");
                _show_node_list(node->predicate);
                printf("\n");
                break;

            case DIVISION:
                printf("DIVISION ");
                printf("\n");
                break;

            case F_SCRIPT:
                _show_node_list(node->attribute);
                printf(" FSCRIPT ");
                _show_node_list(node->attribute2);
                printf("\n");
                break;

            case LEFT_OUTER_JOIN:
                printf("LEFT_OUTER_JOIN ");
                _show_node_list(node->predicate);
                printf("\n");
                break;

            case RIGHT_OUTER_JOIN:
                printf("RIGHT_OUTER_JOIN ");
                _show_node_list(node->predicate);
                printf("\n");
                break;

            case COMPLETE_OUTER_JOIN:
                printf("COMPLETE_OUTER_JOIN ");
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
    } else if (!strcmp("ASSIGNMENT", s)) {
        node->type = ASSIGNMENT;
    } else if (!strcmp("RHO", s)) {
        node->type = ASSIGNMENT_RHO;
    } else if (!strcmp("JOIN", s)) {
        node->type = JOIN;
    } else if (!strcmp("UNION", s)) {
        node->type = UNION;
    } else if (!strcmp("INTERSECTION", s)) {
        node->type = INTERSECTION;
    } else if (!strcmp("SUBTRACTION", s)) {
        node->type = SUBTRACTION;
    } else if (!strcmp("PRODUCT_CARTESIAN", s)) {
        node->type = CARTESIAN_PRODUCT;
    } else if (!strcmp("NATURAL_JOIN", s)) {
        node->type = NATURAL_JOIN;
    } else if (!strcmp("DIVISION", s)) {
        node->type = DIVISION;
    } else if (!strcmp("FSCRIPT", s)) {
        node->type = F_SCRIPT;
    } else if (!strcmp("LEFT_OUTER_JOIN", s)) {
        node->type = LEFT_OUTER_JOIN;
    } else if (!strcmp("RIGHT_OUTER_JOIN", s)) {
        node->type = RIGHT_OUTER_JOIN;
    } else if (!strcmp("COMPLETE_OUTER_JOIN", s)) {
        node->type = COMPLETE_OUTER_JOIN;
    } else if (!strcmp("(", s)) {
        node->type = OPEN_PARENTHESES;
    } else if (!strcmp(")", s)) {
        node->type = CLOSE_PARENTHESES;
    } else {
        node->type = RELATION;
        node->name = s;
    }
}

void _build_node(Node *node) {
    node->attribute = attribute;
    node->attribute2 = attribute2;
    node->predicate = predicate;
    node->right = node->left = NULL;

    //Restaurando variáveis globais para NULL, para usalás posteriormente.
    attribute = attribute2 = predicate = NULL;
}

int _node_type_is_operation_binary(NodeType type) {
    if (type == UNION || type == JOIN || type == CARTESIAN_PRODUCT ||
        type == SUBTRACTION || type == NATURAL_JOIN || type == DIVISION ||
        type == LEFT_OUTER_JOIN || type == RIGHT_OUTER_JOIN ||
        type == COMPLETE_OUTER_JOIN || type == INTERSECTION) {
        return 1;
    } else {
        return 0;
    }
}