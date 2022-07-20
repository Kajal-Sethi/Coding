class MinStack {
public:
    stack<int> s;
    stack<int> ss;
    
    MinStack() {
        
    }
    
    void push(int a) {
        if(s.empty())
        {
            s.push(a);
            ss.push(a);
        }

        else if(ss.top()<a)
            s.push(a);

        else            // update min
        {
            s.push(a);
            ss.push(a);
        }
    }
    
    void pop() {
        int send = s.top();
        s.pop();

        if(send<=ss.top())
            ss.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        
        if(ss.empty())
            return -1;
        return ss.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */