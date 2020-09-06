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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        auto ans = vector<vector<int>>();
        if (!root)
        {
            return ans;
        }
        //定义队列q
        queue<TreeNode*> q;
        //存入根结点root
        q.push(root);

        //循环直至q pop空
        while (!q.empty()) 
        {
            auto level = vector<int>();
            //循环获取size
            int size = q.size();
            for (int i = 0; i < size; ++i) 
            {
                //定义node访问队首元素
                auto node = q.front();
                //弹出队列的第一个元素
                q.pop();
                //level存入,上述node所存数值
                level.push_back(node->val);

                //开始循环存入
                if (node->left) 
                {
                    //判断存在左子结点,存入
                    q.push(node->left);
                }
                if (node->right) 
                {
                    //判断存在右子结点,存入
                    q.push(node->right);
                }
            }
            ans.push_back(level);
        }

        reverse(ans.begin(), ans.end());
        return ans;     
    }
};
