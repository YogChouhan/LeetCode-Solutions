/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int cnt = 0, kthSmallestElement = 0;
    void inOrderTraversal(TreeNode *root, int k){
        if(root == nullptr) return;
        inOrderTraversal(root->left, k);
        cnt++;
        if(cnt==k){
            kthSmallestElement = root->val;
        }
        inOrderTraversal(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inOrderTraversal(root, k);
        return kthSmallestElement;
    }
};

// TC: O(N), SC: O(N) because of recursive approach.

// class Solution {
// public:
//     vector<int> sortedArray;
//     void inOrderTraversal(TreeNode *root){
//         if(root == nullptr) return;
//         inOrderTraversal(root->left);
//         sortedArray.push_back(root->val);
//         inOrderTraversal(root->right);
//     }
//     int kthSmallest(TreeNode* root, int k) {
//         inOrderTraversal(root);
//         return sortedArray[k-1];
//     }
// };

// TC: O(N), SC: O(2N) because of recursive approach and the sorted element