/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head,int k) {
		ListNode ret(0);
		ListNode *temp = &ret,*index;
		temp->next = head;
        while(1)
		{
			int m = k;
			if((index = FindKthNode(temp,k)) == NULL)
				return ret.next;
			ListNode *l1 = index->next;
			ListNode *l2 = index;
			while(--m)  //reverse the main part
			{
				index->next = FindKthNode(temp,m);
				index = index->next;
			}
			index->next = l1;
			temp->next = l2;
			temp = index;
		}
		return ret.next;
    }
	ListNode * FindKthNode(ListNode *head,int k) //return the Kth Node from head,or NULL if  less nodes than k
	{
		while(k--)
		{
			if(head->next == NULL)
				return NULL;
			head = head->next;
		}
		return head;
	}
};