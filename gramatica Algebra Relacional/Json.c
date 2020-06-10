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
    NodeChar *aux = items, *lastInserted;
    int totalElements = 0;

    while (aux != NULL) {
        if (strcmp(aux->name, ",")) {

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

cJSON *_build_node_json(Node *node) {
    cJSON *nodeJson = cJSON_CreateObject();
    cJSON *predJson, *attrJson, *compJson, *typeJson, *name;

    typeJson = cJSON_CreateString(_string_from_node_type(node->type));
    cJSON_AddItemToObject(nodeJson, "type", typeJson);

    switch (node->type) {
        case SELECTION:
            predJson = cJSON_CreateArray();

            if (ELEM_NIL) {
                cJSON_AddItemToObject(nodeJson, "name", cJSON_CreateString("nil"));
                cJSON_AddItemToObject(nodeJson, "attr", cJSON_CreateString("nil"));
                cJSON_AddItemToObject(nodeJson, "comp", cJSON_CreateString("nil"));
                _add_items_array_json(node->pred, predJson);
                cJSON_AddItemToObject(nodeJson, "pred", predJson);

                if (!node->left) {
                    cJSON_AddItemToObject(nodeJson, "left", cJSON_CreateString("nil"));
                }

                if (!node->right) {
                    cJSON_AddItemToObject(nodeJson, "right", cJSON_CreateString("nil"));
                }

            } else {
                _add_items_array_json(node->pred, predJson);
                cJSON_AddItemToObject(nodeJson, "pred", predJson);
            }

            break;

        case RELATION:
            attrJson = cJSON_CreateArray();

            if (ELEM_NIL) {
                cJSON_AddItemToObject(nodeJson, "name", cJSON_CreateString(node->name));

                if (node->attr) {
                    _add_items_array_json(node->attr, attrJson);
                    cJSON_AddItemToObject(nodeJson, "attr", attrJson);
                } else {
                    cJSON_AddItemToObject(nodeJson, "attr", cJSON_CreateString("nil"));
                }

                cJSON_AddItemToObject(nodeJson, "comp", cJSON_CreateString("nil"));
                cJSON_AddItemToObject(nodeJson, "pred", cJSON_CreateString("nil"));

                if (!node->left) {
                    cJSON_AddItemToObject(nodeJson, "left", cJSON_CreateString("nil"));
                }

                if (!node->right) {
                    cJSON_AddItemToObject(nodeJson, "right", cJSON_CreateString("nil"));
                }

            } else {
                attrJson = cJSON_CreateArray();
                _add_items_array_json(node->attr, attrJson);
                cJSON_AddItemToObject(nodeJson, "name", cJSON_CreateString(node->name));
                cJSON_AddItemToObject(nodeJson, "attr", attrJson);
            }

            break;

        case PROJECTION:
            attrJson = cJSON_CreateArray();

            if (ELEM_NIL) {
                cJSON_AddItemToObject(nodeJson, "name", cJSON_CreateString("nil"));

                if (node->attr) {
                    _add_items_array_json(node->attr, attrJson);
                    cJSON_AddItemToObject(nodeJson, "attr", attrJson);
                } else {
                    cJSON_AddItemToObject(nodeJson, "attr", cJSON_CreateString("nil"));
                }

                cJSON_AddItemToObject(nodeJson, "comp", cJSON_CreateString("nil"));
                cJSON_AddItemToObject(nodeJson, "pred", cJSON_CreateString("nil"));

                if (!node->left) {
                    cJSON_AddItemToObject(nodeJson, "left", cJSON_CreateString("nil"));
                }

                if (!node->right) {
                    cJSON_AddItemToObject(nodeJson, "right", cJSON_CreateString("nil"));
                }

            } else {
                _add_items_array_json(node->attr, attrJson);
                cJSON_AddItemToObject(nodeJson, "attr", attrJson);
            }

            break;

        case ASSIGNMENT_RHO:
            attrJson = cJSON_CreateArray();

            if (ELEM_NIL) {
                cJSON_AddItemToObject(nodeJson, "name", cJSON_CreateString("nil"));

                if (node->attr) {
                    _add_items_array_json(node->attr, attrJson);
                    cJSON_AddItemToObject(nodeJson, "attr", attrJson);
                } else {
                    cJSON_AddItemToObject(nodeJson, "attr", cJSON_CreateString("nil"));
                }

                cJSON_AddItemToObject(nodeJson, "comp", cJSON_CreateString("nil"));
                cJSON_AddItemToObject(nodeJson, "pred", cJSON_CreateString("nil"));

                if (!node->left) {
                    cJSON_AddItemToObject(nodeJson, "left", cJSON_CreateString("nil"));
                }

                if (!node->right) {
                    cJSON_AddItemToObject(nodeJson, "right", cJSON_CreateString("nil"));
                }

            } else {
                _add_items_array_json(node->attr, attrJson);
                cJSON_AddItemToObject(nodeJson, "attr", attrJson);
            }

            break;

        case JOIN:
            predJson = cJSON_CreateArray();

            if (ELEM_NIL) {
                cJSON_AddItemToObject(nodeJson, "name", cJSON_CreateString("nil"));
                cJSON_AddItemToObject(nodeJson, "attr", cJSON_CreateString("nil"));
                cJSON_AddItemToObject(nodeJson, "comp", cJSON_CreateString("nil"));

                if (node->pred) {
                    _add_items_array_json(node->pred, predJson);
                    cJSON_AddItemToObject(nodeJson, "pred", predJson);
                } else {
                    cJSON_AddItemToObject(nodeJson, "pred", cJSON_CreateString("nil"));
                }

                if (!node->left) {
                    cJSON_AddItemToObject(nodeJson, "left", cJSON_CreateString("nil"));
                }

                if (!node->right) {
                    cJSON_AddItemToObject(nodeJson, "right", cJSON_CreateString("nil"));
                }

            } else {
                _add_items_array_json(node->pred, predJson);
                cJSON_AddItemToObject(nodeJson, "pred", predJson);
            }

            break;

        case F_SCRIPT:
            attrJson = cJSON_CreateArray();
            compJson = cJSON_CreateArray();

            if (ELEM_NIL) {
                cJSON_AddItemToObject(nodeJson, "name", cJSON_CreateString("nil"));

                if (node->attr) {
                    _add_items_array_json(node->attr, attrJson);
                    cJSON_AddItemToObject(nodeJson, "attr", attrJson);
                } else {
                    cJSON_AddItemToObject(nodeJson, "attr", cJSON_CreateString("nil"));
                }

                if (node->comp) {
                    _add_items_array_json(node->comp, compJson);
                    cJSON_AddItemToObject(nodeJson, "comp", compJson);
                } else {
                    cJSON_AddItemToObject(nodeJson, "comp", cJSON_CreateString("nil"));
                }

                cJSON_AddItemToObject(nodeJson, "pred", cJSON_CreateString("nil"));

                if (!node->left) {
                    cJSON_AddItemToObject(nodeJson, "left", cJSON_CreateString("nil"));
                }

                if (!node->right) {
                    cJSON_AddItemToObject(nodeJson, "right", cJSON_CreateString("nil"));
                }

            } else {
                _add_items_array_json(node->attr, attrJson);
                _add_items_array_json(node->comp, compJson);

                cJSON_AddItemToObject(nodeJson, "attr", attrJson);
                cJSON_AddItemToObject(nodeJson, "comp", compJson);
            }

            break;

        case LEFT_OUTER_JOIN:
            predJson = cJSON_CreateArray();
            _add_items_array_json(node->pred, predJson);
            cJSON_AddItemToObject(nodeJson, "pred", predJson);
            break;

        case RIGHT_OUTER_JOIN:
            predJson = cJSON_CreateArray();
            _add_items_array_json(node->pred, predJson);
            cJSON_AddItemToObject(nodeJson, "pred", predJson);
            break;

        case COMPLETE_OUTER_JOIN:
            predJson = cJSON_CreateArray();
            _add_items_array_json(node->pred, predJson);
            cJSON_AddItemToObject(nodeJson, "pred", predJson);
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

    if (out) {
//        FILE *fptr;
//        fptr = fopen("json.txt", "w");
//
//        if (fptr == NULL) {
//            printf("\nError opening file!\n");
//            exit(1);
//        }
//
//        fprintf(fptr, "%s", out);
//        fclose(fptr);

        printf("%s", out);
        cJSON_free(out);
    }

    printf("\n***************************************************************\n");
}

void _copy_items(cJSON *target, cJSON *source) {
    char *typeName = "type";
    char *nameName = "name";
    char *attrName = "attr";
    char *compName = "comp";
    char *predName = "pred";
    char *leftName = "left";
    char *rightName = "right";

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