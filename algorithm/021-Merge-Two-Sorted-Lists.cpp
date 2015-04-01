/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
*/

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode ret(0);
        ListNode *temp = &ret;
		if(l1 == NULL) return l2;
		if(l2 == NULL) return l1;
		while(l1 || l2)
		{
			if(l1->val < l2->val){
				temp->next = l1;
				if(l1->next)
					l1 = l1->next;
				else{
					temp->next->next = l2;
					break;
				}
				temp = temp->next;
			}else if(l1->val >= l2->val){
				temp->next = l2;
				if(l2->next)
					l2 = l2->next;
				else{
					temp->next->next = l1;
					break;
				}
				temp = temp->next;
			}
		}
		return ret.next;
    }
};