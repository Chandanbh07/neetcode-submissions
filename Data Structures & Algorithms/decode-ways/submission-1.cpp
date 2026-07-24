class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if(n == 0) return 0;
        if(s[0] == '0') return 0;

        vector<int> dp(n,-1);
        return helper(s,0,dp);
    }

    int helper(string s, int idx ,vector<int>& dp){
        int n = s.size();
        if(idx == n) return 1;
        if(s[idx] == '0') return 0;

        if(dp[idx] != -1) return dp[idx];
        
        int count = 0;
        //single digit
        count += helper(s,idx+1,dp);

        //double digit
        if(idx+1<n){
            int two = (s[idx]-'0') * 10 +s[idx+1] - '0';
            if(two >= 10 && two <= 26){
                count += helper(s,idx+2,dp);
            }
        }
        return dp[idx] = count;
    }
};
