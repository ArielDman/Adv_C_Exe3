#include<stdio.h>
#include<stdlib.h>
#include "Stack.h"
#define MAXSIZE 10
/***************** Stack ADT Implementation *****************/




void initStack(Stack* s)
{
	s->head=NULL;
}

void destroyStack(Stack* s)
{
	charNode* tmp;
	while(s->head!=NULL)
	{
		tmp = s->head;
		s->head = s->head->next;
		free(tmp);
	}
}

void push(Stack* s, char data)
{
	charNode* newnode = (charNode*)malloc(sizeof(charNode));
	if (newnode==NULL) 
	{
		printf("\npush:memory allocation problem");
		return;
	}
	newnode->data = data;
	s->head = addToHead(s->head, newnode);
}

char pop(Stack* s)
{
	char item;
	if (s->head==NULL)
	{
		printf("\nSTACK IS EMPTY");
		return '\0';
	}
	item = s->head->data;
	removeItem(&(s->head)); //pop it from the stack
	return(item);
}


int isEmptyStack(const Stack* s)
{
	return (!(s->head));
}

charNode* addToHead(charNode* head, charNode* toAdd) {
	toAdd->next = head;
	head = toAdd;
	return head;
}

void removeItem(charNode** head) {
	if (*head == NULL)
		return; //if stack empty
	charNode* tmp = *head;
	*head = (*head)->next;
	free(tmp);
}

void display(Stack* s)
{
	print(s->head);
}

void print(charNode* head)
{
	charNode* tmp;
	tmp = head;
	while (tmp != NULL) {
		printf("%c", tmp->data);
		tmp = tmp->next;
	}
}



/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence)
{
	int i = 0, k = 0;


	while (sentence[k] != '\0')
	{
		Stack s;
		initStack(&s);
		while (sentence[i] != '#' && sentence[i] != '\0')
		{
			printf("%c", sentence[i]);	
			i++;
		}
		if (sentence[i] == '#')
		{
			int j = i + 1;
			while (sentence[j] != '#')
			{
				push(&s, sentence[j]);
				j++;
			}
			j++;
			display(&s);
			destroyStack(&s);
			i = j;
			k = j;
		}
		k++;
	}
}

int isPalindrome(Stack* s)
{
	return checkIsEqual(s, reverseStack(s));
}

int checkIsEqual(Stack* s1, Stack* s2)
{
	charNode* tmp1;
	charNode* tmp2;
	tmp1 = s1->head;
	tmp2 = s2;
	while (tmp1 != NULL)
	{
		if (tmp1->data != tmp2->data)
		{
			return 0;
		}
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
	destroyStack(&s2);
	return 1;
}

Stack* reverseStack(Stack* s1)
{
	charNode* tmp1;
	tmp1 = s1->head;
	Stack newS;
	initStack(&newS);
	while (tmp1 != NULL)
	{
		char c = tmp1->data;
		tmp1 = tmp1->next;
			push((&newS), c);
	}
	
	return (&newS)->head;
}

void rotateStack(Stack* s, int n)
{
	if (n < 0)
	{
		return;
	}

	if (s->head == NULL)
	{
		printf("\nstack is empty");
		return;
	}

	Stack s1, s2;
	initStack(&s1);
	initStack(&s2);

	charNode *tmp;
	tmp = s->head;

	int counter = 0;
	while (tmp->next != NULL)
	{
		counter++;
		tmp = tmp->next;
	}

	if (n > counter)
	{
		return;
	}
	for (int i = 0; i < counter - n; i++)
	{
		push((&s1), pop(s));
	}

	for (int i = 0; i <= n; i++)
	{
		push((&s2), pop(s));
	}

	while ((&s1)->head != NULL)
	{
		push(s, pop(&s1));
	}

	while ((&s2)->head != NULL)
	{
		push(s, pop((&s2)));
	}
	destroyStack(&s1);
	destroyStack(&s2);
}