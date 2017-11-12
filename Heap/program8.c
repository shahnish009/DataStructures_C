#include "heap.h"
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main()
{
	printf("\n\n\t*****Test 1: Initialize Heap*****\n\n\n");

	printf("\tInserting 1000 random Data objects in an Data array...\n\n");

	int i;
	Data data[1000];

	for(i = 0; i < 1000; i++)
	{
		data[i] = (Data){((rand() % 1000) + 1)};
//printf("Inserting: %d\t", data[i]);
	}

	printf("\n\tInitializing Heap...\n\n\n");

	Heap * h = initHeap(data);

	printf("\tConverting the array into Heap using Heapify...\n\n\n");

	printf("\tUsing Siftdown to maintain the Heap structure...\n\n\n");

	printf("\t*****Test 1 passed*****\n\n\n");

        printf("\t*****Test 2: Removing Priority Values*****\n\n\n");

	printf("\tRemoving the priorities from the heap using removePriority...\n\n");

	Data prev = data[0];

	for(i = 0; i < 1000; i++)
	{
		Data next = removePriority(h);
//printf("Priority: %d\t", next);
		assert(prev.value <= next.value);

		prev = next;
	}

	printf("\n\t*****Test 2 passed*****\n\n\n");

	printf("\tDeleting heap and deallocating the memory...\n\n\n");

	deleteHeap(h);

	printf("\t*****Memory freed and the program is ready*****\n\n\n");

	return 0;
}
