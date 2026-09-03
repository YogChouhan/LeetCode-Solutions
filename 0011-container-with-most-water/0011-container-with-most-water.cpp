class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), left = 0, right = n-1, ans = 0;
        while(left < right){
            int area = min(height[left],height[right])*(right - left);
            ans = max(ans, area);
            height[left]>=height[right] ? right-- : left++;
        }
        return ans;
    }
};