/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/


 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *list = NULL;
        if(FindNthFromEnd(head,n,list) == n)
        	return head->next;
        List->next = List->next->next;
        return head;
    }
    int FindNthFromEnd(ListNode *head,int n,ListNode *&list){ 
    	if(head->next == NULL)
    		return 1;
    	int m = 1 + FindNthFromEnd(head->next,n,list);
    	if(m == n+1) 
    		list = head;
    	return m;
    }
};