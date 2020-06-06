#include <cjson/cJSON.h>

typedef enum nodeType NodeType;
typedef struct nodeChar NodeChar;
typedef struct node Node;
typedef struct subTreeList SubTreeList;

enum nodeType {
    RELATION, SELECTION, PROJECTION, ASSIGNMENT, ASSIGNMENT_RHO,
    JOIN, NATURAL_JOIN, UNION, INTERSECTION, SUBTRACTION,
    CARTESIAN_PRODUCT, DIVISION, F_SCRIPT, LEFT_OUTER_JOIN,
    RIGHT_OUTER_JOIN, COMPLETE_OUTER_JOIN, OPEN_PARENTHESES, CLOSE_PARENTHESES
};

static inline char *_string_from_node_type(enum nodeType type) {
    static const char *strings[] = {"RELATION", "SELECTION", "PROJECTION", "ASSIGNMENT", "ASSIGNMENT_RHO",
                                    "JOIN", "NATURAL_JOIN", "UNION", "INTERSECTION", "SUBTRACTION",
                                    "CARTESIAN_PRODUCT", "DIVISION", "F_SCRIPT", "LEFT_OUTER_JOIN",
                                    "RIGHT_OUTER_JOIN", "COMPLETE_OUTER_JOIN", "OPEN_PARENTHESES", "CLOSE_PARENTHESES"};
    return strings[type];
}

struct nodeChar {
    char *name;
    NodeChar *next;
};

struct node {
    NodeType type;
    char *name;
    NodeChar *attr;
    NodeChar *comp;
    NodeChar *pred;
    Node *left;
    Node *right;
};

struct subTreeList {
    char *name;
    Node *node;
    SubTreeList *next;
};

///*GLOBAL VARIABLES *//
Node *rootTree;
NodeChar *attr;
NodeChar *comp;
NodeChar *pred;
SubTreeList *headList;

/************FUNCTION SIGNATURES***************/
void _tool_initialize();

void _create_tree();

void _build_tree();

void _show_tree(Node *root, int b);

void _start_data_structures();

Node *_allocate_node();

void _add_symbols_predicate(char *symbol);

void _add_symbols_attribute(char *symbol, int option);

void _show_node_list(NodeChar *nodeChar);

void _show_node(Node *node, int b);

void _get_node_type(Node *node, char *s);

void _build_node(Node *node);

int _node_type_is_operation_binary(NodeType type);

int _node_is_operation_binary_or_assignment(Node *node);

void _add_sub_tree(Node *node);

void _create_sub_tree_list();

Node *_get_sub_tree_or_node(Node *node);

int _exists_sub_tree_same_name(char *name);