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
    int count = 0;

    void dfs(TreeNode* node, int path) {
        if (node == nullptr) {
            return;
        }

        path ^= (1 << node->val);

        if (node->left == nullptr && node->right == nullptr) {
            if ((path & (path - 1)) == 0) {
                count++;
            }
            return;
        }

        dfs(node->left, path);
        dfs(node->right, path);
    }

    int pseudoPalindromicPaths(TreeNode* root) {
        dfs(root, 0);
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna