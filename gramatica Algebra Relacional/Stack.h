typedef struct stack Stack;

struct stack {
    Node *node;
    Stack *next;
};

Stack *top;

/************FUNCTION SIGNATURES***************/

void _create_stack();

void _push(Node *node);

Node *_pop();

Node *_top_element();

int _stack_is_empty();

void _add_node_stack(char *s);

Node *_get_first_rho_node_in_stack();

void _display_stack();

void _show_node_stack(Node *node, int b);
