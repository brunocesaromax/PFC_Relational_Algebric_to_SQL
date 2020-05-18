#include <stdio.h>
#include <string.h>
#include "Node.h"
#include "Stack.c"
#include <cjson/cJSON.h>

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
                Node *nodeRHO = _get_first_RHO();

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

cJSON *_get_root_json(cJSON *nodeJson) {
    if (nodeJson->prev == NULL) {
        return nodeJson;
    } else {
        cJSON *temp = nodeJson;

        while (temp->prev != NULL) {
            temp = temp->prev;
        }

        return temp;
    }
}

void _show_node_list(NodeChar *nodeList) {
    NodeChar *aux = nodeList;
    while (aux != NULL) {
        printf("%s", aux->name);
        aux = aux->next;
    }
}

char *_get_node_name_by_direction(int direction) {
    if (direction == 0) {
        return NULL;
    } else if (direction == 1) {
        return "left";
    } else {
        return "right";
    }
}

//Como vai fazer com os nomes repetidos??
//cJSON *_refactor_tree_json(cJSON *rootJson, int direction, cJSON *new) {
//    cJSON *temp = cJSON_GetObjectItem(rootJson, _get_node_name_by_direction(direction));
//    cJSON *aux, *stackAux = temp;
//
//    while (cJSON_HasObjectItem(temp, _get_node_name_by_direction(direction))) {
//        temp = cJSON_GetObjectItem(temp, _get_node_name_by_direction(direction));
//
//        aux = stackAux;
//        while(aux->next != NULL){
//            aux = aux->next;
//        }
//
//        aux->next = temp;
//    }
//
//    printf("\n\nSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSs\n\n");
//    char *out = cJSON_Print(temp);
//    printf("%s\n", out);
//    printf("\n\nSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSs\n\n");
//    return temp;
//}

void _show_node(Node *node, int b, cJSON *rootJson, int direction) {
    if (!node) {
        printf("*");
    } else {
        int i;
        for (i = 0; i < b; i++) printf("          ");

        cJSON *parentRoot, *nodeJson, *predicateJson, *attributeJson, *attribute2Json, *typeJson, *name;

        if (direction == 0) {
            nodeJson = rootJson;
        } else {
            nodeJson = cJSON_CreateObject();
        }

        typeJson = cJSON_CreateString(_string_from_node_type(node->type));
        cJSON_AddItemToObject(nodeJson, "type", typeJson);

        switch (node->type) {
            case SELECTION:
                //todo: fazer extração do trecho de código a seguir em metódo externo
                predicateJson = cJSON_CreateArray();
                _add_items_array(node->predicate, predicateJson);
                cJSON_AddItemToObject(nodeJson, "predicate", predicateJson);

//                mudar posteriormente
                nodeJson->prev = rootJson->prev;
                rootJson = nodeJson;

//              Necessário pegar o root pois nele que é inserido as mudanças
                parentRoot = _get_root_json(rootJson);
                if (cJSON_HasObjectItem(parentRoot, "right")) {
                    cJSON *temp = cJSON_GetObjectItem(parentRoot, "right");
                    cJSON_AddItemToObject(temp, _get_node_name_by_direction(direction), rootJson);
                    cJSON_ReplaceItemInObject(parentRoot, "right", temp);
//                    char *out = cJSON_Print(aux);
//                    printf("%s\n", out);
                } else {
                    cJSON_AddItemToObject(parentRoot, _get_node_name_by_direction(direction), rootJson);
                }

//                printf("\n\nSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSs\n\n");
//                char *out = cJSON_Print(rootJson);
//                printf("%s\n", out);
//                printf("\n\nSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSs\n\n");

                printf("SIGMA ");
                _show_node_list(node->predicate);
                printf("\n");
                break;

            case RELATION:
                attributeJson = cJSON_CreateArray();
                _add_items_array(node->attribute, attributeJson);
                name = cJSON_CreateString(node->name);
                cJSON_AddItemToObject(nodeJson, "name", name);
                cJSON_AddItemToObject(nodeJson, "attribute", attributeJson);
//                cJSON_AddItemToObject(rootJson, _get_node_name_by_direction(direction), nodeJson);

//                mudar posteriormente
                nodeJson->prev = rootJson->prev;
                rootJson = nodeJson;

//              Necessário pegar o root pois nele que é inserido as mudanças
                parentRoot = _get_root_json(rootJson);
//                if(rootJson->prev != NULL) {
//                    printf("\n\nSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSs\n\n");
//                    char *out = cJSON_Print(rootJson->prev);
//                    printf("%s\n", out);
//                    printf("\n\nSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSs\n\n");
//                }
                if (cJSON_HasObjectItem(parentRoot, "right")) {
//                    _cJSON_GetObjectItem(parentRoot, "right")
                    cJSON *temp = cJSON_GetObjectItem(parentRoot, "right");
                    cJSON_AddItemToObject(temp, _get_node_name_by_direction(direction), rootJson);
                    cJSON_ReplaceItemInObject(parentRoot, "right", temp);
//                    char *out = cJSON_Print(aux);
//                    printf("%s\n", out);
                } else {
                    cJSON_AddItemToObject(parentRoot, _get_node_name_by_direction(direction), rootJson);
                }

                printf("%s ", node->name);
                _show_node_list(node->attribute);
                printf("\n");
                break;

            case PROJECTION:
                attributeJson = cJSON_CreateArray();
                _add_items_array(node->attribute, attributeJson);
                cJSON_AddItemToObject(nodeJson, "attribute", attributeJson);
                //todo: nós não podem ter o mesmo nome, pensar em solução
                cJSON_AddItemToObject(rootJson, _get_node_name_by_direction(direction), nodeJson);

                printf("PI ");
                _show_node_list(node->attribute);
                printf("\n");
                break;

            case ASSIGNMENT:
                //todo: nós não podem ter o mesmo nome, pensar em solução
                cJSON_AddItemToObject(rootJson, _get_node_name_by_direction(direction), nodeJson);

                printf("ASSIGNMENT ");
                printf("\n");
                break;

            case ASSIGNMENT_RHO:
                attributeJson = cJSON_CreateArray();
                _add_items_array(node->attribute, attributeJson);
                cJSON_AddItemToObject(nodeJson, "attribute", attributeJson);
                //todo: nós não podem ter o mesmo nome, pensar em solução
                cJSON_AddItemToObject(rootJson, _get_node_name_by_direction(direction), nodeJson);

                printf("RHO ");
                _show_node_list(node->attribute);
                printf("\n");
                break;

            case UNION:
                //todo: nós não podem ter o mesmo nome, pensar em solução
                cJSON_AddItemToObject(rootJson, _get_node_name_by_direction(direction), nodeJson);

                printf("UNION ");
                printf("\n");
                break;

            case INTERSECTION:
                //todo: nós não podem ter o mesmo nome, pensar em solução
                cJSON_AddItemToObject(rootJson, _get_node_name_by_direction(direction), nodeJson);

                printf("INTERSECTION ");
                printf("\n");
                break;

            case SUBTRACTION:
                //todo: nós não podem ter o mesmo nome, pensar em solução
                cJSON_AddItemToObject(rootJson, _get_node_name_by_direction(direction), nodeJson);

                printf("SUBTRACTION ");
                printf("\n");
                break;

            case CARTESIAN_PRODUCT:
                //todo: nós não podem ter o mesmo nome, pensar em solução
                cJSON_AddItemToObject(rootJson, _get_node_name_by_direction(direction), nodeJson);

                printf("PRODUCT_CARTESIAN ");
                printf("\n");
                break;

            case NATURAL_JOIN:
                //todo: nós não podem ter o mesmo nome, pensar em solução
                cJSON_AddItemToObject(rootJson, _get_node_name_by_direction(direction), nodeJson);

                printf("NATURAL_JOIN ");
                printf("\n");
                break;

            case JOIN:
                predicateJson = cJSON_CreateArray();
                _add_items_array(node->predicate, predicateJson);
                cJSON_AddItemToObject(nodeJson, "predicate", predicateJson);
                cJSON_AddItemToObject(rootJson, _get_node_name_by_direction(direction), nodeJson);

                printf("JOIN ");
                _show_node_list(node->predicate);
                printf("\n");
                break;

            case DIVISION:
                //todo: nós não podem ter o mesmo nome, pensar em solução
                cJSON_AddItemToObject(rootJson, _get_node_name_by_direction(direction), nodeJson);

                printf("DIVISION ");
                printf("\n");
                break;

            case F_SCRIPT:
                attributeJson = cJSON_CreateArray();
                attribute2Json = cJSON_CreateArray();

                _add_items_array(node->attribute, attributeJson);
                _add_items_array(node->attribute2, attribute2Json);

                cJSON_AddItemToObject(nodeJson, "attribute", attributeJson);
                cJSON_AddItemToObject(nodeJson, "attribute2", attribute2Json);
                cJSON_AddItemToObject(rootJson, _get_node_name_by_direction(direction), nodeJson);

                _show_node_list(node->attribute);
                printf(" FSCRIPT ");
                _show_node_list(node->attribute2);
                printf("\n");
                break;

            case LEFT_OUTER_JOIN:
                predicateJson = cJSON_CreateArray();
                _add_items_array(node->predicate, predicateJson);
                cJSON_AddItemToObject(nodeJson, "predicate", predicateJson);
                cJSON_AddItemToObject(rootJson, _get_node_name_by_direction(direction), nodeJson);

                printf("LEFT_OUTER_JOIN ");
                _show_node_list(node->predicate);
                printf("\n");
                break;

            case RIGHT_OUTER_JOIN:
                predicateJson = cJSON_CreateArray();
                _add_items_array(node->predicate, predicateJson);
                cJSON_AddItemToObject(nodeJson, "predicate", predicateJson);
                cJSON_AddItemToObject(rootJson, _get_node_name_by_direction(direction), nodeJson);

                printf("RIGHT_OUTER_JOIN ");
                _show_node_list(node->predicate);
                printf("\n");
                break;

            case COMPLETE_OUTER_JOIN:
                predicateJson = cJSON_CreateArray();
                _add_items_array(node->predicate, predicateJson);
                cJSON_AddItemToObject(nodeJson, "predicate", predicateJson);
                cJSON_AddItemToObject(rootJson, _get_node_name_by_direction(direction), nodeJson);

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
    if (node->type == OPEN_PARENTHESES && !_stack_is_empty()) {
        Node *top = _top_element();

        if (top->type == ASSIGNMENT_RHO) {
            if (top->left == NULL) {
                Node *nodeNew = _allocate_node();
                nodeNew->attribute = attribute;
                nodeNew->type = RELATION;
                nodeNew->left = nodeNew->right = NULL;
                top->left = nodeNew;

            } else if (top->left->type == RELATION) {
                top->left->attribute = attribute;
            }

            attribute = NULL;
        }
    }

    node->attribute = attribute;
    node->attribute2 = attribute2;
    node->predicate = predicate;
    node->left = node->right = NULL;

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

char *_get_node_type_name(enum nodeType type) {
    switch (type) {
        case RELATION:
            return "RELATION";
        case SELECTION:
            return "SELECTION";
        case PROJECTION:
            return "PROJECTION";
        case ASSIGNMENT:
            return "ASSIGNMENT";
        case ASSIGNMENT_RHO:
            return "ASSIGNMENT_RHO";
        case JOIN:
            return "JOIN";
        case NATURAL_JOIN:
            return "NATURAL_JOIN";
        case UNION:
            return "UNION";
        case INTERSECTION:
            return "INTERSECTION";
        case SUBTRACTION:
            return "SUBTRACTION";
        case CARTESIAN_PRODUCT:
            return "CARTESIAN_PRODUCT";
        case DIVISION:
            return "DIVISION";
        case F_SCRIPT:
            return "F_SCRIPT";
        case LEFT_OUTER_JOIN:
            return "LEFT_OUTER_JOIN";
        case RIGHT_OUTER_JOIN:
            return "RIGHT_OUTER_JOIN";
        case COMPLETE_OUTER_JOIN:
            return "COMPLETE_OUTER_JOIN";
        case OPEN_PARENTHESES:
            return "OPEN_PARENTHESES";
        case CLOSE_PARENTHESES:
            return "CLOSE_PARENTHESES";
    }
}

void _add_sub_tree(Node *node) {
    if (subTreeList == NULL) {
        subTreeList = (SubTreeList *) malloc(sizeof(SubTreeList));
        subTreeList->name = node->left->name;
        subTreeList->node = node;
        subTreeList->next = NULL;
    } else {
        if (_exists_sub_tree_same_name(node->left->name) == 0) {
            SubTreeList *new = (SubTreeList *) malloc(sizeof(SubTreeList));
            new->name = node->left->name;
            new->node = node;
            new->next = NULL;

            SubTreeList *aux = subTreeList;

            while (aux->next != NULL) {
                aux = aux->next;
            }

            aux->next = new;
        }
    }
}

void _create_sub_tree_list() {
    subTreeList = NULL;
}

Node *_get_sub_tree_or_node(Node *node) {
    SubTreeList *aux = subTreeList;
    while (aux != NULL) {
        if (strcmp(aux->name, node->name) == 0) {
            return aux->node;
        }

        aux = aux->next;
    }

    return node;
}

int _exists_sub_tree_same_name(char *name) {
    SubTreeList *aux = subTreeList;

    while (aux != NULL) {
        if (strcmp(aux->name, name) == 0) {
            return 1;
        }

        aux = aux->next;
    }

    return 0;
}

void _add_items_array(NodeChar *items, cJSON *array) {
    NodeChar *aux = items;
    while (aux != NULL) {
        cJSON_AddItemToArray(array, cJSON_CreateString(aux->name));
        aux = aux->next;
    }
}