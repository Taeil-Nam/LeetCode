class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        container.push(val);
        if (minStack.empty())
            minStack.push(val);
        else
            minStack.push(min(minStack.top(), val));
    }
    
    void pop() {
        container.pop();
        minStack.pop();
    }
    
    int top() {
        return container.top();
    }
    
    int getMin() {
        return minStack.top();
    }

private:
    stack<int> container;
    stack<int> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */