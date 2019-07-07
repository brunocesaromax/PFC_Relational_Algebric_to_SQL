#include "stackNodes.h"

void create_stack() {
    top = NULL;
}

void push(NodeTree *node) {

    if (top == NULL) {

        top = (struct stack *) malloc(1 * sizeof(struct stack));
        top->nodeTree = node;
        top->next = NULL;

    } else {

        struct stack *temp = (struct stack *) malloc(1 * sizeof(struct stack));
        temp->next = top;
        temp->nodeTree = node;
        top = temp;
    }
}

NodeTree *pop() {

    struct stack *temp = top;

    if (temp == NULL) {
        return NULL;

    } else {

        top = top->next;
        return temp->nodeTree;
    }
}

void display_stack() {
    struct stack *temp = top;

    if (temp == NULL) {
        printf("Stack is empty");
        return;
    }

    while (temp != NULL) {

        _show_node_stack(temp->nodeTree, 0);
        temp = temp->next;
    }
}

NodeTree *top_element() {
    return (top->nodeTree);
}

void _show_node_stack(NodeTree *nodeTree, int b) {

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

            case OP_P:
                printf("( ");
                printf("\n");
                break;

            default:
                return;
        }
    }
}