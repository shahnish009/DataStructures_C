#include<stdio.h>
#include<stdlib.h>
#include"list.h"

List * createList()			//Creates/Initializes the list
{
	List * list = malloc(sizeof(List));

	list->head = NULL;
	list->tail = NULL;
	list->index = 0;

	return;
}

void insertData(List * list, int index, Data value)			//insert data into the list
{
	if(list->index == 0)
	{
		Node * current = malloc(sizeof(Node));

		current->data = value;
		list->head = current;
		list->tail = current;
		list->head->prev = NULL;
		list->tail->next = NULL;

		list->index = list->index + 1;
	}

	else if(list->index <= index)
	{
		Node * current = malloc(sizeof(Node));

		current->data = value;
		list->tail->next = current;
		current->prev = list->tail;
		current->next = NULL;
		list->tail = current;

		list->index = list->index + 1;
	}
}

Data * readData(List * list, int index)			//read data from the list at specified index
{
	if(index > list->index)
	{
//		printf("\t\tTrying to read out of array bounds\n");

		return NULL;
	}

	else
	{
	  	Node * current = list->head;
        	int counter = 0;

        	while(current->next != NULL && counter < index)
        	{
			current->next->prev = current;
                	current = current->next;
			counter++;
        	}

        	return &current->data;
        }
}

int isEmpty(List * list)
{
	if(list->head == NULL)
	{
		return 1;
	}

	else
	{
		return 0;
	}
}

void deleteList(List * list)
{
	free(list);
	list = NULL;
}

int searchForward(List * list, Data value)			//search data from forward
{
	Node * current = list->head;
	int counter = 0;

	while((current->next != NULL) && ((current->data.value) != value.value))
	{
		current->next->prev = current;
		current = current->next;
		counter++;
	}

	if(current->next == NULL && current->data.value != value.value)
	{
		return -1;
	}

	else
	{
		return counter;
	}
}

int searchBackward(List * list, Data value)			//search data from backward
{
	Node * current = list->tail;
	int counter = 0;

	while((current->prev != NULL) && ((current->data.value) != value.value))
	{
		current->prev->next = current;
		current = current->prev;
		counter++;
	}

	if(current->prev == NULL && ((current->data.value) != value.value))
	{
		int counter = 0;

	        while(counter <= list->index && list->head != NULL)
        	{
                removeData(list, counter);
                counter++;
        	}

		free(list->head);
		list->head = NULL;
		free(list->tail);
		list->tail = NULL;
		return -1;
	}

	else
	{
		int counter = 0;

        	while(counter <= list->index && list->head != NULL)
        	{
                	removeData(list, counter);
                	counter++;
        	}

		return counter;
	}
}

void push(Stack * stack, Data value)			//push into stack
{
	int counter = value.value - 1;

	insertData(stack->list, counter, value);
}

Data pop(Stack * stack)			//pop out of stack
{
	if(stack->list->index == 1)
	{
		Node * temp = stack->list->tail;
		int res = temp->data.value;

	        stack->list->head = NULL;
	        stack->list->tail = NULL;

		free(temp);
		temp = NULL;

	        return (Data){res};
	}

	else
	{
		Node * temp = stack->list->tail;
		int res = temp->data.value;

	        stack->list->tail->prev->next = NULL;
	        stack->list->tail = stack->list->tail->prev;
	        stack->list->index = stack->list->index - 1;

		free(temp);
		temp = NULL;

	        return (Data){res};
	}
}

void enqueue(Queue * queue, Data value)			//enqueue element
{
	int counter = value.value - 1;

        insertData(queue->list, counter, value);

}

Data dequeue(Queue * queue)			//dequeue element
{
	if(queue->list->index == 1)
        {
                Node * temp = queue->list->tail;
                int res = temp->data.value;

                queue->list->head = NULL;
                queue->list->tail = NULL;
                free(temp);
                temp = NULL;

                return (Data){res};
        }

        else
        {
                Node * temp = queue->list->head;
                int res = temp->data.value;

                queue->list->head->next->prev = NULL;
                queue->list->head = queue->list->head->next;
                queue->list->index = queue->list->index - 1;
                free(temp);
                temp = NULL;

		return (Data){res};
	}
}

void removeData(List * list, int index)			//remove data from specified index
{
	if(list->index == 0)
	{
		return;
	}

	if(index >= list->index)
	{
		return;
	}

	else
	{
		if(list->head == list->tail)
		{
			free(list->head);
			free(list->tail);
			list->head = NULL;
			list->tail = NULL;

			return;
		}

		else if(index == 0)
		{
			Node * new_node = list->head;
			list->head = list->head->next;
			list->head->prev = NULL;

			free(new_node);
			new_node = NULL;

			list->index = list->index - 1;

			return;
		}

		else if(index == (list->index - 1))
		{
			Node * new_node = list->tail;
			list->tail->prev->next = NULL;
			list->tail = list->tail->prev;

			free(new_node);
			new_node = NULL;

			list->index = list->index - 1;

			return;
		}
		else if(index > 0)
		{
			Node * new_node = list->head;
			int counter = 0;

			while(counter != index)
			{
				new_node = new_node->next;
				counter++;
			}

			new_node->next->prev = new_node->prev;
			new_node->prev->next = new_node->next;

			free(new_node);
			new_node = NULL;

			list->index = list->index - 1;

			return;
		}
	}
}
