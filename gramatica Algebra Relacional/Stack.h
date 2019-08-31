struct stack{
    Node *node;
    struct stack *next;
};

struct stack *top;

/************FUNCTION SIGNATURES***************/

void _create_stack();

void _push(Node *node);

Node* _pop();

void _display_stack();

Node* _top_element();

void _show_node_stack(Node *node, int b);