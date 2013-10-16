#include <iostream>
using namespace std;

class mystack
{
        public:
                mystack(int size=10)
                {
                        buf = new int[size];
                        cur = -1;
                }
                virtual ~mystack()
                {
                        delete[] buf;
                }
                void pop()
                {
                        cur--;
                }
                void push(int val)
                {
                        buf[++cur] = val;
                }
                int top()
                {
                        return buf[cur];
                }
                bool empty()
                {
                        return cur == -1;
                }
        private:
                int *buf;
                int cur;
};

class myQueue
{
        public:
                myQueue(){}
                virtual ~myQueue(){}
                void add(int val)
                {
                        s1.push(val);
                }
                void remove()
                {
                        if (!s2.empty()) s2.pop();
                        while(!s1.empty()) 
                        {
                                s2.push(s1.top());
                                s1.pop();
                        }
                        s2.pop();
                }
                int peek()
                {
                        if (!s2.empty()) return s2.top();
                        while(!s1.empty()) 
                        {
                                s2.push(s1.top());
                                s1.pop();
                        }
                        return s2.top();
                }
        private:
                mystack s1, s2;
};

int main()
{
        myQueue q;
        q.add(1);
        q.add(2);
        q.add(3);
        cout << q.peek() << endl;
}

