#include <iostream>
#include <stack>
using namespace std;

class DequeUsingStacks {
private:
    stack<int> stack1, stack2;

public:
    void pushFront(int x) {
        stack2.push(x);
    }

    void pushBack(int x) {
        stack1.push(x);
    }

    int popFront() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if (stack2.empty()) {
            cout << "Deque is empty!\n";
            return -1;
        }
        int front = stack2.top();
        stack2.pop();
        return front;
    }

    int popBack() {
        if (stack1.empty()) {
            while (!stack2.empty()) {
                stack1.push(stack2.top());
                stack2.pop();
            }
        }
        if (stack1.empty()) {
            cout << "Deque is empty!\n";
            return -1;
        }
        int back = stack1.top();
        stack1.pop();
        return back;
    }
};

int main() {
    DequeUsingStacks dq;
    dq.pushFront(1);
    dq.pushBack(2);
    cout << dq.popFront() << endl; 
    cout << dq.popBack() << endl;  
}
