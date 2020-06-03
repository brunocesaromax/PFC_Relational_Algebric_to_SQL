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

    while (auxRight > 0) {
        temp = cJSON_GetObjectItem(temp, "right");
        auxRight--;
    }

    while (auxLeft > 0) {
        temp = cJSON_GetObjectItem(temp, "left");
        auxLeft--;
    }

    return temp;
}

void
_add_node_in_json(cJSON *rootJson, cJSON *nodeJson, int direction, int currentLeft, int currentRight, int isBinary) {
    if (direction == 0) {
        _copy_items(rootJson, nodeJson);
    } else {
        cJSON *node = _get_node_json(rootJson, _get_node_name_by_direction(direction), currentLeft, currentRight);


//        printf("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");
//        printf("\nDirecao = %d\n", direction);
//        char *out = cJSON_Print(node);
//        printf("%s\n", out);
//        printf("\n&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&\n");

        _copy_items(node, nodeJson);
        cJSON_ReplaceItemViaPointer(rootJson, node, node);
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
    }

    //Refatorar a construção do json para trabalhar com os nos
    // esquerdo e direito já construídos
    cJSON_AddItemToObject(nodeJson, "left", cJSON_CreateObject());
    cJSON_AddItemToObject(nodeJson, "right", cJSON_CreateObject());

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
        return;
    } else {
        cJSON *nodeJson = _build_node_json(node);
        _add_node_in_json(rootJson, nodeJson, direction, currentLeft, currentRight,
                          _node_is_operation_binary_or_assignment(node));

//        if (_node_is_operation_binary_or_assignment(node) && (node != rootTree)) {
//            rootJson->next = _build_node_json(node->left);
//            cJSON_SetNumberValue(rootJson->next, 1);
//        } else {
//        printf("\n%d - %d\n", currentLeft + 1, currentRight);
        _build_json(node->left, rootJson, 1, currentLeft + 1, currentRight);

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
    char *nameName = "name";
    char *attributeName = "attribute";
    char *attribute2Name = "attribute2";
    char *predicateName = "predicate";
    char *leftName = "left";
    char *rightName = "right";

    cJSON *type = cJSON_DetachItemFromObject(source, typeName);
    cJSON *name = cJSON_DetachItemFromObject(source, nameName);
    cJSON *attribute = cJSON_DetachItemFromObject(source, attributeName);
    cJSON *attribute2 = cJSON_DetachItemFromObject(source, attribute2Name);
    cJSON *predicate = cJSON_DetachItemFromObject(source, predicateName);
    cJSON *left = cJSON_DetachItemFromObject(source, leftName);
    cJSON *right = cJSON_DetachItemFromObject(source, rightName);

    cJSON_AddItemToObject(target, typeName, type);
    cJSON_AddItemToObject(target, nameName, name);
    cJSON_AddItemToObject(target, attributeName, attribute);
    cJSON_AddItemToObject(target, attribute2Name, attribute2);
    cJSON_AddItemToObject(target, predicateName, predicate);
    cJSON_AddItemToObject(target, leftName, left);
    cJSON_AddItemToObject(target, rightName, right);
}