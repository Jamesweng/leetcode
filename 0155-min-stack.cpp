class MinStack {
private:
    vector<int> sortedList;
    stack<int> stk;
    
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        stk.push(x);
        if (sortedList.empty() || sortedList.back() >= x) {
            sortedList.push_back(x);
        }
    }
    
    void pop() {
        if (stk.top() == sortedList.back()) {
            sortedList.pop_back();
        } 
        stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return sortedList.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
