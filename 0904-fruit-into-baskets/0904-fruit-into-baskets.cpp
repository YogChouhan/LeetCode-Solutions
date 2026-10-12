class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxFruitsPicked = 0, right = 0, left = 0;
        unordered_map<int, int> mpp;

        while(right < fruits.size()){
            mpp[fruits[right]]++;

            if(mpp.size() > 2){
                mpp[fruits[left]]--;
                if(mpp[fruits[left]] == 0) mpp.erase(fruits[left]);
                left++;
                // while(mpp.size() > 2){ // max O(N) time complexity added.
                //     mpp[fruits[left]]--;
                //     if(mpp[fruits[left]] == 0) mpp.erase(fruits[left]); // erase takes logN time but here N is 3 so it is considered as constant
                //     left++;
                // }
            }

            if(mpp.size() <= 2){
                maxFruitsPicked = max(maxFruitsPicked, right - left + 1);
            }

            right++;
        }

        return maxFruitsPicked;
    }
};

// TC: O(N)
// SC: O(3) as you store maximum 3 elements in the map.