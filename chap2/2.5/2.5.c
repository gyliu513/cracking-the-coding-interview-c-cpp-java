/*Input: A -> B -> C -> D -> E -> C [the same C as earlier]
Output: C
*/

/* This is one of the solution set to CareerCup 150 problems.
 * 
 * Problem 2.6
 *
 * Method: Use two pointers, one with speed 1 and another with speed 2,
 * they will end up meeting if the linked list has a loop. And when they meet, 
 * set the Slow Runner to the head, start iterate, and when they meet again,
 * the new meeting point will be the start of the loop.
 * 
 *
 * Author: Hu Kun (Kimurate)
 * Date: 03/03/2013
 * Compile command: gcc-4.7 2.6.c -std=c99
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct _node
{
	struct _node * next;
	int content;
} node;
 
node *createCircularLinkedList(int list[], int length);
node *findLoopStart(node *listHead);
 
int main()
{
	int list[6] = {5, 4, 3, 2, 1, 0};
	node *head = createCircularLinkedList(list, 6);
 
 	node *loopStart = findLoopStart(head);
 
 	if(loopStart)
 		printf("The start of the loop is: %d.\n", loopStart->content);
 	else
 		printf("This list is not a circular linked list.\n");
 
	return 0;
}
 
node *findLoopStart(node *listHead)
{
	node *fastRunner = listHead;	//speed 2
	node *slowRunner = listHead;	//speed 1
 
	//find the meeting point, if it exists
	while(fastRunner && fastRunner->next)
	{
		fastRunner = fastRunner->next->next;
		slowRunner = slowRunner->next;
		if(fastRunner == slowRunner)
			break;
	}
 
	if(!fastRunner->next || !fastRunner)
		return NULL;
 
	slowRunner = listHead;
	while(slowRunner != fastRunner)
	{
		slowRunner = slowRunner->next;
		fastRunner = fastRunner->next;
	}
 
	return fastRunner;
}
 
node *createCircularLinkedList(int list[], int length)
{
	node *head = (node*)malloc(sizeof(node));
	if(head == NULL)
	{
		printf("Allocate head failed.\n");
		return NULL;
	}
	head->next = NULL;
	node *rear = head;
 
	//Create the linked list
        int i, len;
	for(i=0, len=length; i<len; i++)
	{
		node *p = (node*)malloc(sizeof(node));
		if(p == NULL)
		{
			printf("Allocate head failed.\n");
			return NULL;
		}
		p->content = list[i];
		rear->next = p;
		rear = p;
	}
	//the start of the loop is the third element
	//namely, the list should be 5->4->3->2->1->0->3
	rear->next = head->next->next->next;
 
	return head;
}

