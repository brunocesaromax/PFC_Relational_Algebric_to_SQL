#include <cjson/cJSON.h>

typedef struct tree Tree;

struct tree{
    Node *node;
};

Tree *root;
cJSON *rootJson;

/************FUNCTION SIGNATURES***************/

void _tool_initialize();

void _create_tree();

void _build_tree();

void _show_tree(Node *root, int b, cJSON *rootJson, int direction, int currentLeft, int currentRight);

void _start_data_structures();