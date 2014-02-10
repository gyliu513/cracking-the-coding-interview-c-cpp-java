#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    int key;
    Node *parent, *lchild, *rchild;
};

Node node[100];

int cnt = 0;

Node *createMinimialTree(Node* &head, Node *parent, int a[], int start, int end) {
    if (start <= end) {
        int mid = (start + end) >> 1;
        node[cnt].key = a[mid];
        node[cnt].parent = parent;
        head = &node[cnt++];
        createMinimialTree(head->lchild, head, a, start, mid-1);
        createMinimialTree(head->rchild, head, a, mid+1, end);
    }
}

int match(Node *n1, Node* n2) {
    if (n1 == NULL && n2 == NULL) return true;
    else if (n1 == NULL || n2 == NULL) return false;
    else if (n1->key != n2->key) return false;
    else match(n1->rchild, n2->rchild) && match(n1->lchild, n2->lchild);
}

int subTree(Node* n1, Node* n2) {
    if (n1 == NULL) return false;
    else if (n1->key == n2->key) {
        if (match(n1, n2)) return true;
    } else {
        return subTree(n1->rchild, n2) || subTree(n1->lchild, n2);
    }
}

int containTree(Node *n1, Node *n2) {
    if (n2 == NULL) return true;
    return subTree(n1, n2);
}

int printSum(Node* node, int index) {
    for (int i=0; i<=index; i++) {
        cout << node->key << " ";
        node = node->parent;
    }
    cout << endl;
}

void findSum(Node* head, int sum) {
    Node *no = head;
    int tmp = 0;
    if (head == NULL) return;
    for (int i=0; no != NULL; i++) {
        tmp += no->key;
        if (tmp == sum) {
            printSum(head, i);
        }
        no = no->parent;
    }
    findSum(head->lchild, sum);
    findSum(head->rchild, sum);
}

int main()
{
    memset(node, '\0', sizeof(node));
    Node *head1 = NULL, *head2 = NULL;
    int a1[] = {0,1,2,3,4,5,6,7};
    int a2[] = {0,1,2};
    createMinimialTree(head1, NULL, a1, 0, sizeof(a1)/sizeof(a1[0]));
    createMinimialTree(head2, NULL, a2, 0, sizeof(a2)/sizeof(a2[0]));
    cout << containTree(head1, head2) << endl;
    cout << "==========================" << endl;
    int a[] = {
        4, 3, 8, 5, 2, 1, 6
    };
    Node *head = NULL;
    createMinimialTree(head, NULL, a, 0, sizeof(a)/sizeof(a[0]));
    findSum(head, 8);
}
