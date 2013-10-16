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
                        --cur;
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

int sortStack(mystack s, mystack &t)
{
        while(!s.empty())
        {
                int tmp = s.top();
                s.pop();
                while(!t.empty() && t.top() > tmp)
                {
                        s.push(t.top());
                        t.pop();
                }
                t.push(tmp);
        }
        return 0;
}
int main()
{
        mystack q;
        q.push(3);
        q.push(2);
        q.push(1);
        mystack t;
        sortStack(q, t);
        cout << endl;
        while(!t.empty())
        {
                cout << t.top() << " ";
                t.pop();
        }
        cout << endl;
}

