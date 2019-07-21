struct stack{
    Node *node;
    struct stack *next;
};

struct stack *top;

/************FUNCTION SIGNATURES***************/
/*stack no inicio das operações*/

void create_stack();

void push(Node *node);

Node *pop();

void display_stack();

Node *top_element();

void _show_node_stack(Node *node, int b);