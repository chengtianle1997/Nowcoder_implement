/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    int counter = 0;

    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        TreeNode* KNode;
        if (pRoot == NULL || k < 1)
            return NULL;
        if (pRoot->left)
        {
            KNode = KthNode(pRoot->left, k);
            if (KNode)
                return KNode;
        }
        counter++;
        if (counter == k)
            return pRoot;
        if (pRoot->right)
        {
            KNode = KthNode(pRoot->right, k);
            if (KNode)
                return KNode;
        }
        return NULL;
    }
};