class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        min_current = INT_MAX;
    }
    
    void push(int x) {
        values.push_back(x);
        if (min_current > x) min_current = x;
        minval.push_back( min_current );
    }
    
    void pop() {
        size_t n = values.size();
        if(n==0) return;
        values.erase( values.begin() + n - 1);
        minval.erase( minval.begin() + n - 1);
        n--;
        if(n>0) min_current = minval[n-1];
        else    min_current = INT_MAX;
    }
    
    int top() {
        return values[ values.size() - 1];
    }
    
    int getMin() {
        return minval[ minval.size() - 1];
    }
private:
    vector<int> values;
    vector<int> minval;
    int min_current;

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
