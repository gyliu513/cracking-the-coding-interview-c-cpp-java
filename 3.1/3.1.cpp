#include <iostream>
using namespace std;

strcut node {
    int val;
    int preIndex;
};

class mystack{
    public:
        mystack(int size=900) {
            buf = new node[size];    
            ptop[0] = ptop[1] = ptop[2] = -1
            cur = 0;
        }
        virtual ~mystack() {
            delete [] buf;
        }
        void push(int stackNum, int val) {
            but[cur].val = val;
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
        
}