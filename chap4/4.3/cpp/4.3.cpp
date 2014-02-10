#include <iostream>
#include <cstring>
#include <cmath>
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
}

