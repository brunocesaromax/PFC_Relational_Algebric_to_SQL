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

cJSON *_get_node_json(cJSON *rootJson, char *direction, int currentLeft, int currentRight) {
    //left = 1, right = 0

    int auxRight = currentRight;
    int auxLeft = currentLeft;
    cJSON *temp = rootJson;

    do{
        temp = cJSON_GetObjectItem(temp, "right");
        auxRight--;
    }while(auxRight > 1);

    while (auxLeft > 1) {
        temp = cJSON_GetObjectItem(temp, direction);
        auxLeft--;
    }

    return temp;
}

void _add_node_in_json(cJSON *rootJson, cJSON *nodeJson, int direction, int currentLeft, int currentRight, int isBinary) {
    if (direction == 0) {
        _copy_items(rootJson, nodeJson);
    } else {
        cJSON *node = _get_node_json(rootJson, _get_node_name_by_direction(direction), currentLeft, currentRight);

        //todo: verificar nesse ponto o erro
//        if (isBinary && !cJSON_IsNull(rootJson->next)) {
////            cJSON_AddItemToObject(nodeJson, _get_node_name_by_direction(rootJson->next->valueint), rootJson->next);
//            printf("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
//            char *out = cJSON_Print(rootJson->next);
//            printf("%s\n", out);
//            printf("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
//            rootJson->next = NULL;
//        }

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
    cJSON *nodeJson = cJSON_CreateObject();

    if (node) {
        cJSON *predicateJson, *attributeJson, *attribute2Json, *typeJson, *name;

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

        //Refatorar a construção do json para trabalhar com os nos
        // esquerdo e direito já construídos
        cJSON_AddItemToObject(nodeJson, "left", cJSON_CreateObject());
        cJSON_AddItemToObject(nodeJson, "right", cJSON_CreateObject());
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

void _build_json(Node *node, cJSON *rootJson, int direction, int currentLeft, int currentRight) {
    if (node == NULL) {
        cJSON *nodeJson = _build_node_json(node);
//        printf("\nleft = %d, right = %d\n", currentLeft, currentRight);

        _add_node_in_json(rootJson, nodeJson, direction, currentLeft, currentRight,
                          _node_is_operation_binary_or_assignment(node));
        return;
    } else {
        cJSON *nodeJson = _build_node_json(node);
        _add_node_in_json(rootJson, nodeJson, direction, currentLeft, currentRight,
                          _node_is_operation_binary_or_assignment(node));

        if (_node_is_operation_binary_or_assignment(node) && (node != rootTree)) {
            rootJson->next = _build_node_json(node->left);
            cJSON_SetNumberValue(rootJson->next, 1);
        } else {
            _build_json(node->left, rootJson, 1, currentLeft + 1, currentRight);
        }

//        printf("\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
//        printf("\nleft = %d, right = %d\n", currentLeft, currentRight);
//        printf("\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n");
        _build_json(node->right, rootJson, 2, currentLeft, currentRight + 1);
    }
}

void _show_json(cJSON *rootJson) {
    printf("\n****************************JSON********************************\n");
    char *out = cJSON_Print(rootJson);
    printf("%s", out);
    printf("\n***************************************************************\n");
}

void _copy_items(cJSON *target, cJSON *source) {
    char *typeName = "type";
    char *attributeName = "attribute";
    char *attribute2Name = "attribute2";
    char *predicateName = "predicate";

    cJSON *type = cJSON_DetachItemFromObject(source, typeName);
    cJSON *attribute = cJSON_DetachItemFromObject(source, attributeName);
    cJSON *attribute2 = cJSON_DetachItemFromObject(source, attribute2Name);
    cJSON *predicate = cJSON_DetachItemFromObject(source, predicateName);

    cJSON_AddItemToObject(target, typeName, type);
    cJSON_AddItemToObject(target, attributeName, attribute);
    cJSON_AddItemToObject(target, attribute2Name, attribute2);
    cJSON_AddItemToObject(target, predicateName, predicate);
}