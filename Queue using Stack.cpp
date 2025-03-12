#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks {
private:
    stack<int> stack1, stack2;

public:
    void enqueue(int x) {
        stack1.push(x);
    }

    int dequeue() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if (stack2.empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        int front = stack2.top();
        stack2.pop();
        return front;
    }
};

int main() {
    QueueUsingStacks q;
    q.enqueue(1);
    q.enqueue(2);
    cout << q.dequeue() << endl; 
    cout << q.dequeue() << endl; 
}
