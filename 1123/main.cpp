#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    TreeNode *lcaDeepestLeaves(TreeNode *root)
    {
        if (!root)
            return nullptr;

        int depth = 0;
        return findLCA(root, depth);
    }

    TreeNode *findLCA(TreeNode *node, int &depth)
    {
        if (!node)
        {
            depth = 0;
            return nullptr;
        }

        int leftDepth = 0, rightDepth = 0;
        TreeNode *leftLCA = findLCA(node->left, leftDepth);
        TreeNode *rightLCA = findLCA(node->right, rightDepth);

        depth = 1 + max(leftDepth, rightDepth);

        if (leftDepth == rightDepth)
        {
            return node;
        }
        else if (leftDepth > rightDepth)
        {
            return leftLCA;
        }
        else
        {
            return rightLCA;
        }
    }
};

TreeNode *buildTree(const vector<string> &nodes)
{
    if (nodes.empty() || nodes[0] == "null")
        return nullptr;

    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(stoi(nodes[0]));
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size())
    {
        TreeNode *curr = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != "null")
        {
            curr->left = new TreeNode(stoi(nodes[i]));
            q.push(curr->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null")
        {
            curr->right = new TreeNode(stoi(nodes[i]));
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

vector<string> parseInput(const string &input)
{
    vector<string> nodes;
    stringstream ss(input);
    string token;

    // 去除首尾的方括号
    string trimmed = input.substr(1, input.size() - 2);
    stringstream ss_trimmed(trimmed);

    while (getline(ss_trimmed, token, ','))
    {
        // 去除前后空格
        size_t start = token.find_first_not_of(" ");
        size_t end = token.find_last_not_of(" ");
        if (start != string::npos && end != string::npos)
        {
            token = token.substr(start, end - start + 1);
        }
        nodes.push_back(token);
    }

    return nodes;
}

void printTree(TreeNode *root)
{
    if (!root)
    {
        cout << "null";
        return;
    }

    queue<TreeNode *> q;
    q.push(root);
    cout << "[" << root->val;

    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();

        if (curr->left)
        {
            cout << "," << curr->left->val;
            q.push(curr->left);
        }
        else
        {
            cout << ",null";
        }

        if (curr->right)
        {
            cout << "," << curr->right->val;
            q.push(curr->right);
        }
        else
        {
            cout << ",null";
        }
    }
    cout << "]";
}

int main()
{
    Solution solution;
    string input;

    cout << "请输入二叉树（格式如[3,5,1,6,2,0,8,null,null,7,4]）：" << endl;
    getline(cin, input);

    vector<string> nodes = parseInput(input);
    TreeNode *root = buildTree(nodes);

    TreeNode *result = solution.lcaDeepestLeaves(root);

    cout << "最深叶节点的最近公共祖先节点值为: ";
    if (result)
    {
        cout << result->val << endl;
    }
    else
    {
        cout << "null" << endl;
    }

    return 0;
}