class Solution {
public:

    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> subs;
        helper(nums,subs,0);
        
        return ans;
    }

    void helper(vector<int>& nums, vector<int>& subs, int idx){
        if(idx >= nums.size()) {
            ans.push_back(subs);
            return;
        }

       subs.push_back(nums[idx]);
       helper(nums,subs,idx+1);

       subs.pop_back();

       //dublicate handling
       int i = idx+1;
       while(i>0 && i < nums.size() && nums[i] == nums[i-1]) i++;
       helper(nums,subs,i);
    }
};
