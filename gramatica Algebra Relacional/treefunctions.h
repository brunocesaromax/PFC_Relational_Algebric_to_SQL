#ifndef  FUNCTIONS_H_INCLUDED
#define  FUNCTIONS_H_INCLUDED

typedef enum nodeTreeType NodeTreeType;
typedef enum boolean Boolean;
typedef struct nodeList NodeList;
typedef struct nodeTree NodeTree;

enum nodeTreeType {
    RELATION,  SELECTION, PROJECTION, ASSIGNMENT, ASSIGNMENT2,
     JOIN, NATURAL_JOIN, UNION, INTERSECTION, SUBTRACTION,
    CARTESIAN_PRODUCT, DIVISION, F_SCRIPT, LEFT_OUTER_JOIN,
     RIGHT_OUTER_JOIN ,COMPLETE_OUTER_JOIN, OP_P, CL_P
};

enum boolean {
    TRUE = 1, FALSE = 0
};

struct nodeList {
    char *name;
    NodeList *nodeNext;
};

struct nodeTree {
    NodeTreeType type;
    char *name;
    NodeList *attribute;
    NodeList *attribute2;
    NodeList *predicate;
    NodeTree *nodeLeft;
    NodeTree *nodeRight;
};

/*Raíz da árvore*/
NodeTree *root;

/************FUNCTION SIGNATURES***************/

void _tool_initialize();

void create_tree();

NodeTree *allocate_node();

void _add_symbols_predicate(char *symbol);

void _add_symbols_attribute(char *symbol, int option);

//void _add_node_stack(NodeTreeType type, char *s, char *attribute,char *attribute2, char *predicate);

void _add_node_stack(char *s);

void _build_tree();

void _show_node_list(NodeList *nodeList);

void _show_tree(NodeTree *root, int b);

void _show_node(NodeTree *nodeTree, int b);

#endif
