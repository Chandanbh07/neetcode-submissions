class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return helper(nums,0,-1);
    }

    int helper(vector<int>& nums , int idx , int prev){
        int n = nums.size();
        if(idx == n) return 0;

        int notpick = 0+helper(nums,idx+1,prev);
        int pick = 0;
        if(prev == -1 || nums[prev] < nums[idx]) pick = 1+helper(nums,idx+1,idx);

        return max(notpick,pick);
    }
};
