#ifndef  FUNCTIONS_H_INCLUDED
#define  FUNCTIONS_H_INCLUDED

typedef enum nodeType NodeType;
typedef struct nodeChar NodeChar;
typedef struct node Node;

enum nodeType {
    RELATION, SELECTION, PROJECTION, ASSIGNMENT, ASSIGNMENT_RHO,
    JOIN, NATURAL_JOIN, UNION, INTERSECTION, SUBTRACTION,
    CARTESIAN_PRODUCT, DIVISION, F_SCRIPT, LEFT_OUTER_JOIN,
    RIGHT_OUTER_JOIN, COMPLETE_OUTER_JOIN, OPEN_PARENTHESES, CLOSE_PARENTHESES
};

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

/************FUNCTION SIGNATURES***************/

Node *allocate_node();

void _add_symbols_predicate(char *symbol);

void _add_symbols_attribute(char *symbol, int option);

void _add_node_stack(char *s);

void _show_node_list(NodeChar *nodeChar);

void _show_node(Node *node, int b);

void _get_node_type(Node *node, char *s);

void _build_node(Node *node);

Node* _allocate_node();

#endif
