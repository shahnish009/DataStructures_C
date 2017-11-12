#include<stdio.h>
#include<stdlib.h>
#include"bst.h"

Node * createNode(Data d, Node * parent)
{
	Node * node = malloc(sizeof(Node));
	node->data = d;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	node->flag = 0;

	return node;
}

Tree * createTree()
{
	Tree * tree = malloc(sizeof(Tree));
	tree->root = NULL;

	return tree;
}

Data * insert(Tree * bst, Data value)
{
	        if(bst->root == NULL)
	        {
	                bst->root = createNode(value,NULL);
        	        bst->root->parent = NULL;

			return &(bst->root->data);
        	}

	        else
        	{
			Node * node = searchNode(bst->root, value);

			if(node != NULL)
			{
				return NULL;
			}

			else
			{
				Data * data = insertNode(bst->root, value);
				return &(bst->root->data);
			}
	        }
}

Data * insertNode(Node * node, Data value)
{
	if(value.value < node->data.value)
	{
		if(node->left == NULL)
		{
			node->left = createNode(value, NULL);
			node->left->parent = node;
		}

		else
		{
			insertNode(node->left, value);
		}
	}

	else if(value.value > node->data.value)
	{
		if(node->right == NULL)
		{
			node->right = createNode(value, NULL);
			node->right->parent = node;
		}

		else
		{
			insertNode(node->right, value);
		}
	}

	return &(node->data);
}

void sort(Tree * bst, Data * data)
{
	int i = 0;
	int sortRes = InOrderSort(bst->root, data, i);
}

int InOrderSort(Node * current, Data * data, int i)
{
	if(current == NULL)
	{
		return i;
	}

	else
	{
		if(current->left != NULL)
		{
			i = InOrderSort(current->left, data, i);
		}

		data[i].value = current->data.value;
		i++;

		if(current->right != NULL)
		{
			i = InOrderSort(current->right, data, i);
		}
	}

	return i;
}

Data * search(Tree * bst, Data value)
{
	if(bst->root == NULL)
	{
		return NULL;
	}

	else if(bst->root->data.value == value.value)
	{
		return &(bst->root->data);
	}

	else
	{
		Node * current = searchNode(bst->root, value);

		return &(current->data);
	}
}

Node * searchTree(Tree * bst, Data value)
{
	if(bst->root == NULL)
	{
		return NULL;
	}

	else if(bst->root->data.value == value.value)
	{
		return bst->root;
	}

	else
	{
		Node * current = searchNode(bst->root, value);

		return current;
	}
}

Node * searchNode(Node * node, Data value)
{
	if(node->data.value == value.value)
	{
		return node;
	}

	else if(node->data.value > value.value)
	{
		if(node->left == NULL)
		{
			return NULL;
		}

		else
		{
			searchNode(node->left, value);
		}
	}

	else
	{
		if(node->right == NULL)
		{
			return NULL;
		}

		else
		{
			searchNode(node->right, value);
		}
	}
}

void removeData(Tree * bst, Data value)
{
	if(bst->root == NULL)
	{
		return;
	}
	else
	{
		Node * current = searchTree(bst, value);

		if(current == NULL)
		{
			return;
		}
		else
		{
			if(current->left == NULL && current->right == NULL)
			{
				removeLeaf(bst, current);
			}

			else if(current->left == NULL || current->right == NULL)
			{
				shortCircuit(bst, current);
			}

			else
			{
				promotion(bst, current);
			}
		}
	}
}

void removeLeaf(Tree * bst, Node * d_node)
{
	if(d_node->parent == NULL)
	{
		bst->root = NULL;

	}
	else if(d_node == d_node->parent->left)
	{
		d_node->parent->left = NULL;
	}
	else
	{
		d_node->parent->right = NULL;
	}

	free(d_node);
	d_node = NULL;
}

