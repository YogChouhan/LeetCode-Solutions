#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    long long sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        vector<int> prevSmaller(n), nextSmaller(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            prevSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            nextSmaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long totalMin = 0;
        for (int i = 0; i < n; i++) {
            long long leftCount = i - prevSmaller[i];
            long long rightCount = nextSmaller[i] - i;
            totalMin += leftCount * rightCount * nums[i];
        }

        return totalMin;
    }

    long long sumSubarrayMaxs(vector<int>& nums) {
        int n = nums.size();
        vector<int> prevGreater(n), nextGreater(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            prevGreater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            nextGreater[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long totalMax = 0;
        for (int i = 0; i < n; i++) {
            long long leftCount = i - prevGreater[i];
            long long rightCount = nextGreater[i] - i;
            totalMax += leftCount * rightCount * nums[i];
        }

        return totalMax;
    }

    long long subArrayRanges(vector<int>& nums) {
        return sumSubarrayMaxs(nums) - sumSubarrayMins(nums);
    }
};

// TC: O(10N) -> O(5N + 5N) for totalMins and totalMax
// SC: O(6N)