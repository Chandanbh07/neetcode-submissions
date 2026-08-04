class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sets;
        helper(nums,sets,0);
        return ans;
    }

    void helper(vector<int>& nums, vector<int>& sets, int idx){
        if(idx == nums.size()){
            ans.push_back(sets);
            return;
        }

        helper(nums,sets,idx+1);
        sets.push_back(nums[idx]);
        helper(nums,sets,idx+1);
        sets.pop_back();
    }
};
