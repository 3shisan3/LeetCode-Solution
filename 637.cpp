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
	vector <double> averageOfLevels(TreeNode* root) {
		vector<double> ans;
		auto q = queue<TreeNode*>();
		q.push(root);
		while (!q.empty())
		{
			double sum = 0;
			int num = q.size();
			for (int i = 0; i < num; i++)
			{
				auto node = q.front();
				q.pop();
				sum = node.val + sum;
				auto left = node->left;
				auto right = node->right;
				if (left != nullptr)
				{
					q.push(left);
				}
				if (right != nullptr)
				{
					q.push(right);
				}
			}
			ans.push_back(sum / num);
		}
		return ans;
	}
};
