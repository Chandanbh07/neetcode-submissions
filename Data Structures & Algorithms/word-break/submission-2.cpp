class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> word(wordDict.begin(),wordDict.end());
        int n = s.size();
        vector<int> dp(n+1,-1);
        return helper(s,word,0,dp);
    }

    bool helper(string s,unordered_set<string>& word,int idx, vector<int>& dp){
        if(idx == s.size()) return true;

        if(dp[idx] != -1) return dp[idx];

        for(int end=idx+1;end<=s.size();end++){
            string sub = s.substr(idx,end-idx);
            if(word.count(sub)){
                if(helper(s,word,end,dp)) return dp[idx] = 1;
            }
        }
        return dp[idx]=0;
    }
};
