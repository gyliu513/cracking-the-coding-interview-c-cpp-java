#include <iostream>
using namespace std;

class mystack
{
        public:
                mystack(int capa=10) 
                {
                        buf = new int[capa];
                        cur = -1;
                        capacity=capa;
                }
                void push(int val) 
                {
                        buf[++cur] = val;
                }
                void pop()
                {
                        --cur;
                }

                int top()
                {
                        return buf[cur];
                }

                bool full()
                {
                        return cur == capacity-1;
                }
                bool empty()
                {
                        return cur == -1;
                }
        private:
                int *buf;
                int cur;
                int capacity;
};

class stackSet
{
        public:
                stackSet(int capa=10)
                {
                        s = new mystack[capa];
                        cur = 0;
                        capacity = capa;
                }
                virtual ~stackSet()
                {
                        delete[] s;
                }
                void push(int val)
                {
                        if (s[cur].full()) cur++;
                        s[cur].push(val);
                }
                void pop()
                {
                        if (s[cur].empty()) cur--;
                        s[cur].pop();
                }
                int top()
                {
                        if (s[cur].empty()) cur--;
                        return s[cur].top();
                }
                int popAt(int index)
                {
                        if (s[index].empty()) index--;
                        s[index].pop();

                }
                bool full()
                {
                        if (cur == capacity-1) return s[cur].full();
                        return false;
                }
        private:
                mystack *s;
                int cur;
                int capacity;
};

int main()
{
        stackSet s;
        for (int i=0; i<24; i++)
                s.push(i); 
        for (int i=0; i<7; i++)
                s.pop();
        cout << s.top() << endl;
}
