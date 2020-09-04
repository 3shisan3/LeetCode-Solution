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
    vector<string> binaryTreePaths(TreeNode* root) {
        //定义最终返回路径
        vector<string> paths;

        if (root == nullptr) {
            return paths;
        }

        queue<TreeNode*> node_queue;
        queue<string> path_queue;

        node_queue.push(root);
        path_queue.push(to_string(root->val));

        //遍历直至指针指向为空(到叶子节点)
        while (!node_queue.empty()) {
            TreeNode* node = node_queue.front(); 
            string path = path_queue.front();
            node_queue.pop();
            path_queue.pop();

            if (node->left == nullptr && node->right == nullptr) {
                paths.push_back(path);
            } else {
                if (node->left != nullptr) {
                    node_queue.push(node->left);
                    path_queue.push(path + "->" + to_string(node->left->val));
                }

                if (node->right != nullptr) {
                    node_queue.push(node->right);
                    path_queue.push(path + "->" + to_string(node->right->val));
                }
            }
        }
        return paths;
    }
};
