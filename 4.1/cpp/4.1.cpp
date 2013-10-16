#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 100;
struct Node{
    int key;
    Node *lchild, *rchild, *parent;
};
Node *head, *p, node[maxn];
int cnt;

int getHeight(Node *head){
    if(head == NULL) return 0;
    else return max(getHeight(head->lchild), getHeight(head->rchild)) + 1;
        
}
bool isBanlance(Node *head){
    if(head == NULL) return true;
    int dif = getHeight(head->lchild) - getHeight(head->rchild);
    if(abs(dif) > 1)
        return false;
    else
        return isBanlance(head->lchild) && isBanlance(head->rchild);
}
void init(){
    head = p = NULL;
    memset(node, '\0', sizeof(node));
    cnt = 0;
}
void insert(Node* &head, int x){
    if(head == NULL){
        node[cnt].key = x;
        node[cnt].parent = p;
        head = &node[cnt++];
        return;
    }
    p = head;
    if(x < head->key)
        insert(head->lchild, x);
    else
        insert(head->rchild, x);
}
int main(){
    init();
    int a[] = {
        5, 3, 8, 1, 4, 7, 10, 2, 6, 9, 11, 12
    };
    for(int i=0; i<12; ++i)
        insert(head, a[i]);
    cout<<isBanlance(head)<<endl;
    return 0;
}
