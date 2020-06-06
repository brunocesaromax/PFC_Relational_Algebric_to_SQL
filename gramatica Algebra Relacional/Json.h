#include <stdio.h>
#include <stdlib.h>
#include <cjson/cJSON.h>

cJSON *rootJson;

/************FUNCTION SIGNATURES***************/
cJSON *_get_root_json(cJSON *nodeJson);

cJSON *_get_node_json(cJSON *rootJson, char *direction, int currentLeft, int currentRight);

void _add_node_in_json(cJSON *rootJson, cJSON *nodeJson, int direction, int currentLeft, int currentRight, int isBinary);

void _add_items_array_json(NodeChar *items, cJSON *array);

cJSON *_build_node_json(Node *node);

char *_get_node_name_by_direction(int direction);

void _build_json(Node *node, cJSON *rootJson, int direction, int currentLeft, int currentRight);

void _show_json(cJSON *rootJson);

void _copy_items(cJSON *target, cJSON *source);