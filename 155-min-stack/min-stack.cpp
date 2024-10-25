class MinStack {
public:
    stack<pair<int,int>> st;
    int mini;
    MinStack() {
        mini = INT_MAX;
    }
    
    void push(int val) {
        mini = min(mini, val);
        st.push({val, mini});
    }
    
    void pop() {
        st.pop();
        if(st.size() == 0) mini = INT_MAX;
        else if(st.top().second > mini) mini = st.top().second;
    }
    
    int top() {
        if(st.size()) return st.top().first;
        return -1;
    }
    
    int getMin() {
        if(st.size()) return st.top().second;
        return -1;
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