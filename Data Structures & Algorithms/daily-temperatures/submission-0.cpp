class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);  // Initialize result with zeros
        stack<int> st;          // Monotonic stack (stores indices)

        for (int i = n - 1; i >= 0; i--) {
            // Pop all indices with temperatures <= current day's temperature
            while (!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }

            // If stack isn't empty, calculate distance to next warmer day
            if (!st.empty()) {
                res[i] = st.top() - i;
            }

            // Push current day index
            st.push(i);
        }

        return res;
    }
};
