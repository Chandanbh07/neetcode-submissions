class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<int,int> bracket = {
            {')','('} , {']','['} ,{'}','{'}
        };

        for(char c : s){
            if( c == '{' || c == '(' || c == '['){
                st.push(c);
            }else{
                if(st.empty() || st.top() != bracket[c]) return false;
                st.pop();
            }

        }

        return (st.empty());
    }
};
