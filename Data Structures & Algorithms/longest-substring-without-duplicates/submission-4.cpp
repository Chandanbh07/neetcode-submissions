class Solution {
public:
    int lengthOfLongestSubstring(string st) {
        unordered_set<int> s;
        int n = st.size();
        int left = 0;
        int right = 0;

        int maxi = 0;
        while(right < n){

            while(s.count(st[right])){
                s.erase(st[left]);
                left++;
            }

            s.insert(st[right]);
            maxi = max(maxi, right-left+1);
            right++;
        }

        return maxi;
    }
};
