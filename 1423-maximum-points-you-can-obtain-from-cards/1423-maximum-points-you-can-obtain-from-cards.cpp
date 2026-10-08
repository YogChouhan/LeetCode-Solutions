class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftSum = 0, rightSum = 0, maxCardPoints = 0;
        int n = cardPoints.size();

        // adding elements from right initially
        for(int i = 0; i < k; i++) leftSum += cardPoints[i];
        maxCardPoints = leftSum;

        int rightIndex = n - 1;

        // removing elements from left and adding from right
        for(int i = k - 1; i >= 0; i--){
            rightSum += cardPoints[rightIndex--];
            leftSum -= cardPoints[i];
            if(maxCardPoints < (rightSum + leftSum)) maxCardPoints = leftSum + rightSum;
        }

        return maxCardPoints;
    }
};

// TC: O(2k)
// SC: O(1)