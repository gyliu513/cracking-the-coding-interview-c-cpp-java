#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
        int key;
        struct _node *next;
} node;

node *createLinkedList(int a[], int n) {
        node *head = (node*)calloc(1, sizeof(node));
        head->next = NULL;
        node *rear = head;
        int i;
        for (i=0; i<n; i++) {
                node *p = (node*)calloc(1, sizeof(node));
                p->key = a[i];
                rear->next = p;
                rear = p;
        }
        rear->next = NULL;
        return head;
}

void printLinkedList(const node *head) {
        node *p = head->next;
        while (p) {
                printf("%d ", p->key);
                p = p->next;
        }
        printf("\n");
}

node *returnKthkey(node *head, int size, int n) {
        if (size < n) {
                return NULL;
        }
        node *p = head->next;
        node *q = p;
        while(q && n>0) {
                q = q->next;
                n--;
        }
        while(q) {
                q = q->next;
                p = p->next;
        }
        return p;
}

int main()
{
        int a[] = {1,2,3,4,5,6,7,8,9,10};
        int size = sizeof(a)/sizeof(a[0]);
        int i;
        for (i=0; i<size; i++) {
                printf("%d ", a[i]);
        }
        printf("\n");
        node *head = createLinkedList(a, size);
        printLinkedList(head);
        node *kth = returnKthkey(head, size, 4);
        printf("%d\n", kth->key);
}
