#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Stack.h"
#include "Queue.h"
#define _CRT_SECURE_NO_WARNINGS


void main()
{
	//flipBetweenHashes test
	/*const char sentence[30] = {"remem#reb# th#si#ttt"};

	
	flipBetweenHashes(sentence);*/


	//is palindrome tesd

	//Stack s;
	//initStack(&s);
	//push(&s,'e');
	//push(&s,'d');
	//push(&s,'c');
	//push(&s,'b');
	//push(&s,'a');

	//printf("%d",isPalindrome(&s));

	//rotateStack test

	//display(&s);
	//rotateStack(&s,2);
	//printf("\n");
	//display(&s);

	Queue q;
	initQueue(&q);
	enqueue(&q, 6);
	enqueue(&q, 1);
	enqueue(&q, 5);
	enqueue(&q, 2);
	enqueue(&q, 3);
	enqueue(&q, 9);

	//rotate Q test
	// 
	//rotateQueue(&q);

	//printQ(&q);
	//printf("\n");
	//cutAndReplace(&q);
	//printQ(&q);
	
	printQ(&q);
	printf("\n");
	sortKidsFirst(&q);
	printQ(&q);
}