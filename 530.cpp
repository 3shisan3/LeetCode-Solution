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
    int getMinimumDifference(TreeNode* root) {
        vector<int> treeval;
        stack<TreeNode*> tree;
        tree.emplace(root); 
        while(!tree.empty())
        {
            TreeNode* node = tree.top();
            treeval.emplace_back(node->val);
            tree.pop();
            if(node->left != nullptr)
            {
                tree.emplace(node->left);
            }
            if(node->right != nullptr)
            {
                tree.emplace(node->right);
            }
        }
        sort(treeval.begin(),treeval.end());
        int min = treeval[1] - treeval[0];
        for(int i = 1; i < treeval.size()-1; i++)
        {
            if(min > treeval[i+1]- treeval[i])
            {
                min = treeval[i+1] - treeval[i];
            }
        }
        return min;
    }
};
