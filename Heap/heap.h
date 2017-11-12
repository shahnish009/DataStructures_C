#ifndef heap_h
#define heap_h

typedef struct data
{
	int value;
}Data;

typedef struct heap
{
	Data * data;
	int current_size;
	int maximum_capacity;
}Heap;

Heap * initHeap(Data * );

void siftDown(Heap *, int);

void * heapify(Heap *);

Data removePriority(Heap *);

void deleteHeap(Heap *);

#endif
