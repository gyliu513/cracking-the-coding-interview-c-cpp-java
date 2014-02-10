#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <list>
using namespace std;

struct Node {
	int key;
	Node *parent, *lchild, *rchild;
};

Node node[100];
int cnt = 0;

int createMinimalHeightTree(Node* &head, Node* parent, int a[], int start, int end)
{
	if (start <= end) {
		int mid = (start+end) >> 1;
		node[cnt].key = a[mid];
		node[cnt].parent = parent;
		head = &node[cnt++];
		createMinimalHeightTree(head->lchild, head, a, start, mid-1);
		createMinimalHeightTree(head->rchild, head, a, mid+1, end);
	}
}

int height(Node *head) {
	if (head == NULL)
		return 0;
	return max(height(head->lchild), height(head->rchild)) + 1;
}

int init()
{
	memset(node, '\0', sizeof(node));
}

vector<list<Node*> > find_level_linklists(Node *head) {
    vector<list<Node*> > res;
    list<Node*> li;
    int level = 0;
    li.push_back(head);
    res.push_back(li);

    while (!res[level].empty()) {
        list<Node *> l;
        list<Node *>::iterator it;
        for (it=res[level].begin(); it!=res[level].end(); it++) {
            Node *n = *it;
            if (n->lchild) l.push_back(n->lchild);
            if (n->rchild) l.push_back(n->rchild);
        }
        level++;
        res.push_back(l);
    }
    return res;
}

void print_level(vector<list<Node*> > res) {
    vector<list<Node*> >::iterator it;
    for (it=res.begin(); it!=res.end(); it++) {
        list<Node *> li = *it;
        list<Node *>::iterator lit;
        for (lit=li.begin(); lit!=li.end(); lit++) {
             Node *n = *lit;
             cout << n->key << " ";
        }
        cout << endl;
    }
}

int main()
{
	//int a[] = {1, 2, 3, 4, 5, 6};
	int a[] = {
		0, 1, 2, 3, 4, 5, 6, 7, 8
	};
	init();
	Node *head = NULL;
	createMinimalHeightTree(head, NULL, a, 0, sizeof(a)/sizeof(a[0]));
	cout << height(head) << endl;
        vector<list<Node*> > res;
        res = find_level_linklists(head);
        print_level(res);
}

