/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> temp;
        if(root == nullptr)
        {
            return ans;
        }
        caculate(ans, root, sum, 0, temp);
        return ans;
    }

    void caculate(vector<vector<int>> &ans, TreeNode* node, int sum, int tempsum, vector<int> temp)
    {
        tempsum += node->val;
        temp.emplace_back(node->val);
        if(tempsum == sum && node->left == nullptr && node->right == nullptr)
        {
            ans.emplace_back(temp);
            return;
        }
        if(node->left != nullptr)
        {
            caculate(ans, node->left, sum, tempsum, temp);
        }
        if(node->right != nullptr)
        {
            caculate(ans, node->right, sum, tempsum, temp);
        }
    }
};
