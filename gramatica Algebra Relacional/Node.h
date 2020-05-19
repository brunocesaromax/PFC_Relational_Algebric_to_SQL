#include <cjson/cJSON.h>

typedef enum nodeType NodeType;
typedef struct nodeChar NodeChar;
typedef struct node Node;
typedef struct subTreesList SubTreeList;

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
    NodeChar *attribute;
    NodeChar *attribute2;
    NodeChar *predicate;
    Node *left;
    Node *right;
};

struct subTreesList {
    char *name;
    Node *node;
    SubTreeList *next;
};

SubTreeList *subTreeList;

/************FUNCTION SIGNATURES***************/

Node *allocate_node();

void _add_symbols_predicate(char *symbol);

void _add_symbols_attribute(char *symbol, int option);

void _add_node_stack(char *s);

void _show_node_list(NodeChar *nodeChar);

void _show_node(Node *node, int b, cJSON *rootJson, int direction, int currentLeft, int currentRight);

void _get_node_type(Node *node, char *s);

void _build_node(Node *node);

Node *_allocate_node();

const char *get_node_type_name(NodeType type);

void _create_sub_tree_list();

void _add_sub_tree(Node *node);

Node *_get_sub_tree_or_node(Node *node);
