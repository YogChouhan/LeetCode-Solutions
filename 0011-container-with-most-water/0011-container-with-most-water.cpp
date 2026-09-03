class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), left = 0, right = n-1, ans = 0, area = 0;
        while(left < right){
            int h_left = height[left], h_right = height[right];
            area = min(h_left, h_right)*(right - left);
            ans = max(ans , area);
            if (h_left > h_right){
                while(left < right && h_right >= height[right]){
                    right--;
                }
            }
            else{
                while(left < right && h_left >= height[left]){
                    left++;
                }
            }
            // height[left]>=height[right] ? right-- : left++;
        }
        return ans;
    }
};