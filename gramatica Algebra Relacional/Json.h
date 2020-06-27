#include <stdio.h>
#include <stdlib.h>
#include <cjson/cJSON.h>

/********FLAG TO SHOW EMPTY NODES**********/
#define ELEM_NIL 1

/********STATIC STRINGS TO JSON**********/
#define ROOT "root"
#define TYPE "type"
#define NAME "name"
#define ATTR "attr"
#define COMP "comp"
#define PRED "pred"
#define LEFT "left"
#define RIGHT "right"
#define NIL "nil"

cJSON *jsonResult;
cJSON *jsonResultFile;

/************FUNCTION SIGNATURES***************/
void _create_json();

void _add_items_array_json(NodeChar *items, cJSON *array);

cJSON *_build_node_json(Node *node);

void _build_json(Node *node, cJSON *rootJson);

void _show_json(cJSON *rootJson);

void _copy_items(cJSON *target, cJSON *source);

void _build_node_with_only_pred(cJSON *nodeJson, cJSON *predJson, Node *node);

void _build_node_with_only_attr(cJSON *nodeJson, cJSON *attrJson, Node *node);

void _generate_file_json();