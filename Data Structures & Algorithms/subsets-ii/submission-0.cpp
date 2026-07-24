class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       sort(nums.begin(),nums.end());

       vector<int> cur;
       helper(nums, 0 , cur, ans);
       return ans;
    }
    
    void helper(vector<int>& nums, int idx , vector<int>& cur , vector<vector<int>>& ans){
        if(idx == nums.size()){
            ans.push_back(cur);
            return;
        }
        cur.push_back(nums[idx]);
        helper(nums,idx+1,cur,ans);
        cur.pop_back();

        int newIdx = idx+1;
        while(idx < nums.size() && nums[newIdx] == nums[idx]) newIdx++;

        helper(nums,newIdx,cur,ans);
    }
};
