class Solution {
public:
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return ans;
        string curr;

        vector<string> mappings = {
            "" , "" , "abc" , "def" , "ghi" ,
            "jkl" , "mno" , "pqrs" , "tuv" , 
            "wxyz"
        };
        helper(digits,mappings,curr,0);

        return ans;
    }

    void helper(string digits, vector<string>& mappings, string& curr, int idx){
        if(idx == digits.size()){
            ans.push_back(curr);
            return;
        }

        string chars = mappings[digits[idx] - '0'];

        for(char c:chars){
            curr.push_back(c);
            helper(digits,mappings,curr,idx+1);
            curr.pop_back();
        }
    }
};
