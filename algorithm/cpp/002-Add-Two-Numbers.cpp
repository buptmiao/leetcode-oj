/*
Add Two Numbers

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/


 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *temp;
        int sum=0,mod=0;
        ListNode res = ListNode(0);
        temp = &res;
        while(l1 || l2){
        	if(l1){ 
        		sum+=l1->val;
        		l1=l1->next;
        	}
        	if(l2){ 
        		sum+=l2->val;
        		l2=l2->next;
        	}
        	sum+=mod;
        	mod = sum / 10;
        	temp->next = new ListNode(sum%10);
        	temp = temp->next;
        	sum = 0;
        }
        if(mod == 1)
        	temp->next = new ListNode(1);
        return res.next;
    }
};