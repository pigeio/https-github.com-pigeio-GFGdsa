/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    int findMax(Node *root) {
        // code here
        if(root == NULL)return INT_MIN;
        
        int res = root->data;
        int left = findMax(root->left);
        int right = findMax(root->right);
        
        res = max(res ,left);
        res = max(res ,right);
        
        return res;
    }

    int findMin(Node *root) {
        if(root == NULL)return INT_MAX;
        
        int res = root->data;
        int left = findMin(root->left);
        int right = findMin(root->right);
        
        res = min(res , left);
        res = min(res , right);
        
        return res;
        // code here
    }
};