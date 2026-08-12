class Solution {
public:
    vector<string> ans;
    int pairs;
    vector<string> generateParenthesis(int n) {
        string all_sets;
        pairs = n;
        helper(all_sets,2*n,0,0);
        return ans;
    }

    void helper(string& st, int n,int open,int close){
        if(open + close > 2*pairs) return;
        
        if(n == 0){
            ans.push_back(st);
            return;
        }

        if(open < pairs){
            st += '(';
            helper(st,n-1,open+1,close);
            st.pop_back();
        }
        if(close < pairs && open > close){
            st.push_back(')');
            helper(st,n-1,open,close+1);
            st.pop_back();
        }
    }
};
