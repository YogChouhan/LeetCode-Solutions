class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1, leftMax = 0, rightMax = 0, waterTrapped = 0;
        while(left < right){
            if(height[left] <= height[right]){
                if(height[left] < leftMax){
                    waterTrapped += leftMax - height[left];
                }
                else leftMax = height[left];
                left++;
            }
            else{
                if(height[right] < rightMax){
                    waterTrapped += rightMax - height[right];
                }
                else rightMax = height[right];
                right--;
            }
        }
        return waterTrapped;
    }
};