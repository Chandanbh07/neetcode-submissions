class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string> partitions;
        helper(s,partitions,ans);
        return ans;
    }

    void helper(string s , vector<string>& partitions , vector<vector<string>>& ans){
        if(s.size() == 0) ans.push_back(partitions);

        for(int i=0;i<s.size();i++){
            string part = s.substr(0,i+1);
            if(ispalin(part)){
                partitions.push_back(part);
                helper(s.substr(i+1),partitions,ans);
                partitions.pop_back();
            }
        }
    }

    bool ispalin(string s){
        int st = 0 , end = s.size()-1;
        while(st<=end){
            if(s[st] != s[end]) return false;
            st++;
            end--;
        }
        return true;
    }
};
