#ifndef bst_h
#define bst_h

typedef struct data
{
	int value;
}Data;

typedef struct node
{
	Data data;
	struct node * left;
	struct node * right;
	struct node * parent;
	int flag;
}Node;

typedef struct tree
{
	Node * root;
}Tree;

Node * createNode(Data, Node *);

Tree * createTree();

Data * insert(Tree *, Data);

Data * insertNode(Node *, Data);

void sort(Tree *, Data *);

int sortAux(Node *, Data *, int );

Tree * traversen(Node *, Tree *);

Data * search(Tree *, Data);

Node * searchTree(Tree *, Data);

Node * searchNode(Node *, Data);

int compare(Tree *, Tree *);

int compared(Node *, Node *);

Tree * clone(Tree *);

Node * copy(Node *);

void deleteTree(Tree *);

void deleteData(Tree *, Node *);

void removeData(Tree *, Data);

void removeLeaf(Tree *, Node *);

void shortCircuit(Tree *, Node *);

void promotion(Tree *, Node *);

#endif
