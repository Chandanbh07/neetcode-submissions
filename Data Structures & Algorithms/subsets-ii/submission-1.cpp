class Solution {
public:

    set<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> subs;
        helper(nums,subs,0);
        vector<vector<int>> res;
        for(auto val: ans){
            res.push_back(val);
        }
        return res;
    }

    void helper(vector<int>& nums, vector<int>& subs, int idx){
        if(idx == nums.size()) {
            ans.insert(subs);
            return;
        }
        helper(nums,subs,idx+1);
        subs.push_back(nums[idx]);
        helper(nums,subs,idx+1);
        subs.pop_back();

    }
};
