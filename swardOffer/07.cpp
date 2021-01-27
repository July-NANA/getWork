#include <bits/stdc++.h>
using namespace std;

/*
前序遍历：根，左，右
根后为子节点，每一节点的后一个节点为左子节点
中序遍历：左，根，右
根前为左子节点，根后为右子节点
*/

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        this->preorder = preorder;
        // vector<int> leftPre, leftIn, rightPre, rightIn;
        for (int i = 0; i < inorder.size(); i++)
        {
            dic[inorder[i]] = i;
        }
        TreeNode *tree = recur(0, 0, inorder.size() - 1);
        return tree;
    }
    //第一步建立根节点
    //第二版划分左右子树

    //第三步构建左右子树
private:
    vector<int> preorder;
    unordered_map<char, int> dic;

    //root:根节点在前序遍历的索引
    //left：子树在中序遍历的左边界
    //right：子树在中序遍历的右边界

    TreeNode *recur(int root, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }

        //1、建立根节点
        TreeNode *node = new TreeNode(preorder[root]);

        int i = dic[preorder[root]]; //根节点在中序遍历中的索引

        node->left = recur(root + 1, left, i - 1);
        node->right = recur(root + i - left + 1, i + 1, right); //右子树根节点索引为父节点+左子树长度+1
        return node;
    }
};