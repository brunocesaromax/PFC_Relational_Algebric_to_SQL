#include "Stack.h"

void create_stack() {
    top = NULL;
}

void push(Node *node) {

    if (top == NULL) {

        top = (struct stack *) malloc(1 * sizeof(struct stack));
        top->node = node;
        top->next = NULL;

    } else {

        struct stack *temp = (struct stack *) malloc(1 * sizeof(struct stack));
        temp->next = top;
        temp->node = node;
        top = temp;
    }
}

Node *pop() {

    struct stack *temp = top;

    if (temp == NULL) {
        return NULL;

    } else {

        top = top->next;
        return temp->node;
    }
}

void display_stack() {
    struct stack *temp = top;

    if (temp == NULL) {
        printf("Stack is empty");
        return;
    }

    while (temp != NULL) {

        _show_node_stack(temp->node, 0);
        temp = temp->next;
    }
}

Node *top_element() {
    return (top->node);
}

void _show_node_stack(Node *node, int b) {

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

            case OP_P:
                printf("( ");
                printf("\n");
                break;

            default:
                return;
        }
    }
}