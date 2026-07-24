class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int start = 0;
        int maxLen = 1;

        // All single characters are palindromes
        for (int i = 0; i < n; i++) dp[i][i] = true;

        // Fill DP table
        for (int len = 2; len <= n; len++) {  // substring length
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;

                if (s[i] == s[j]) {
                    if (len <= 3) {
                        dp[i][j] = true; // length 2 or 3 -> automatically palindrome
                    } else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                } else {
                    dp[i][j] = false;
                }

                if (dp[i][j] && len > maxLen) {
                    start = i;
                    maxLen = len;
                }
            }
        }

        return s.substr(start, maxLen);
    }
};

