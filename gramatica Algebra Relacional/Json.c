#include "Json.h"

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

cJSON *_get_node_json(cJSON *rootJson, int current, char *direction) {
    int aux = current;
    cJSON *temp = rootJson;

    while (aux > 1) {
        temp = cJSON_GetObjectItem(temp, direction);
        aux--;
    }

    return temp;
}

void _add_node_in_json(cJSON *rootJson, cJSON *nodeJson, int direction, int currentNumberDirection, int isBinary) {
    if (direction == 0) {
        cJSON_AddItemToObject(rootJson, _get_node_name_by_direction(direction), nodeJson);
    } else {
        cJSON *node = _get_node_json(rootJson, currentNumberDirection,
                                     _get_node_name_by_direction(direction));

        //todo: verificar nesse ponto o erro
        if (isBinary && !cJSON_IsNull(rootJson->next)) {
//            cJSON_AddItemToObject(nodeJson, _get_node_name_by_direction(rootJson->next->valueint), rootJson->next);
            printf("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
            char *out = cJSON_Print(rootJson->next);
            printf("%s\n", out);
            printf("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
            rootJson->next = NULL;
        }

        if (node == NULL) {
            cJSON_AddItemToObject(rootJson, _get_node_name_by_direction(direction), nodeJson);
        } else {
            cJSON_AddItemToObject(node, _get_node_name_by_direction(direction), nodeJson);
            cJSON_ReplaceItemViaPointer(rootJson, node, node);
        }
    }
}

void _add_items_array_json(NodeChar *items, cJSON *array) {
    NodeChar *aux = items;
    while (aux != NULL) {
        cJSON_AddItemToArray(array, cJSON_CreateString(aux->name));
        aux = aux->next;
    }
}

cJSON *_build_node_json(Node *node) {
    cJSON *nodeJson = cJSON_CreateObject(), *predicateJson, *attributeJson, *attribute2Json, *typeJson, *name;

    typeJson = cJSON_CreateString(_string_from_node_type(node->type));
    cJSON_AddItemToObject(nodeJson, "type", typeJson);

    switch (node->type) {
        case SELECTION:
            predicateJson = cJSON_CreateArray();
            _add_items_array_json(node->predicate, predicateJson);
            cJSON_AddItemToObject(nodeJson, "predicate", predicateJson);
            break;

        case RELATION:
            attributeJson = cJSON_CreateArray();
            _add_items_array_json(node->attribute, attributeJson);
            name = cJSON_CreateString(node->name);
            cJSON_AddItemToObject(nodeJson, "name", name);
            cJSON_AddItemToObject(nodeJson, "attribute", attributeJson);
            break;

        case PROJECTION:
            attributeJson = cJSON_CreateArray();
            _add_items_array_json(node->attribute, attributeJson);
            cJSON_AddItemToObject(nodeJson, "attribute", attributeJson);
            break;

        case ASSIGNMENT_RHO:
            attributeJson = cJSON_CreateArray();
            _add_items_array_json(node->attribute, attributeJson);
            cJSON_AddItemToObject(nodeJson, "attribute", attributeJson);
            break;

        case JOIN:
            predicateJson = cJSON_CreateArray();
            _add_items_array_json(node->predicate, predicateJson);
            cJSON_AddItemToObject(nodeJson, "predicate", predicateJson);
            break;

        case F_SCRIPT:
            attributeJson = cJSON_CreateArray();
            attribute2Json = cJSON_CreateArray();

            _add_items_array_json(node->attribute, attributeJson);
            _add_items_array_json(node->attribute2, attribute2Json);

            cJSON_AddItemToObject(nodeJson, "attribute", attributeJson);
            cJSON_AddItemToObject(nodeJson, "attribute2", attribute2Json);
            break;

        case LEFT_OUTER_JOIN:
            predicateJson = cJSON_CreateArray();
            _add_items_array_json(node->predicate, predicateJson);
            cJSON_AddItemToObject(nodeJson, "predicate", predicateJson);
            break;

        case RIGHT_OUTER_JOIN:
            predicateJson = cJSON_CreateArray();
            _add_items_array_json(node->predicate, predicateJson);
            cJSON_AddItemToObject(nodeJson, "predicate", predicateJson);
            break;

        case COMPLETE_OUTER_JOIN:
            predicateJson = cJSON_CreateArray();
            _add_items_array_json(node->predicate, predicateJson);
            cJSON_AddItemToObject(nodeJson, "predicate", predicateJson);
            break;

        default:
            return NULL;
    }

    return nodeJson;
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

//todo: Corrigir o segmentation fault na função
void _build_json(Node *node, Node *rootTree, cJSON *rootJson, int direction, int currentLeft, int currentRight) {
//    if (node == NULL) {
//        _show_node(node, b, rootJson->next, direction, currentLeft, currentRight);
//        return;
//    } else {
    if (_node_type_is_operation_binary_or_assignment(node->type) && (node != rootTree)) {
        rootJson->next = _build_node_json(node->left);
        cJSON_SetNumberValue(rootJson->next, 1);
    } else {
        _build_json(node->left, rootTree, rootJson, 1, currentLeft + 1, currentRight);
    }

    cJSON *nodeJson = _build_node_json(node);
    _add_node_in_json(rootJson, nodeJson, direction, direction == 1 ? currentLeft : currentRight,
                      _node_type_is_operation_binary_or_assignment(node->type));

    _build_json(node->right, rootTree, rootJson, 2, currentLeft, currentRight + 1);
//    }
}

void _show_json(cJSON *rootJson) {
    printf("\n****************************JSON********************************\n");
    char *out = cJSON_Print(rootJson);
    printf("%s", out);
    printf("\n***************************************************************\n");
}