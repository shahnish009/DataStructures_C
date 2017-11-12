#include"vector.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

Vector * initVector()
{
	Vector * vector = malloc(sizeof(Vector));
	vector->current_size = 0;
	vector->max_size = 0;
	vector->data = NULL;
	vector->index_array = NULL;

	return vector;
}

void vectorInsert(Vector * array, int index, Data value)					//Inserting data in the vector
{
	if(array->max_size <= index)
	{
		array->max_size = (index * 2) + 1;

		Data * new_array = malloc(sizeof(Data) * array->max_size);
		memset(new_array, -1, sizeof(Data) * array->max_size);

		int * extra = malloc(sizeof(int) * array->max_size);
		memset(extra, -1, sizeof(int) * array->max_size);

		if(array->data != NULL)
		{

			memcpy(new_array, array->data, sizeof(Data) * array->current_size);
			free(array->data);
			array->data = NULL;

			memcpy(extra, array->index_array, sizeof(int) * array->current_size);
			free(array->index_array);
			array->index_array = NULL;
		}

		array->data = new_array;
		array->index_array = extra;
	}

	array->data[index] = value;
	array->index_array[index] = index;

	if(index >= array->current_size)
        {
                array->current_size = index + 1;
        }

}

Data * vectorRead(Vector * array, int index)					//Reading data from the vector
{
	if(index <= array->max_size && index >= 0)
	{
		if(array->index_array[index] == -1)
		{
			return &(array->data[index]);
		}
		else
		{
			return &(array->data[array->index_array[index]]);
		}
	}
	else
	{
		return NULL;
	}

}

/*
void vectorRemove(Vector * array, int index)					//Remove Data from the vector
{
	if(index <= array->current_size && index >= 0)
	{
		Data * arraynew = malloc(sizeof(Data)*(array->current_size - 1));
		memset(arraynew, 0, sizeof(Data)*(array->current_size - 1));
		memcpy(arraynew, array->data, sizeof(Data) * index);
                memcpy(arraynew + index, array->data + index + 1, sizeof(Data) * ((array->current_size) - index - 1));
                free(array->data);

		array->data = NULL;
		array->data = arraynew;

		array->current_size = array->current_size - 1;
	}

	else
	{
		return;
	}

}
*/

void vectorRemove(Vector * array, int index)					//Vector remove operation stated as an extra credit
{
	int i;

        if(index <= array->current_size && index >= 0)
        {
		for(i = 0; i < index; i++)
		{
			array->index_array[i] = i;
		}

		for(i = index; i < array->current_size; i++)
		{
			array->index_array[i] = i + 1;
		}

		if(i == (array->current_size))
		{
			array->index_array[i] = -1;
		}

		array->current_size = array->current_size - 1;
	}
	else
        {
                return;
        }
}

void * deleteVector(Vector * vector)					//Deleting Pointers
{
	free(vector->data);
	vector->data = NULL;

	free(vector->index_array);
	vector->index_array = NULL;

	free(vector);
	vector = NULL;

	return NULL;
}

void vectorInsertIncremental(Vector * array, int index, Data value)					//Vector insert in incremental manner
{
	index = index + 1;
	if(array->max_size < index)
        {
                array->max_size = (index - 1) + 1;
                Data * new_array = malloc(sizeof(Data) * array->max_size);
                memset(new_array, 0, sizeof(Data) * array->max_size);
                memcpy(new_array, array->data, sizeof(Data) * array->current_size);
                free(array->data);
                array->data = NULL;
                array->data = new_array;
        }

        array->data[index-1] = value;

        if(index >= array->current_size)
        {
                array->current_size = index;
        }
}

void vectorInsertMine(Vector * array, int index, Data value)					//My own algorithm to increase the space of vector
{
	index = index + 1;
        if(array->max_size < index)
        {
                array->max_size = (index-1) * 3 + 1;
                Data * new_array = malloc(sizeof(Data) * array->max_size);
                memset(new_array, 0, sizeof(Data) * array->max_size);
                memcpy(new_array, array->data, sizeof(Data) * array->current_size);
                free(array->data);
                array->data = NULL;
                array->data = new_array;
        }

        array->data[index - 1] = value;

        if(index >= array->current_size)
        {
                array->current_size = index;
        }
}
