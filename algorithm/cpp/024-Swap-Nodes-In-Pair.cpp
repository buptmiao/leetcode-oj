/*

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. 
You may not modify the values in the list, only nodes itself can be changed.

*/

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
		ListNode ret(0);
		ListNode *temp = &ret;
		temp->next = head;
        while(temp->next != NULL && temp->next->next != NULL)
		{
			ListNode *l1 = temp->next->next->next;
			ListNode *l2 = temp->next;
			temp->next = temp->next->next;
			temp->next->next = l2;
			temp->next->next->next = l1;
			
			temp = l2;
		}
		return ret.next;
    }
};