class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> cur;
        helper(nums,target,n-1,cur);
        return ans;
    }

    void helper(vector<int>& nums,int target,int idx,vector<int>& cur){
        if(target == 0){
            ans.push_back(cur);
            return;
        }
        if (target < 0 || idx < 0) {
            return;
        }
        
        cur.push_back(nums[idx]);
        helper(nums,target-nums[idx],idx,cur);
        cur.pop_back();
        helper(nums,target,idx-1,cur);
    }
};
