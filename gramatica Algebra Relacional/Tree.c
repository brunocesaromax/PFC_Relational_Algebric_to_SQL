#include <stdio.h>
#include "Tree.h"

/*Inicializando a ferramenta*/
void _tool_initialize() {
    printf("Initializing...\n\n\n");
    _create_sub_tree_list();
    _start_data_structures();
    return;
}

void _create_tree() {
    root = (Tree *) malloc(sizeof(Tree));
    root->node = NULL;
}

/*Função de construção da árvore logo após regras de parênteses tiverem sido executadas*/
void _build_tree() {
    Node *actual = NULL;

    /*Enquanto houver elementos na pilha, desempilhar e empilhar a direita*/
    while (top != NULL) {
        actual = _pop();

        if (actual != NULL) {
            if (!root->node) {
                root->node = actual;
            } else {
                actual->right = root->node;
                root->node = actual;
            }
        }
    }

    _show_tree(root->node, 0);
    printf("\n*******************************************************************");
    printf("*********************************************************************\n");

    _start_data_structures();
}

/*root nessa caso é o primeiro nó da árvore "raíz"*/
void _show_tree(Node *root, int b) {
    if (root == NULL) {
        _show_node(root, b);
        return;
    } else {
        _show_tree(root->right, b + 1);
        _show_node(root, b);
        _show_tree(root->left, b + 1);
    }
}

void _start_data_structures() {
    free(root);
    free(top);
    root = top = NULL;

    _create_tree();
    _create_stack();

    printf("\n\n\n");
}