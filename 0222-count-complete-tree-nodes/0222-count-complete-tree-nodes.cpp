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
private:
    int findLeftHeight(TreeNode *root){
        int height = 1;
        while(root->left != nullptr){
            height++;
            root = root->left;
        }
        return height;
    }
    int findRightHeight(TreeNode *root){
        int height = 1;
        while(root->right != nullptr){
            height++;
            root = root->right;
        }
        return height;
    }
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;

        int left_height = findLeftHeight(root);
        int right_height = findRightHeight(root);

        if(left_height == right_height) return (1<<left_height)-1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};