typedef struct tree Tree;

struct tree{
    Node *node;
};

Tree *root;

/************FUNCTION SIGNATURES***************/

void _tool_initialize();

void _create_tree();

void _build_tree();

void _show_tree(Node *root, int b);

void _start_data_structures();