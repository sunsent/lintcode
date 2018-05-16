http://www.lintcode.com/zh-cn/problem/maximum-depth-of-binary-tree/#
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: An integer
     */
    int maxDepth(TreeNode * root) {
        // write your code here
        if(root==NULL){
            return 0;//空节点返回0,非空节点返回子节点和自己 的和
        }
        int left=maxDepth(root->left);
        int max=left;
        int right=maxDepth(root->right);
        if(right>left){
            max=right;
        }
        max++;
        return max;
    }
};