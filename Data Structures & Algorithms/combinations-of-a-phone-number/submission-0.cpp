class Solution {
public:
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return ans;
        vector<string> mapping = {
            "" , "" , "abc" , "def" ,
            "ghi" , "jkl" ,"mno" ,"pqrs" ,
            "tuv" , "wxyz"
        };

        string cur="";

        backtrack(digits,0,mapping,cur,ans);
        return ans;
    }

    void backtrack(string digits , int idx , vector<string>& mapping , string& cur , vector<string>& ans){
        if(idx == digits.size()){
            ans.push_back(cur);
            return;
        }

        string letters = mapping[digits[idx] - '0'];

        for(char c:letters){
            cur.push_back(c);
            backtrack(digits , idx+1 , mapping , cur , ans);
            cur.pop_back();
        }
    }
};
