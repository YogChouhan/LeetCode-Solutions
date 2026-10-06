class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        stack<int> st;
        vector<int> answer(n);
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && st.top() > prices[i]){
                st.pop();
            }
            answer[i] = st.empty() ? prices[i] : prices[i]-st.top();
            st.push(prices[i]);
        }
        return answer;
    }
};

// TC: O(2N)
// SC: O(2N) for stack and returning answer array