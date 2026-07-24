class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int st = 0 , end = n-1;
        int maxi = 0;
        while(st<end){
          int cur = min(heights[st],heights[end]) * (end-st);
          maxi = max(maxi,cur);

          if(heights[st] < heights[end]) st++;
          else end--;
        }
        return maxi;
    }
};
