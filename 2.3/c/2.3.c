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

int removeNode(node *del) {
        if (del->next == NULL) {
                free(del);
                del == NULL;
                return 0;
        }
        node *delNext = del->next;
        del->key = delNext->key;
        del->next = delNext->next;
        free(delNext);
        delNext = NULL;
        return 0;
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
        node *del = head->next->next->next;
        printf("node %d will be deleted!\n", del->key);
        removeNode(del);
        printLinkedList(head);
}
