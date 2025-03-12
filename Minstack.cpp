#include <iostream>
#include <stack>
using namespace std;

class MinStack {
private:
    stack<int> stack1, minStack;

public:
    void push(int x) {
        stack1.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (!stack1.empty()) {
            if (stack1.top() == minStack.top()) {
                minStack.pop();
            }
            stack1.pop();
        }
    }

    int top() {
        return stack1.empty() ? -1 : stack1.top();
    }

    int getMin() {
        return minStack.empty() ? -1 : minStack.top();
    }
};

int main() {
    MinStack ms;
    ms.push(3);
    ms.push(5);
    cout << ms.getMin() << endl; 
    ms.push(2);
    ms.push(1);
    cout << ms.getMin() << endl; 
    ms.pop();
    cout << ms.getMin() << endl; 
}
