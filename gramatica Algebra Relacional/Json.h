#include <cjson/cJSON.h>

cJSON *rootJson;

/************FUNCTION SIGNATURES***************/
cJSON *_get_root_json(cJSON *nodeJson);

cJSON *_get_node_json(cJSON *rootJson, int current, char *direction);

void _add_node_in_json(cJSON *rootJson, cJSON *nodeJson, int direction, int currentNumberDirection, int isBinary);

void _add_items_array_json(NodeChar *items, cJSON *array);

cJSON *_build_node_json(Node *node);

char *_get_node_name_by_direction(int direction);