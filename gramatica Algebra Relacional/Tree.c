#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

/*Inicializando a ferramenta*/
void _tool_initialize() {
    printf("Initializing...\n\n\n");
    _create_sub_tree_list();
    _start_data_structures();


//    cJSON *root, *names, *ages;
//    root  = cJSON_CreateObject();
//    names = cJSON_CreateArray();
//    ages  = cJSON_CreateArray();
//    cJSON_AddItemToArray(names, cJSON_CreateString("Arroz"));
//    cJSON_AddItemToArray(names, cJSON_CreateString("feijao"));
//
//    cJSON_AddItemToObject(root, "name", names);
//    cJSON_AddItemToObject(root, "age", ages);
//    char *out = cJSON_Print(root);
//    printf("%s\n",out);

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

    _show_tree(root->node, 0, rootJson);
    printf("\n*******************************************************************");
    printf("*********************************************************************\n");

    _start_data_structures();
}

/*root nessa caso é o primeiro nó da árvore "raíz"*/
void _show_tree(Node *root, int b, cJSON *rootJson) {
    if (root == NULL) {
        _show_node(root, b, rootJson);
        return;
    } else {
        _show_tree(root->right, b + 1, cJSON_CreateObject());
        _show_node(root, b, rootJson);
        _show_tree(root->left, b + 1, cJSON_CreateObject());
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