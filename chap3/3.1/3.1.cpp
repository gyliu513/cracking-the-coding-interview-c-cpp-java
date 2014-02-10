#include <iostream>
using namespace std;

struct node {
    int val;
    int preIndex;
};

class mystack{
    public:
        mystack(int size=900) {
            buf = new node[size];    
            ptop[0] = ptop[1] = ptop[2] = -1;
            cur = 0;
        }
        virtual ~mystack() {
            delete [] buf;
        }
        void push(int stackNum, int val) {
            buf[cur].val = val;
            buf[cur].preIndex = ptop[stackNum];
            ptop[stackNum] = cur;
            cur++;
        }
        int top(int stackNum) {
            return buf[ptop[stackNum]].val;
        }

        void pop(int stackNum) {
            ptop[stackNum] = buf[ptop[stackNum]].preIndex;
        }
        void empty(int stackNum) {
            ptop[stackNum] = -1;
        }
    private:
        int ptop[3];
        node *buf;
        int cur;
        
};

int main()
{
    mystack s;
    s.push(0, 1);
    s.push(0, 2);
    s.push(0, 3);
    s.push(1, 4);
    s.push(1, 5);
    s.push(1, 6);
    s.push(2, 7);
    s.push(2, 8);
    s.push(2, 9);
    cout << s.top(0) << endl;
    cout << s.top(1) << endl;
    cout << s.top(2) << endl;
    return 0;
}
