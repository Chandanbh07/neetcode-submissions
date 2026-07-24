class Solution {
public:
    int maxArea(vector<int>& heights) {
       int n = heights.size();
       int st = 0;
       int end = n-1;

        int maxwater=0;
       while(st<end){
        int width = end-st;
        int h = min(heights[st],heights[end]);

        int water = width * h;
        maxwater = max(maxwater,water);

        if(heights[st] < heights[end]) st++;
        else end--;
       }
       return maxwater;
    }
};
