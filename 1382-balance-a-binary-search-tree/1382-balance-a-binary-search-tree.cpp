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
    vector<int> inOrderArray;

    // left root right
    void inOrderTraversal(TreeNode* root){
        if(root == nullptr) return;
        inOrderTraversal(root->left);
        inOrderArray.push_back(root->val);
        inOrderTraversal(root->right);
    }

    TreeNode* createBST(int left, int right){
        if(left > right) return nullptr;
        int mid = left + ((right - left)>>1);
        TreeNode* node = new TreeNode(inOrderArray[mid]);
        node->left = createBST(left, mid - 1);
        node->right = createBST(mid + 1, right);
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        inOrderTraversal(root);
        return createBST(0, inOrderArray.size() - 1);
    }
};

// get the inorder traversal array
// make the bst from that
// TC: O(N), SC: O(N)