//http://www.lintcode.com/zh-cn/problem/remove-linked-list-elements/#
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
    /*
     * @param head: a ListNode
     * @param val: An integer
     * @return: a ListNode
     */
    ListNode * removeElements(ListNode * head, int val) {
        // write your code here
        if(head!=NULL){
            ListNode * head_temp=NULL;
            if(head->val==val){//如果当前节点要被去掉,那就返回它的next
                head_temp=removeElements(head->next,val);
                return head_temp;
                //return removeElements(head->next,val);
            }
            else if(head->val!=val){//如果当前节点要被保留,
                //那就先把它后面的也保留的节点作为next
                head->next=removeElements(head->next,val);
                //然后返回当前节点
                return head;
            }
        }
        else{
            return NULL;//节点为空就返回空
        }
    }
};