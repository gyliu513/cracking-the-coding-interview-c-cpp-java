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
    if (start < end) {
        int mid = (start + end) >> 1;
        node[cnt].key = a[mid];
        node[cnt].parent = head;
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

int main()
{
    memset(node, '\0', sizeof(node));
    Node *head1 = NULL, *head2 = NULL;
    int a1[] = {0,1,2,3,4,5,6,7};
    int a2[] = {0,1,2};
    createMinimialTree(head1, NULL, a1, 0, sizeof(a1)/sizeof(a1[0]));
    createMinimialTree(head2, NULL, a2, 0, sizeof(a2)/sizeof(a2[0]));
    cout << containTree(head1, head2) << endl;
}
