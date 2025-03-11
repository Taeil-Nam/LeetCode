class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        mStack.push(val);
        if (mMinStack.empty())
            mMinStack.push(val);
        else
            mMinStack.push(min(mMinStack.top(), val));
    }
    
    void pop() {
        mStack.pop();
        mMinStack.pop();
    }
    
    int top() {
        return mStack.top();
    }
    
    int getMin() {
        return mMinStack.top();
    }

private:
    stack<int> mStack;
    stack<int> mMinStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */