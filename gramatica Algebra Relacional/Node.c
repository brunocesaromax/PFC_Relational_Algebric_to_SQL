#include "Node.h"
#include "Stack.c"
#include "Json.c"

/*Inicializando a ferramenta*/
void _tool_initialize() {
    printf("Initializing...\n\n\n");
    _start_data_structures();
}

void _create_tree() {
    rootTree = NULL;
}

/*Função de construção da árvore logo após regras de parênteses tiverem sido executadas*/
void _build_tree() {
    Node *actual = NULL;

    /*Enquanto houver elementos na pilha, desempilhar e empilhar a direita*/
    while (top != NULL) {
        actual = _pop();

        if (actual != NULL) {
            if (!rootTree) {
                rootTree = actual;
            } else {
                actual->right = rootTree;
                rootTree = actual;
            }
        }
    }

    _show_tree(rootTree, 0, rootJson, 0, 0, 0);
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
        //todo: separar o add node in json em outra função e nao dentro do show_node
        if ((_node_type_is_operation_binary(root->type) || root->type == ASSIGNMENT)
            && (root != rootTree)) {
            rootJson->next = _build_node_json(root->left);
            cJSON_SetNumberValue(rootJson->next, 1);
        } else {
            _show_tree(root->left, b + 1, rootJson, 1, currentLeft + 1, currentRight);
        }
        _show_node(root, b, rootJson, direction, currentLeft, currentRight);
        _show_tree(root->right, b + 1, rootJson, 2, currentLeft, currentRight + 1);
    }
}

void _start_data_structures() {
    free(rootTree);
    free(top);
    cJSON_Delete(rootJson);

    rootTree = top = rootJson = NULL;

    _create_tree();
    _create_stack();
    _create_sub_tree_list();
    rootJson = cJSON_CreateObject();

    printf("\n\n\n");
}

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

void _show_node_list(NodeChar *nodeList) {
    NodeChar *aux = nodeList;
    while (aux != NULL) {
        printf("%s", aux->name);
        aux = aux->next;
    }
}

