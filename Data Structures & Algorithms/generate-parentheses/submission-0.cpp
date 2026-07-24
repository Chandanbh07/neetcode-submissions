class Solution {
public:
    vector<string> s;
    vector<string> generateParenthesis(int n) {
        helper("",0,0,n);
        return s;
    }

    void helper(string cur , int open , int close , int n ){
        if(cur.size() == 2*n){
         s.push_back(cur);
         return;
        }

        if(open < n) helper(cur+'(', open+1, close, n);
        if(close < open) helper(cur+')' , open ,close+1 , n);
    }
};
