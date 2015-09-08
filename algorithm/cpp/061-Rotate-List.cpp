/*

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.

*/


struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        int size = 1;
		ListNode *l1,*l2,*l3;
		l3 = head;
		if(head == NULL) return head;
		while(l3->next!= NULL){
			size++;
			l3 = l3->next;
		}
		k %= size;
		if(k == 0) return head;
		ListNode temp(0);
		l1 = &temp;
		l1->next = head;
		for(int m = size-k;m > 0;m--)
			l1 = l1->next;
		l2 = l1->next;
		l3->next = head;
		l1->next = NULL;
		return l2;
    }
};