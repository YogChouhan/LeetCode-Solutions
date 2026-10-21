// class Solution {
// public:
//     vector<int> frequencySort(vector<int>& nums) {
//         unordered_map<int, int> freq;
//         for(int num : nums){
//             freq[num]++;
//         }

//         sort(nums.begin(), nums.end(), [&](int a, int b){
//             if(freq[a] != freq[b]) return freq[a] < freq[b];
//             return a > b;
//         });
//         // returning true means "a should come before b". Returning false means "b should come before a"

//         return nums;
//     }
// };


class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        int freq[201] = {0};

        for(int num : nums){
            freq[num + 100]++;
        }

        vector<vector<int>> bucket(n + 1); // nth elements can have max n+1 freq

        for(int i = 200; i >= 0; i--){
            if(freq[i] > 0){
                int actualNum = i - 100;
                bucket[freq[i]].push_back(actualNum);
            }
        }

        vector<int> answer;

        for(int i = 1; i < n+1; i++){
            for(int num : bucket[i]){
                for(int k = 0; k < i; k++) answer.push_back(num);
            }
        }

        return answer;
    }
};
