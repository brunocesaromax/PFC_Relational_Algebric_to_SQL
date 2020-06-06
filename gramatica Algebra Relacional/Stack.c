#include "Stack.h"

void _create_stack() {
    top = NULL;
}

void _push(Node *node) {
    if (top == NULL) {
        top = (Stack *) malloc(1 * sizeof(Stack));
        top->node = node;
        top->next = NULL;

    } else {
        Stack *temp = (Stack *) malloc(1 * sizeof(Stack));
        temp->next = top;
        temp->node = node;
        top = temp;
    }
}

Node *_pop() {
    Stack *temp = top;

    if (temp == NULL) {
        return NULL;
    } else {
        top = top->next;
        return temp->node;
    }
}

Node *_top_element() {
    return (top->node);
}

int _stack_is_empty() {
    if (top == NULL)
        return 1;
    else
        return 0;
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
        _add_sub_tree(node);

    } else if (node->type == RELATION) {
        if (_stack_is_empty()) {
            _push(node);
        } else {
            Node *temp = _pop();

            if (temp->type == ASSIGNMENT_RHO) {
                temp->left = _get_sub_tree_or_node(node);
                _push(temp);
                _add_sub_tree(temp);

            } else if (temp->type == OPEN_PARENTHESES) {
                Node *nodeRHO = _get_first_rho_node_in_stack();

                //Ex: PROJETO_DEP ASSIGNMENT PROJETO NATURAL_JOIN RHO (Dnome, Dnum, Cpf_gerente, Data_inicio_gerente)(DEPARTAMENTO)
                if (nodeRHO != NULL && nodeRHO->left->name == NULL) {
                    nodeRHO->left->name = node->name;
                }

                _push(temp);
                _push(_get_sub_tree_or_node(node));

            } else {
                _push(temp);
                _push(_get_sub_tree_or_node(node));
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

        /*Adicionar subárvore existente a esquerda de um nó de operação binária
         * somente se as condições a seguir forem satisfeitas*/
        if ((top->node->type == ASSIGNMENT || top->node->type == ASSIGNMENT_RHO)
            && top->node->left != NULL && _exists_sub_tree_same_name(top->node->left->name) && temp == NULL) {
            temp = _pop();
        }

        node->left = temp;
        _push(node);

    } else {
        _push(node);
    }
}

Node *_get_first_rho_node_in_stack() {
    Stack *temp = top;
    Node *rho = NULL;

    while (temp != NULL) {
        if (temp->node->type == ASSIGNMENT_RHO) {
            rho = temp->node;
        }

        temp = temp->next;
    }

    return rho;
}

void _display_stack() {
    Stack *temp = top;

    if (temp == NULL) {
        printf("Stack is empty");
        return;
    }

    while (temp != NULL) {
        _show_node_stack(temp->node, 0);
        temp = temp->next;
    }
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
                _show_node_list(node->pred);
                printf("\n");
                break;

            case RELATION:
                printf("%s ", node->name);
                _show_node_list(node->attr);
                printf("\n");
                break;

            case PROJECTION:
                printf("PI ");
                _show_node_list(node->attr);
                printf("\n");
                break;

            case ASSIGNMENT:
                printf("ASSIGNMENT ");
                _show_node_list(node->attr);
                printf("\n");
                break;

            case ASSIGNMENT_RHO:
                printf("RHO ");
                _show_node_list(node->attr);
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
                _show_node_list(node->pred);
                printf("\n");
                break;

            case DIVISION:
                printf("DIVISION ");
                printf("\n");
                break;

            case F_SCRIPT:
                _show_node_list(node->attr);
                printf(" FSCRIPT ");
                _show_node_list(node->comp);
                printf("\n");
                break;

            case LEFT_OUTER_JOIN:
                printf("LEFT_OUTER_JOIN ");
                _show_node_list(node->pred);
                printf("\n");
                break;

            case RIGHT_OUTER_JOIN:
                printf("RIGHT_OUTER_JOIN ");
                _show_node_list(node->pred);
                printf("\n");
                break;

            case COMPLETE_OUTER_JOIN:
                printf("COMPLETE_OUTER_JOIN ");
                _show_node_list(node->pred);
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
