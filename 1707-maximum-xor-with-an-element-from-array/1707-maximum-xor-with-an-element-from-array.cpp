struct Node {
    Node* links[2];
    
    bool containsKey(int bit) {
        return (links[bit] != nullptr);
    }
    
    void put(int bit, Node* node) {
        links[bit] = node;
    }
    
    Node* get(int bit) {
        return links[bit];
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }
    
    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    
    int getMax(int num) {
        Node* node = root;
        int maxNum = 0;
        
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int oppositeBit = 1 - bit;
            
            if (node->containsKey(oppositeBit)) {
                maxNum = maxNum | (1 << i);
                node = node->get(oppositeBit);
            } else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

// the class Trie and structure for Node is copied from LC 421

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end()); // TC: O(N logN)

        vector<pair<int, pair<int, int>>> offlineQueries;
        int q = queries.size();

        for(int i = 0; i < q; i++){
            offlineQueries.push_back({queries[i][1], {queries[i][0], i}});
        }

        sort(offlineQueries.begin(), offlineQueries.end()); // TC: O(q logq)
        
        vector<int> ans(q, 0);

        int ind = 0;

        Trie trie;

        // basically we are inserting the elements which are less than mi as per the queries into the trie and then finding the answer.

        for(int i = 0; i < q; i++){
            int mi = offlineQueries[i].first;
            int xi = offlineQueries[i].second.first;
            int qInd = offlineQueries[i].second.second;

            while(ind < nums.size() && nums[ind] <= mi){
                trie.insert(nums[ind]);
                ind++;
            }

            if(ind == 0) ans[qInd] = -1;
            else ans[qInd] = trie.getMax(xi);
        } // TC: O(q) + O(N)

        return ans;
    }
};