void _show_node(Node *node, int b, cJSON *rootJson, int direction, int currentLeft, int currentRight) {
    if (!node) {
        printf("*");
    } else {
        int i;
        for (i = 0; i < b; i++) printf("          ");

        cJSON *nodeJson, *predicateJson, *attributeJson, *attribute2Json, *typeJson, *name;

        if (direction == 0) {
            nodeJson = rootJson;
        } else {
            nodeJson = cJSON_CreateObject();
        }

//        printf("\n\nLeft: %d\n\n", currentLeft);
//        printf("\n\nRight: %d\n\n", currentRight);

        typeJson = cJSON_CreateString(_string_from_node_type(node->type));
        cJSON_AddItemToObject(nodeJson, "type", typeJson);

        switch (node->type) {
            case SELECTION:
                //todo: fazer extração do trecho de código a seguir em metódo externo
                predicateJson = cJSON_CreateArray();
                _add_items_array_json(node->predicate, predicateJson);
                cJSON_AddItemToObject(nodeJson, "predicate", predicateJson);
                _add_node_in_json(rootJson, nodeJson, direction, direction == 1 ? currentLeft : currentRight,
                                  _node_type_is_operation_binary_or_assignment(node->type));

                printf("SIGMA ");
                _show_node_list(node->predicate);
                printf("\n");
                break;

            case RELATION:
                attributeJson = cJSON_CreateArray();
                _add_items_array_json(node->attribute, attributeJson);
                name = cJSON_CreateString(node->name);
                cJSON_AddItemToObject(nodeJson, "name", name);
                cJSON_AddItemToObject(nodeJson, "attribute", attributeJson);
                _add_node_in_json(rootJson, nodeJson, direction, direction == 1 ? currentLeft : currentRight,
                                  _node_type_is_operation_binary_or_assignment(node->type));
                printf("%s ", node->name);
                _show_node_list(node->attribute);
                printf("\n");
                break;

            case PROJECTION:
                attributeJson = cJSON_CreateArray();
                _add_items_array_json(node->attribute, attributeJson);
                cJSON_AddItemToObject(nodeJson, "attribute", attributeJson);
                _add_node_in_json(rootJson, nodeJson, direction, direction == 1 ? currentLeft : currentRight,
                                  _node_type_is_operation_binary_or_assignment(node->type));
                printf("PI ");
                _show_node_list(node->attribute);
                printf("\n");
                break;

            case ASSIGNMENT:
                //todo: nós não podem ter o mesmo nome, pensar em solução
                _add_node_in_json(rootJson, nodeJson, direction, direction == 1 ? currentLeft : currentRight,
                                  _node_type_is_operation_binary_or_assignment(node->type));
                printf("ASSIGNMENT ");
                printf("\n");
                break;

            case ASSIGNMENT_RHO:
                attributeJson = cJSON_CreateArray();
                _add_items_array_json(node->attribute, attributeJson);
                cJSON_AddItemToObject(nodeJson, "attribute", attributeJson);
                //todo: nós não podem ter o mesmo nome, pensar em solução
                _add_node_in_json(rootJson, nodeJson, direction, direction == 1 ? currentLeft : currentRight,
                                  _node_type_is_operation_binary_or_assignment(node->type));
                printf("RHO ");
                _show_node_list(node->attribute);
                printf("\n");
                break;

            case UNION:
                //todo: nós não podem ter o mesmo nome, pensar em solução
                _add_node_in_json(rootJson, nodeJson, direction, direction == 1 ? currentLeft : currentRight,
                                  _node_type_is_operation_binary_or_assignment(node->type));
                printf("UNION ");
                printf("\n");
                break;

            case INTERSECTION:
                //todo: nós não podem ter o mesmo nome, pensar em solução
                _add_node_in_json(rootJson, nodeJson, direction, direction == 1 ? currentLeft : currentRight,
                                  _node_type_is_operation_binary_or_assignment(node->type));
                printf("INTERSECTION ");
                printf("\n");
                break;

            case SUBTRACTION:
                //todo: nós não podem ter o mesmo nome, pensar em solução
                _add_node_in_json(rootJson, nodeJson, direction, direction == 1 ? currentLeft : currentRight,
                                  _node_type_is_operation_binary_or_assignment(node->type));
                printf("SUBTRACTION ");
                printf("\n");
                break;

            case CARTESIAN_PRODUCT:
                //todo: nós não podem ter o mesmo nome, pensar em solução
                _add_node_in_json(rootJson, nodeJson, direction, direction == 1 ? currentLeft : currentRight,
                                  _node_type_is_operation_binary_or_assignment(node->type));
                printf("PRODUCT_CARTESIAN ");
                printf("\n");
                break;

            case NATURAL_JOIN:
                //todo: nós não podem ter o mesmo nome, pensar em solução
                _add_node_in_json(rootJson, nodeJson, direction, direction == 1 ? currentLeft : currentRight,
                                  _node_type_is_operation_binary_or_assignment(node->type));
                printf("NATURAL_JOIN ");
                printf("\n");
                break;

            case JOIN:
                predicateJson = cJSON_CreateArray();
                _add_items_array_json(node->predicate, predicateJson);
                cJSON_AddItemToObject(nodeJson, "predicate", predicateJson);
                _add_node_in_json(rootJson, nodeJson, direction, direction == 1 ? currentLeft : currentRight,
                                  _node_type_is_operation_binary_or_assignment(node->type));
                printf("JOIN ");
                _show_node_list(node->predicate);
                printf("\n");
                break;

            case DIVISION:
                //todo: nós não podem ter o mesmo nome, pensar em solução
                _add_node_in_json(rootJson, nodeJson, direction, direction == 1 ? currentLeft : currentRight,
                                  _node_type_is_operation_binary_or_assignment(node->type));
                printf("DIVISION ");
                printf("\n");
                break;

            case F_SCRIPT:
                attributeJson = cJSON_CreateArray();
                attribute2Json = cJSON_CreateArray();

                _add_items_array_json(node->attribute, attributeJson);
                _add_items_array_json(node->attribute2, attribute2Json);

                cJSON_AddItemToObject(nodeJson, "attribute", attributeJson);
                cJSON_AddItemToObject(nodeJson, "attribute2", attribute2Json);
                _add_node_in_json(rootJson, nodeJson, direction, direction == 1 ? currentLeft : currentRight,
                                  _node_type_is_operation_binary_or_assignment(node->type));
                _show_node_list(node->attribute);
                printf(" FSCRIPT ");
                _show_node_list(node->attribute2);
                printf("\n");
                break;

            case LEFT_OUTER_JOIN:
                predicateJson = cJSON_CreateArray();
                _add_items_array_json(node->predicate, predicateJson);
                cJSON_AddItemToObject(nodeJson, "predicate", predicateJson);
                _add_node_in_json(rootJson, nodeJson, direction, direction == 1 ? currentLeft : currentRight,
                                  _node_type_is_operation_binary_or_assignment(node->type));
                printf("LEFT_OUTER_JOIN ");
                _show_node_list(node->predicate);
                printf("\n");
                break;

            case RIGHT_OUTER_JOIN:
                predicateJson = cJSON_CreateArray();
                _add_items_array_json(node->predicate, predicateJson);
                cJSON_AddItemToObject(nodeJson, "predicate", predicateJson);
                _add_node_in_json(rootJson, nodeJson, direction, direction == 1 ? currentLeft : currentRight,
                                  _node_type_is_operation_binary_or_assignment(node->type));
                printf("RIGHT_OUTER_JOIN ");
                _show_node_list(node->predicate);
                printf("\n");
                break;

            case COMPLETE_OUTER_JOIN:
                predicateJson = cJSON_CreateArray();
                _add_items_array_json(node->predicate, predicateJson);
                cJSON_AddItemToObject(nodeJson, "predicate", predicateJson);
                _add_node_in_json(rootJson, nodeJson, direction, direction == 1 ? currentLeft : currentRight,
                                  _node_type_is_operation_binary_or_assignment(node->type));
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

int _node_type_is_operation_binary_or_assignment(NodeType type) {
    if (type == UNION || type == JOIN || type == CARTESIAN_PRODUCT ||
        type == SUBTRACTION || type == NATURAL_JOIN || type == DIVISION ||
        type == LEFT_OUTER_JOIN || type == RIGHT_OUTER_JOIN ||
        type == COMPLETE_OUTER_JOIN || type == INTERSECTION || type == ASSIGNMENT) {
        return 1;
    } else {
        return 0;
    }
}

void _add_sub_tree(Node *node) {
    if (headList == NULL) {
        headList = (SubTreeList *) malloc(sizeof(SubTreeList));
        headList->name = node->left->name;
        headList->node = node;
        headList->next = NULL;
    } else {
        if (_exists_sub_tree_same_name(node->left->name) == 0) {
            SubTreeList *new = (SubTreeList *) malloc(sizeof(SubTreeList));
            new->name = node->left->name;
            new->node = node;
            new->next = NULL;

            SubTreeList *aux = headList;

            while (aux->next != NULL) {
                aux = aux->next;
            }

            aux->next = new;
        }
    }
}

void _create_sub_tree_list() {
    headList = NULL;
}

Node *_get_sub_tree_or_node(Node *node) {
    SubTreeList *aux = headList;
    while (aux != NULL) {
        if (strcmp(aux->name, node->name) == 0) {
            return aux->node;
        }

        aux = aux->next;
    }

    return node;
}

int _exists_sub_tree_same_name(char *name) {
    SubTreeList *aux = headList;

    while (aux != NULL) {
        if (strcmp(aux->name, name) == 0) {
            return 1;
        }

        aux = aux->next;
    }

    return 0;
}
