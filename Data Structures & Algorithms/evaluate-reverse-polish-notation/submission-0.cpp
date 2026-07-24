class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto &c:tokens){
            if(c == "+" || c == "-" || c=="*" || c=="/"){
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                int res = 0;

                if(c == "+") res = a+b;
                else if(c == "-") res = a-b;
                else if(c == "*") res = a*b;
                else res = a/b;

                st.push(res);
            }else{
                st.push(stoll(c));
            }
        }
        return st.top();
    }
};
