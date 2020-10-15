/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr)
        {
            return root;
        }
        queue<Node*> Q;
        Q.emplace(root);
        while(!Q.empty())
        {
            int size = Q.size();
            for(int i = 0; i < size; i++)
            {
                Node* node = Q.front();
                Q.pop();

                if(i < size - 1)
                {
                    node->next = Q.front();
                }            
                if(node->left != nullptr)
                {
                    Q.emplace(node->left);
                }
                if(node->right != nullptr)
                {
                    Q.emplace(node->right);
                }
            }
        }
        return root;
    }
};
