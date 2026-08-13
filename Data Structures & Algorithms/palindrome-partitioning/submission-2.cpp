class Solution {
public:
    vector<vector<string>> ans;

    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    void backtrack(string& s, vector<string>& path, int start) {
        // Entire string is partitioned
        if (start == s.size()) {
            ans.push_back(path);
            return;
        }

        for (int end = start; end < s.size(); end++) {

            // Check substring [start ... end]
            if (!isPalindrome(s, start, end))
                continue;

            // Choose
            path.push_back(s.substr(start, end - start + 1));

            // Explore
            backtrack(s, path, end + 1);

            // Backtrack
            path.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> path;
        backtrack(s, path, 0);

        return ans;
    }
};