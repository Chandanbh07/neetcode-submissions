class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> combo;
        helper(nums,combo,target,0);
        return ans;
    }

    void helper(vector<int>& nums,vector<int>& combos,int target , int idx){
        if(target == 0){
            ans.push_back(combos);
            return;
        }
        if(idx == nums.size()){
            return;
        }

        if(target >= nums[idx]){
            combos.push_back(nums[idx]);
            helper(nums,combos,target-nums[idx],idx);
            combos.pop_back();
        }
        helper(nums,combos,target,idx+1);
    }
};
