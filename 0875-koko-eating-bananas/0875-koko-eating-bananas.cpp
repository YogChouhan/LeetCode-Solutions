class Solution {
private:
    long long timeTaken(int mid, vector<int>& piles) {
        long long time = 0;
        for (int i = 0; i < piles.size(); i++) {
            time += (piles[i] / mid) + (piles[i] % mid != 0);
        }
        return time;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = 0, low = 1;
        for (int i = 0; i < piles.size(); i++) {
            high = max(piles[i], high);
        }
        
        while (low <= high) {
            int mid = low + (high - low) / 2; 
            
            if (timeTaken(mid, piles) <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low; 
    }
};