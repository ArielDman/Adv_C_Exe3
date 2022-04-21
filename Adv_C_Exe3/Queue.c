#include <stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
#include "Queue.h"

/***************** Queue ADT Implementation *****************/




void initQueue(Queue* q)
{
	q->head = q->tail = NULL;
}

void destroyQueue(Queue* q)
{
	do
	{
		dequeue(q);
	} 
	while (!isEmptyQueue(q));
}

void enqueue(Queue* q, unsigned int data)
{
	intNode* p = (intNode*)malloc(sizeof(intNode));
	
	p->data = data;
	p->next = NULL;

	if (!isEmptyQueue(q))
	{
		q->tail->next = p;
		q->tail = p;
	}
	else
	{
		q->head = p;
		q->tail = q->head;
	}
}

unsigned int dequeue(Queue* q)
{
	if (isEmptyQueue(q))
	{
		printf("\ncannot dequeue an empty queue");
		return 0;
	}
	int temp = q->head->data;
	intNode* p = q->head;
	q->head = q->head->next;

	if (q->head == NULL)
		q->tail = NULL;

	free(p);
	return temp;
}

int isEmptyQueue(const Queue* q)
{
	if (q->head == NULL && q->tail==NULL)
	{
		return 1;
	}
	else
		return 0;
}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
	if (isEmptyQueue(q) == 1)
		printf("Cant rotate an empty Queue");
	else
		enqueue(q, dequeue(q));
}


void cutAndReplace(Queue* q)
{
	intNode* tmp;
	tmp = q->head;
	int counter = 0;
	int sum = 0;
	while (tmp != NULL)
	{
		counter++;
		sum = sum + tmp->data;
		tmp = tmp->next;
	}
	int avg = sum / counter;

	if (counter % 2 == 1)
	{
		enqueue(q, avg);
		counter += 1;
	}

	Queue help;
	initQueue(&help);

	for (int i = 0; i < counter/2; i++)
	{
		enqueue(&help, dequeue(q));
	}
	reverse(q);
	
	q->tail->next = (&help)->head;
	q->tail= (&help)->tail;
}

void reverse(Queue* queue) 
{
	int element;
	if (isEmptyQueue(queue)) {
		return;
	}
	element = dequeue(queue);
	reverse(queue);
	enqueue(queue, element);
}


void sortKidsFirst(Queue* q)
{
	int swapped, i;
	intNode* ptr1;
	intNode* lptr = NULL;

	/* Checking for empty list */
	if (q->head == NULL)
		return;

	do
	{
		swapped = 0;
		ptr1 = q->head;

		while (ptr1->next != lptr)
		{
			if (ptr1->data > ptr1->next->data)
			{
				swap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	} while (swapped);
}


void swap(intNode* a,intNode* b)
{
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

void printQ(Queue* q)
{
	intNode* head;
	head = q->head;
	while (head != NULL)
	{
		printf("%d", head->data);
		head = head->next;
	}
}