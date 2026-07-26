class MinStack {
public:
    stack<long long> st;
    long long minval;

    MinStack() {
        minval = LLONG_MAX;

    }
    
    void push(int val) {
        long x = val;
        if(st.empty()){
            st.push(x);
            minval = x;
        }
        else{
            if(x < minval){
                st.push(2LL * x - minval);
                minval = x;
            }
            else{
                st.push(x);
            }
        }
    }
    
    void pop() {
        if(st.top() < minval){
            minval = 2LL * minval - st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.top() < minval){
            return minval;
        }
        return st.top();
    }
    
    int getMin() {
        return minval;
    }
};
