class Solution {
public:
    int hammingWeight(int n) {
        int cnt = 0;
        while(n != 0){
            n = n & (n-1); // removes the left most set bit and sets it to 0
            cnt++;
        }
        return cnt;
    }
};

// Brian Kernighan's Algorithm