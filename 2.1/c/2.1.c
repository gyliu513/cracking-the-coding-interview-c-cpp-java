#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
        struct _node *next;
        int key;
} node;

node *createLinkedList(int a[], int n) {
        node *head = (node*)calloc(1, sizeof(node));
        head->next = NULL;
        node *rear = head;

        int i;
        for (i=0; i<n; i++) {
                node *n = (node*)calloc(1, sizeof(node));
                n->key = a[i];
                rear->next = n;
                rear = n;
        }
        rear->next = NULL;
        return head;
}

int removeDup(const node* head) {
        node *p = head->next;
        while(p) {
                node *q = p->next;
                node *prev = p;
                while(q) {
                        if (p->key == q->key) {
                                node *delNode = q;
                                prev->next = q->next;
                                q = q->next;
                                printf("node %d deleted!\n", delNode->key);
                                free(delNode);
                                delNode = NULL;
                        } else {
                                q= q->next;
                        }
                        prev = prev->next;
                }
                p = p->next;
        }
}

void printList(node *head) {
        node *p = head->next;
        while(p) {
                printf("%d ", p->key);
                p = p->next;
        }
        printf("\n");
}

int main()
{
        int a[] = {1,2,3,4,2,4,7,8};
        int i;
        for (i=0; i<sizeof(a)/sizeof(a[0]); i++) {
                printf("%d ", a[i]);
        }
        printf("\n");
        node *head = createLinkedList(a, sizeof(a)/sizeof(a[0]));
        printList(head);
        removeDup(head);
        printList(head);

}
