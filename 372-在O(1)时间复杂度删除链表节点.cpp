http://www.lintcode.com/zh-cn/problem/delete-node-in-the-middle-of-singly-linked-list/
/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */


class Solution {
public:
    /*
     * @param node: the node in the list should be deletedt
     * @return: nothing
     */
    void deleteNode(ListNode * node) {
        // write your code here
        if(node!=NULL&&node->next!=NULL){
			ListNode* temp=node->next;
            node->val=node->next->val;
            node->next=node->next->next;
			delete temp;
        }
		else if(node!=NULL&&node->next==NULL){
			delete node;
			node=NULL;
		}
    }
};