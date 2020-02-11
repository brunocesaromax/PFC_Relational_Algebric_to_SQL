#include "Stack.h"

void _create_stack() {
    top = NULL;
}

void _push(Node *node) {

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

Node* _pop() {
    struct stack *temp = top;
    if (temp == NULL) {
        return NULL;
    } else {
        top = top->next;
        return temp->node;
    }
}

void _display_stack() {
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

Node* _top_element() {
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

            case OPEN_PARENTHESES:
                printf("( ");
                printf("\n");
                break;

            default:
                return;
        }
    }
}

int _stack_is_empty(){
    if (top == NULL)
        return 1;
    else
        return 0;
}