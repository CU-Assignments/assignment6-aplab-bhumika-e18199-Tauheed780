#include <iostream>
#include <stack>
using namespace std;

class MaxStack {
private:
    stack<int> stack1, maxStack;

public:
    void push(int x) {
        stack1.push(x);
        if (maxStack.empty() || x >= maxStack.top()) {
            maxStack.push(x);
        }
    }

    void pop() {
        if (!stack1.empty()) {
            if (stack1.top() == maxStack.top()) {
                maxStack.pop();
            }
            stack1.pop();
        }
    }

    int top() {
        return stack1.empty() ? -1 : stack1.top();
    }

    int getMax() {
        return maxStack.empty() ? -1 : maxStack.top();
    }
};

int main() {
    MaxStack ms;
    ms.push(1);
    ms.push(5);
    ms.push(3);
    cout << ms.getMax() << endl; 
    ms.pop();
    cout << ms.getMax() << endl; 
}
