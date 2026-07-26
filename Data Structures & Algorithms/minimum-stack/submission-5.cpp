class MinStack {
public:
    stack<pair<int,int>> st;
    int minval;

    MinStack() {
        minval = INT_MAX;
    }
    
    void push(int val) {
        if(st.empty()){
            minval= val;
            st.push({val,minval});
        }
        else{
            minval = min(minval, val);
            st.push({val,minval});
        }
    }
    
    void pop() {
        st.pop();
        if(!st.empty())
          minval = st.top().second;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
