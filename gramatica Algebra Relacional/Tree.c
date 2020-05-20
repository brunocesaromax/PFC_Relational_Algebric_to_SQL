#include <stdio.h>
#include <stdlib.h>
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

    _show_tree(root->node, 0, rootJson, 0, 0, 0);
    printf("\n*******************************************************************");
    printf("*********************************************************************\n");
    char *out = cJSON_Print(rootJson);
    printf("%s\n", out);

    _start_data_structures();
}

/*root nessa caso é o primeiro nó da árvore "raíz"*/
void _show_tree(Node *root, int b, cJSON *rootJson, int direction, int currentLeft, int currentRight) {
    if (root == NULL) {
        _show_node(root, b, rootJson->next, direction, currentLeft, currentRight);
        return;
    } else {
        //todo: Pensar no caso de nó binário
        if(_node_type_is_operation_binary(root->type)){
            rootJson->next = _build_node_json(root->left);
            cJSON_SetNumberValue(rootJson->next,1);//1 == left
        }else{
            _show_tree(root->left, b + 1, rootJson, 1, currentLeft + 1, currentRight);
        }
        _show_node(root, b, rootJson, direction, currentLeft, currentRight);
        _show_tree(root->right, b + 1, rootJson, 2, currentLeft, currentRight + 1);
    }
}

void _start_data_structures() {
    free(root);
    free(top);
    cJSON_Delete(rootJson);

    root = top = rootJson = NULL;

    _create_tree();
    _create_stack();
    rootJson = cJSON_CreateObject();

    printf("\n\n\n");
}