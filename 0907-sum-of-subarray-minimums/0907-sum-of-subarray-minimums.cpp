class Solution {
private:
    vector<int> findNSE(vector<int>& arr, int& n){
        vector<int> NSE(n,0);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            NSE[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return NSE;
    }

    // TC: O(2N), SC: O(2N)

    vector<int> findPSEE(vector<int>& arr, int n){
        vector<int> PSEE(n,0);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            PSEE[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return PSEE;
    }

    // TC: O(2N), SC: O(2N)

public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size(), total = 0, mod = (int)(1e9 + 7);
        vector<int> NSE = findNSE(arr, n);
        vector<int> PSEE = findPSEE(arr, n);
        for(int i = 0; i < n; i++){
            int left = i - PSEE[i];
            int right = NSE[i] - i;
            total = (total + (right * left * (long long)(1) * arr[i]) % mod) % mod;
        }
        return total;
    }
    // TC: O(N), SC: O(2N)
};