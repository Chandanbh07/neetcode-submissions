class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> left;
        stack<int> right;
        int n = heights.size();
        vector<int> l(n,-1);
        vector<int> r(n,n);

        int i = 0;
        while(i<n){
            while(!left.empty() && heights[left.top()] >= heights[i]){
                left.pop();
            }
            if(!left.empty()) l[i] = left.top();

            left.push(i);
            i++;
        }

        i = n-1;
        while(i>=0){
            while(!right.empty() && heights[right.top()] >= heights[i]){
                right.pop();
            }
            if(!right.empty()) r[i] = right.top();

            right.push(i);
            i--;
        }

        i = 0;
        int area = 0;
        while(i < n){
            int curr = (r[i] - l[i] - 1) * heights[i];

            area = max(area , curr);
            i++;
        }

        return area;
    }
};
