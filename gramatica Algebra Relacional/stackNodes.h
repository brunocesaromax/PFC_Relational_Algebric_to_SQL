struct stack{
    NodeTree *nodeTree;
    struct stack *next;
};

struct stack *top;

/************FUNCTION SIGNATURES***************/

void create_stack();

void push(NodeTree *node);

NodeTree *pop();

void display_stack();

NodeTree *top_element();

void _show_node_stack(NodeTree *nodeTree, int b);
