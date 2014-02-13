#include <iostream>
using namespace std;

#define MAX_INT ~(1<<31)

class mystack
{
    public:
        mystack(int size=1000)
        {
            buf = new int[size];
            cur = -1;
        }
        ~mystack()
        {
            delete[] buf;
        }
        void push(int val)
        {
            buf[++cur] = val;
        }
        void pop()
        {
            cur--;
        }
        int empty()
        {
            return cur == -1;
        }
        int top() 
        {
            return buf[cur];
        }
    private:
        int *buf;
        int cur;
};

class stackWithMin
{
    public:
        stackWithMin(){}
        ~stackWithMin(){}
        void push(int val) 
        {
            s1.push(val);
            if (val<min())
                s2.push(val);
        }
        void pop()
        {
            if (s1.top() == min()) 
            {
                int tmp = s1.top();
                s1.pop();
                if (s1.top() != min())
                    s2.pop();
            }
            s1.pop();
        }
        int top()
        {
            return s1.top();
        }
        int min()
        {
            if (s2.empty())  return MAX_INT;
            return s2.top();
        }

    private:
       mystack s1, s2;
};

int main()
{
    stackWithMin s;
    s.push(2);
    s.push(2);
    s.push(2);
    s.push(2);
    s.push(2);
    cout << s.min() << endl;
    s.pop();
    cout << s.min() << endl;
    s.pop();
    cout << s.min() << endl;
}
