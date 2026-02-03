class Solution {
public:
    unordered_map<int,int> pos;
    int idx;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int l, int r) {
        if (l > r) return nullptr;
        int val = postorder[idx--];
        TreeNode* root = new TreeNode(val);
        int m = pos[val];
        root->right = build(inorder, postorder, m + 1, r);
        root->left = build(inorder, postorder, l, m - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
            pos[inorder[i]] = i;
        idx = postorder.size() - 1;
        return build(inorder, postorder, 0, inorder.size() - 1);
    }
};
