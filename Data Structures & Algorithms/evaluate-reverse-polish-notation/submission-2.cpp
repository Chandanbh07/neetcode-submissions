class Solution {
public:
    int evalRPN(vector<string>& token) {
        int n = token.size();
        stack<int> st;

        int i = 0;
        while(i < n){
            
            if(token[i] == "+"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                st.push(a+b);
            }else if(token[i] == "-"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                st.push(b-a);
            }else if(token[i] == "*"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                st.push(a*b);
            }else if(token[i] == "/"){
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();

                st.push(b/a);
            }else{
                st.push(stoi(token[i]));
            }
            i++;
        }
        return st.top();
    }
};
