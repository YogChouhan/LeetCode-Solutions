class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> mpp;
        vector<int> ans;
        int len1 = nums1.size(), len2 = nums2.size();
        for(int i = len2-1; i >= 0; i--){
            while(!st.empty() && nums2[i] >= st.top()){
                st.pop();
            }
            if(st.empty()) mpp[nums2[i]] = -1;
            else mpp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        
        for(int j = 0; j < len1; j++){
            ans.push_back(mpp[nums1[j]]);
        }

        return ans;
    }
};

// TC: O(2N + N) for finding the NGE and to return the answers according to the nums1
// SC: O(N + N) for stack and to store answer