class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0) return 0;
        if(s[0] == '0') return 0;

        vector<int> dp(n+1,0);
        return helper(s,n,dp);
    }

    int helper(string s, int idx ,vector<int>& dp){
        dp[0] = 1;
        if(s[0] != '0') dp[1] = 1;

        for(int i=2;i<=idx;i++){
            if(s[i-1] != '0'){
                dp[i]+=dp[i-1];
            }
            
            int two = (s[i-2]-'0')*10 + (s[i-1]-'0');
            if(two >= 10 && two <= 26){
                dp[i] += dp[i-2];
            }
        }
        return dp[idx];
    }
};
