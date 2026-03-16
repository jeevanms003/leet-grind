class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();
        vector<int> ans(n,0);
        stack<int> st;  // store indices

        for(int i = 0; i < n; i++)
        {
            while(!st.empty() && temperatures[i] > temperatures[st.top()])
            {
                int index = st.top();
                st.pop();

                ans[index] = i - index;
            }

            st.push(i);
        }

        return ans;
    }
};