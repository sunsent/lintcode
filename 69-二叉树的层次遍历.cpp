//http://www.lintcode.com/zh-cn/problem/binary-tree-level-order-traversal/#
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
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        // write your code here
        vector<vector<int>> result;
        if(root==NULL){
            return result;
        }
        queue<TreeNode *>nextNode;
        nextNode.push(root);//存入当前层
        while(!nextNode.empty()){
            vector<int> currentLevel;//当前一整层
            int size=nextNode.size();
            TreeNode *temp;
            for(int i=0;i<size;i++){
                temp=nextNode.front();//不断取当前层
                currentLevel.push_back(temp->val);//存入当前一层当前节点的值
                if(temp->left!=NULL){
                    nextNode.push(temp->left);//存入下一层
                }
                if(temp->right!=NULL){
                    nextNode.push(temp->right);//存入下一层
                }
                nextNode.pop();//不断把当前一层当前节点pop
            }
            result.push_back(currentLevel);//存入当前一层的值
        }
        return result;
    }
};