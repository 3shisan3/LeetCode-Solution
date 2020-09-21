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
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL)
        {
            return root;
        }
        vector<int> value;
        stack<TreeNode*> node;
        node.push(root);
        while(!node.empty())
        {
            TreeNode* temp = node.top();
            value.emplace_back(temp->val);
            node.pop();
            if(temp->left)
            {
                node.push(temp->left);
            }
            if(temp->right)
            {
                node.push(temp->right);
            }
        }

        changeval(root,value);
        return root;
    }

    void changeval(TreeNode* point,vector<int> value)
    {
        int tmp = 0;
        for(int i = 0; i < value.size(); i++)
        {
            point->val <= value[i] ? tmp += value[i] : tmp += 0;
        }
        point->val = tmp;
        if(point->left)
        {
            changeval(point->left,value);
        }
        if(point->right)
        {
            changeval(point->right,value);
        }
        if((point->left == NULL && point->right == NULL) || point == NULL)
        {
            return;
        }
    }
};
