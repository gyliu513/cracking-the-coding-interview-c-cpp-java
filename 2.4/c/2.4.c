#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _node
{
        struct _node * next;
        int content;
} node;
node *createLinkedList(int num);
void printLinkedList(const node *listHead);
int getValFromList(const node *num);
node *addLinkedList(const node *num1, const node *num2);
int main()
{
        int num1 = 617;
        int num2 = 295;
        const node *num1List = createLinkedList(num1);
        const node *num2List = createLinkedList(num2);
        printf("(");
        printLinkedList(num1List);
        printf(") + (");
        printLinkedList(num2List);
        printf("). That is, %d + %d.\n", getValFromList(num1List), getValFromList(num2List));
        node *result = addLinkedList(num1List, num2List);
        printLinkedList(result);
        printf(". That is, %d.\n", getValFromList(result));
        return 0;
}
 
node *addLinkedList(const node *num1, const node *num2)
{
        int n1 = getValFromList(num1);
        int n2 = getValFromList(num2);
        node *result = createLinkedList(n1+n2);
        return result;
}
 
int power(int base, int exp)
{
        int result = 1;
        while(exp)
        {
                result *= base;
                exp--;
        }
        return result;
}
 
int getValFromList(const node *num)
{
        int result = 0;
        int countDigit = 0;
        node *p = num->next;
 
        while(p)
        {
                result += (p->content)*(power(10, countDigit));
                countDigit++;
                p = p->next;
        }
 
        return result;
}
void printLinkedList(const node *listHead)
{
        node *p = listHead->next;
        while(p->next)
        {
                printf("%d->", p->content);
                p = p->next;
        }
        printf("%d", p->content);
}
node *createLinkedList(int num)
{
        node *head = (node*)malloc(sizeof(node));
        if(head == NULL)
        {
                printf("Allocate head failed.\n");
                return NULL;
        }
        head->next = NULL;
        node *rear = head;
        int n = num * 10;
        //Create the linked list
        int i;
        for(i=0; n/=10; i++)
        {
                node *p = (node*)malloc(sizeof(node));
                if(p == NULL)
                {
                        printf("Allocate head failed.\n");
                        return NULL;
                }
                p->content = n%10;
                rear->next = p;
                rear = p;
        }
        rear->next = NULL;
        return head;
}
