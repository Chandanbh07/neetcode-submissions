class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int> mp;

       for(int N:nums){
        mp[N]++;
       }

       priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> minheap;

       for(auto& [n,count]:mp){
        minheap.push({count,n});
        if(minheap.size()>k){
          minheap.pop();
        }
       }

       vector<int> ans;

       while(minheap.size()){
        ans.push_back(minheap.top().second);
        minheap.pop();
       }

       return ans;
    }
};
