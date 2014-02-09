#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _node
{
        struct _node * next;
        int content;
} node;
node *createLinkedList(int list[], int length);
void printLinkedList(const node *listHead);
void partitionAtX(node *listHead, int x);

int main()
{
        int list[8] = {5, 4, 3, 1, 5, 2, 1, 0};
        node *head = createLinkedList(list, 8);
        int x = 3;

        printf("Original:\t");
        printLinkedList(head);
        partitionAtX(head, x);
        printf("Partition:\t");
        printLinkedList(head);

        return 0;
}

void partitionAtX(node *listHead, int x)
{
        node *head = listHead;
        node *tmpHead = (node*)malloc(sizeof(node));
        if(!tmpHead)
        {
                printf("Allocate head failed.\n");
                return;
        }
        tmpHead->next = NULL;
        node *tmpRear = tmpHead;
        node *prev = listHead;
        node *p = prev->next;
        while(p)
        {
                if(p->content < x)
                {
                        //insert p to the new list
                        tmpRear->next = p;
                        tmpRear = p;
                        //skip p
                        prev->next = p->next;
                        p = p->next;
                }
                else
                {
                        //move on
                        p = p->next;
                        prev = prev->next;
                }
        }
        //Link the new list and the old list
        tmpRear->next = head->next;

        *head = *tmpHead;
}
void printLinkedList(const node *listHead)
{
        node *p = listHead->next;
        while(p->next)
        {
                printf("%d->", p->content);
                p = p->next;
        }
        printf("%d\n", p->content);
}
node *createLinkedList(int list[], int length)
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
        rear->next = NULL;
        return head;
}
