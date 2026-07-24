class MinStack {
public:
    stack<long long> st;
    long long minval;

    MinStack() {
        minval = LLONG_MAX;
    }
    
    void push(int val) {
        long long x = val;
        if (st.empty()) {
            st.push(x);
            minval = x;
        } else if (x < minval) {
            // encode previous min
            st.push(2LL * x - minval);
            minval = x;
        } else {
            st.push(x);
        }
    }
    
    void pop() {
        if (st.empty()) return;
        long long topVal = st.top();
        st.pop();
        if (topVal < minval) {
            // decode previous min
            minval = 2LL * minval - topVal;
        }
        if (st.empty()) minval = LLONG_MAX; // reset when empty
    }
    
    int top() {
        if (st.empty()) return -1; 
        long long topVal = st.top();
        if (topVal < minval) return (int)minval;
        return (int)topVal;
    }
    
    int getMin() {
        return (int)minval;
    }
};
