class Solution {
   public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int Maxarea = 0;

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || heights[i] < heights[st.top()])) {
                int h = heights[st.top()];
                st.pop();

                int left = st.empty() ? -1 : st.top();
                int width = i - left - 1;

                int area = width * h;

                Maxarea = max(Maxarea, area);
            }
            if (i < n) st.push(i);
        }
        return Maxarea;
    }
};
