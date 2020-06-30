#include "Json.h"

void _create_json() {
    jsonResultFile = jsonResult;
    jsonResult = NULL;

    jsonResult = cJSON_CreateObject();
    cJSON *rootJson = cJSON_CreateObject();
    cJSON_AddItemToObject(jsonResult, ROOT, rootJson);
}

void _add_items_array_json(NodeChar *items, cJSON *array) {
    NodeChar *aux = items, *lastInserted;
    int totalElements = 0;

    while (aux != NULL) {
        if (strcmp(aux->name, ",") && strcmp(aux->name, "(") && strcmp(aux->name, ")")) {

            if (totalElements > 0 && _is_arithmetic_operator(lastInserted->name)) {
                cJSON *arithmeticOperator = cJSON_DetachItemFromArray(array, --totalElements);
                cJSON *beforeArithmeticOperator = cJSON_DetachItemFromArray(array, --totalElements);

                char newElement[100];
                strcpy(newElement, beforeArithmeticOperator->valuestring);
                strcat(newElement, arithmeticOperator->valuestring);
                strcat(newElement, aux->name);

                cJSON_AddItemToArray(array, cJSON_CreateString(newElement));

                cJSON_Delete(arithmeticOperator);
                cJSON_Delete(beforeArithmeticOperator);

            } else if (totalElements > 0 && _is_aggregated_function(lastInserted->name)) {
                cJSON *aggregatedFunction = cJSON_DetachItemFromArray(array, --totalElements);
                char newElement[100];

                strcpy(newElement, aggregatedFunction->valuestring);
                strcat(newElement, aux->name);

                cJSON_AddItemToArray(array, cJSON_CreateString(newElement));

                cJSON_Delete(aggregatedFunction);

            } else {
                cJSON_AddItemToArray(array, cJSON_CreateString(aux->name));
            }

            lastInserted = aux;
            totalElements++;
        }

        aux = aux->next;
    }
}

cJSON *_get_node_json(Node *node) {
    cJSON *nodeJson = cJSON_CreateObject();
    cJSON *predJson, *attrJson, *compJson, *typeJson, *name;

    typeJson = cJSON_CreateString(_string_from_node_type(node->type));
    cJSON_AddItemToObject(nodeJson, TYPE, typeJson);

    if (ELEM_NIL) {
        if (node->name) {
            cJSON_AddItemToObject(nodeJson, NAME, cJSON_CreateString(node->name));
        } else {
            cJSON_AddItemToObject(nodeJson, NAME, cJSON_CreateString(NIL));
        }

        if (node->attr) {
            attrJson = cJSON_CreateArray();
            _add_items_array_json(node->attr, attrJson);
            cJSON_AddItemToObject(nodeJson, ATTR, attrJson);
        } else {
            cJSON_AddItemToObject(nodeJson, ATTR, cJSON_CreateString(NIL));
        }

        if (node->comp) {
            compJson = cJSON_CreateArray();
            _add_items_array_json(node->comp, compJson);
            cJSON_AddItemToObject(nodeJson, COMP, compJson);
        } else {
            cJSON_AddItemToObject(nodeJson, COMP, cJSON_CreateString(NIL));
        }

        if (node->pred) {
            predJson = cJSON_CreateArray();
            _add_items_array_json(node->pred, predJson);
            cJSON_AddItemToObject(nodeJson, PRED, predJson);
        } else {
            cJSON_AddItemToObject(nodeJson, PRED, cJSON_CreateString(NIL));
        }

        if (node->left) {
            cJSON_AddItemToObject(nodeJson, LEFT, cJSON_CreateObject());
        } else {
            cJSON_AddItemToObject(nodeJson, LEFT, cJSON_CreateString(NIL));
        }

        if (node->right) {
            cJSON_AddItemToObject(nodeJson, RIGHT, cJSON_CreateObject());
        } else {
            cJSON_AddItemToObject(nodeJson, RIGHT, cJSON_CreateString(NIL));
        }

    } else {
        if (node->name) {
            cJSON_AddItemToObject(nodeJson, NAME, cJSON_CreateString(node->name));
        }

        if (node->attr) {
            attrJson = cJSON_CreateArray();
            _add_items_array_json(node->attr, attrJson);
            cJSON_AddItemToObject(nodeJson, ATTR, attrJson);
        }

        if (node->comp) {
            compJson = cJSON_CreateArray();
            _add_items_array_json(node->comp, compJson);
            cJSON_AddItemToObject(nodeJson, COMP, compJson);
        }

        if (node->pred) {
            predJson = cJSON_CreateArray();
            _add_items_array_json(node->pred, predJson);
            cJSON_AddItemToObject(nodeJson, PRED, predJson);
        }

        if (node->left) {
            cJSON_AddItemToObject(nodeJson, LEFT, cJSON_CreateObject());
        }

        if (node->right) {
            cJSON_AddItemToObject(nodeJson, RIGHT, cJSON_CreateObject());
        }
    }

    return nodeJson;
}

void _build_json(Node *node, cJSON *nodeJson) {
    if (node == NULL) {
        return;
    } else {
        cJSON *new = _get_node_json(node);
        _copy_items(nodeJson, new);
        _build_json(node->left, cJSON_GetObjectItem(nodeJson, LEFT));
        _build_json(node->right, cJSON_GetObjectItem(nodeJson, RIGHT));
    }
}

void _show_json(cJSON *rootJson) {
    printf("\n****************************JSON********************************\n");
    char *out = cJSON_Print(rootJson);

    if (out) {
        printf("%s", out);
        cJSON_free(out);
    }

    printf("\n***************************************************************\n");
}

void _copy_items(cJSON *target, cJSON *source) {
    char *typeName = TYPE;
    char *nameName = NAME;
    char *attrName = ATTR;
    char *compName = COMP;
    char *predName = PRED;
    char *leftName = LEFT;
    char *rightName = RIGHT;

    cJSON *type = cJSON_DetachItemFromObject(source, typeName);
    cJSON *name = cJSON_DetachItemFromObject(source, nameName);
    cJSON *attr = cJSON_DetachItemFromObject(source, attrName);
    cJSON *comp = cJSON_DetachItemFromObject(source, compName);
    cJSON *pred = cJSON_DetachItemFromObject(source, predName);
    cJSON *left = cJSON_DetachItemFromObject(source, leftName);
    cJSON *right = cJSON_DetachItemFromObject(source, rightName);

    cJSON_AddItemToObject(target, typeName, type);
    cJSON_AddItemToObject(target, nameName, name);
    cJSON_AddItemToObject(target, attrName, attr);
    cJSON_AddItemToObject(target, compName, comp);
    cJSON_AddItemToObject(target, predName, pred);
    cJSON_AddItemToObject(target, leftName, left);
    cJSON_AddItemToObject(target, rightName, right);
}

void _generate_file_json() {
    char *out = cJSON_Print(jsonResultFile);

    if (out) {
        FILE *fptr;
        fptr = fopen("json.txt", "w");

        if (fptr == NULL) {
            printf("\nError opening file!\n");
            exit(1);
        }

        fprintf(fptr, "%s", out);
        fclose(fptr);
    }
}