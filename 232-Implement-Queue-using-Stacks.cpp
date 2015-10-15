#include <stack>


class Queue {
public:
    std::stack<int> stack;
    std::stack<int> tmp;
    // Push element x to the back of queue.
    void push(int x) {
        int n = stack.size();
        for (int i = 0; i < n; i++) {
            tmp.push(stack.top());
            stack.pop();
        }
        stack.push(x);
        for (int i = 0; i < n; i++) {
            stack.push(tmp.top());
            tmp.pop();
        }
    }
    
    // Removes the element from in front of queue.
    void pop(void) {
        stack.pop();
    }
    
    // Get the front element.
    int peek(void) {
        return stack.top();
    }
    
    // Return whether the queue is empty.
    bool empty(void) {
        return stack.empty();
    }
};