void shortCircuit(Tree * bst, Node * d_node)
{
	if(d_node->parent == NULL)
	{
		if(d_node->left != NULL)
		{
			bst->root = d_node->left;
			d_node->left->parent = NULL;
		}
		else
		{
			bst->root = d_node->right;
			d_node->right->parent = NULL;
		}
	}
	else if(d_node == d_node->parent->left)
	{
		if(d_node->left != NULL)
		{
			d_node->parent->left = d_node->left;
			d_node->left->parent = d_node->parent;
		}
		else
		{
			d_node->parent->left = d_node->right;
			d_node->right->parent = d_node->parent;
		}
	}
	else
	{
		if(d_node->left != NULL)
		{
			d_node->parent->right = d_node->left;
			d_node->left->parent = d_node->parent;
		}
		else
		{
			d_node->parent->right = d_node->right;
			d_node->right->parent = d_node->parent;
		}
	}

	free(d_node);
	d_node = NULL;
}

void promotion(Tree * bst, Node * d_node)
{
	if(d_node->parent == NULL)
	{
		if(d_node->right->left == NULL && d_node->right->right == NULL)
		{
			d_node->data.value = d_node->right->data.value;
			removeLeaf(bst, d_node->right);
		}
		else if(d_node->right->left == NULL)
		{
				d_node->data.value = d_node->right->data.value;
				shortCircuit(bst, d_node->right);
		}
		else
		{
			Node * current = d_node->right;
			while(current->left != NULL)
			{
				current = current->left;
			}

			d_node->data.value = current->data.value;
			removeLeaf(bst, current);
		}
	}
	else if(d_node == d_node->parent->right)
	{
		Node * current = d_node->right;

		if(d_node->right->left == NULL && d_node->right->right == NULL)
		{
			d_node->data.value = d_node->right->data.value;
			removeLeaf(bst, d_node->right);
		}

		else if(d_node->right->left == NULL)
		{
			d_node->data.value = d_node->right->data.value;
			shortCircuit(bst, d_node->right);
		}

		else
		{
			while(current->left != NULL)
			{
				current = current->left;
			}
			d_node->data.value = current->data.value;
			removeLeaf(bst, current);
		}
	}

	else
	{
		Node * current = d_node->right;
		if(d_node->right->left == NULL && d_node->right->right == NULL)
		{
			d_node->data.value = d_node->right->data.value;
			removeLeaf(bst, d_node->right);
		}

		else if(d_node->right->left == NULL)
		{
			d_node->data.value = d_node->right->data.value;
			shortCircuit(bst, d_node->right);
		}

		else
		{
			while(current->left != NULL)
			{
				current = current->left;
			}
			d_node->data.value = current->data.value;
			removeLeaf(bst, current);
		}
	}
}

Tree * clone(Tree * bst)
{
	Tree * t = createTree();
	t = traversen(bst->root, t);
	return t;
}

Tree * traversen(Node * node, Tree * ct)
{
	if(node != NULL)
	{
		insert(ct, node->data);
		traversen(node->left, ct);
		traversen(node->right, ct);
	}

	return ct;
}

int compare(Tree * t, Tree * copy)
{
	if(t == NULL || copy == NULL)
	{
		return 0;
	}
	int flag = compared(t->root, copy->root);

	return flag;
}

int compared(Node * node, Node * copy)
{
	int f = 1;

	if(node!= NULL && copy!= NULL)
	{
		if(node->data.value == copy->data.value)
		{
			f = 1;
			compared(node->left, copy->left);
			compared(node->right, copy->right);
		}
		else
		{
			return f;
		}
	}

	else if(node == NULL && copy == NULL)
	{
		f = 1;
	}
	return f;
}

void deleteTree(Tree * bst)
{
	if(bst->root == NULL)
	{
		free(bst->root);
		free(bst);
		return;
	}

	else
	{
		deleteData(bst, bst->root);
		free(bst);
		bst = NULL;
	}
}

void deleteData(Tree * bst, Node * current)
{

	if(current == NULL)
	{
		return;
	}

	else if(current != NULL)
	{
		deleteData(bst, current->left);
		deleteData(bst, current->right);
		removeLeaf(bst, current);
	}
}
