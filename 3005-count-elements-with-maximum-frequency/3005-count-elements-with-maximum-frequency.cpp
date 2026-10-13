class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int hashArray[101] = {0};
        int maxFreq = 0;
        int totalSum = 0;

        for(int num : nums) {
            hashArray[num]++;
            
            if(hashArray[num] > maxFreq) {
                maxFreq = hashArray[num];
                totalSum = hashArray[num];
            } 
            else if(hashArray[num] == maxFreq) {
                totalSum += hashArray[num];
            }
        }

        return totalSum;
    }
};