class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> ans(n);

        for(int i = (2*n)-1; i >= 0; i--){
            int index = i % n;
            while(!st.empty() && nums[index] >= st.top()){
                st.pop();
            }
            if(i < n) ans[i] = st.empty() ? -1 : st.top();
            st.push(nums[index]);
        }
        
        return ans;
    }
};

// TC: O(4N) -> we assume the double of array [1,2,3] as [1,2,3,1,2,3]
// SC: O(2N) -> stack + answer array