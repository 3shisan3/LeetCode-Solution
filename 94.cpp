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
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode *p = root;
        vector<int> ans;
        if(!p)
        {
            return ans;
        }
        stack<TreeNode*> q;
        while(p || !q.empty())
        {
            if(p)
            {
                q.push(p);
                p = p->left;
            }
            else
            {
                p = q.top();
                ans.push_back(p->val);
                q.pop();
                p = p->right;
            }
        }
        return ans;
    }
};
