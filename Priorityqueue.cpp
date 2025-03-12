#include <iostream>
#include <stack>
using namespace std;

class PriorityQueueUsingStack {
private:
    stack<int> s;

public:
    void push(int x) {
        stack<int> temp;
        while (!s.empty() && s.top() > x) {
            temp.push(s.top());
            s.pop();
        }
        s.push(x);
        while (!temp.empty()) {
            s.push(temp.top());
            temp.pop();
        }
    }

    int pop() {
        if (s.empty()) {
            cout << "Priority Queue is empty!\n";
            return -1;
        }
        int top = s.top();
        s.pop();
        return top;
    }
};

int main() {
    PriorityQueueUsingStack pq;
    pq.push(3);
    pq.push(1);
    pq.push(4);
    cout << pq.pop() << endl; 
    cout << pq.pop() << endl;
}
