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
    int cnt = 0;
    queue<TreeNode *> q;
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        preOrder(root);
        
        TreeNode* curr = q.front();
        q.pop();

        while (!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            curr->right = temp;
            curr->left = nullptr;
            curr = temp;
        }
    }
    void preOrder(TreeNode* root){
        //root, left, right
        if(root == nullptr) return;
        cnt++;
        q.push(root);
        preOrder(root->left);
        preOrder(root->right);
    }
};