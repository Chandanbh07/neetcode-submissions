class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> right(n,n);

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()) right[i] = n;
            else right[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        vector<int> left(n,-1);
        
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()) left[i] = -1;
            else left[i] = st.top();
            st.push(i);
        }

        int maxarea = 0;
        for(int i=0;i<n;i++){
            int area = heights[i] * (right[i] - left[i] - 1);
            maxarea = max(maxarea,area);
        }
        return maxarea;
    }
};
