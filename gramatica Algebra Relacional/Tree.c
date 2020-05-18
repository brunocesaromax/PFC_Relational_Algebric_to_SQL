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

    _show_tree(root->node, 0, rootJson, 0);
    printf("\n*******************************************************************");
    printf("*********************************************************************\n");
//    cJSON_DeleteItemFromObjectCaseSensitive(rootJson, "right");
    char *out = cJSON_Print(rootJson);
    printf("%s\n", out);

    _start_data_structures();
}

/*root nessa caso é o primeiro nó da árvore "raíz"*/
void _show_tree(Node *root, int b, cJSON *rootJson, int direction) {
    if (root == NULL) {
        _show_node(root, b, rootJson->next, direction);
        return;
    } else {
        if(root->left != NULL){
            rootJson->next = cJSON_CreateObject();
            rootJson->next->prev = rootJson;
            _show_tree(root->left, b + 1, rootJson->next, 1);
        }else{
            _show_tree(root->left, b + 1, rootJson, 1);
        }

        _show_node(root, b, rootJson, direction);

        if(root->right != NULL){
            rootJson->next = cJSON_CreateObject();
            rootJson->next->prev = rootJson;
            _show_tree(root->right, b + 1, rootJson->next, 2);
        }else{
            _show_tree(root->right, b + 1, rootJson, 2);
        }
    }
}

void testJSON(Node *root, cJSON *rootJson) {
    if (root != NULL) {
        Node *aux = root;
        while (aux->left != NULL) {
            aux = aux->left;
        }


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
    cJSON_SetNumberValue(rootJson, 0);
//    cJSON_SetNumberValue(rootJson, 2);
//    printf("TIPO: %d\n", rootJson->valueint);


    printf("\n\n\n");
}