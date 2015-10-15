class Stack {
public:
    queue<int> stack;
    // Push element x onto stack.
    void push(int x) {
        stack.push(x);
    }
    
    // Removes the element on top of the stack.
    void pop() {
        queue<int> tmp;
        int length = stack.size() - 1;
        for (int i = 0; i < length; i++) {
            tmp.push(stack.front());
            stack.pop();
        }
        stack = tmp;
    }
    
    // Get the top element.
    int top() {
        return stack.back();
    }
    
    // Return whether the stack is empty.
    bool empty() {
        return stack.empty();
    }
    
};