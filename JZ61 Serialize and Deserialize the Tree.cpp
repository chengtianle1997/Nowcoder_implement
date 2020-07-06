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
    char* Serialize(TreeNode* root) {
        if (!root)
            return "#";
        char* res;
        string res_s = to_string(root->val);
        res_s.push_back(',');
        // Handle the left child
        char* sleft = Serialize(root->left);
        char* sright = Serialize(root->right);
        // Concat the string
        res = new char[strlen(sleft) + strlen(sright) + res_s.size()];
        strcpy(res, res_s.c_str());
        strcat(res, sleft);
        strcat(res, sright);
        return res;
    }
    TreeNode* Deserialize(char* str) {
        return Des_res(str);
    }
    // "char* &  " to ensure functions in different layers use the same str
    TreeNode* Des_res(char*& str) {
        if (!str)
            return NULL;
        if (*str == '#')
        {
            str++;
            return NULL;
        }
        int val = 0;
        while (*str != ',')
        {
            val = val * 10 + *str - '0';
            str++;
        }
        str++;
        TreeNode* newNode = new TreeNode(val);
        newNode->left = Des_res(str);
        newNode->right = Des_res(str);
        return newNode;
    }
};