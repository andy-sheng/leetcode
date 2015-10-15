#include <stack>
class MinStack {
public:
    stack<int> data;
    stack<int> min;
    void push(int x) {
        if (data.size() == 0) {
            min.push(x);
        } else {
            if (x <= min.top()) {
                min.push(x);
            }
        }
        data.push(x);
    }
    
    void pop() {
        if (data.top() == min.top()) {
            min.pop();
        }
        data.pop();
    }
    
    int top() {
        return data.top();
    }
    
    int getMin() {
        return min.top();
    }
};