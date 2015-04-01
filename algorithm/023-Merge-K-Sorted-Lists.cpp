/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

*/
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
		ListNode ret(0);
		ListNode *temp = &ret;
		priority_queue<ListNode * ,vector<ListNode *>,CompNode> pq;
		for(size_t i = 0;i<lists.size();i++)
		{
			if(lists[i] != NULL)
				pq.push(lists[i]);
		}
		while(!pq.empty())
		{
			temp->next = pq.top();
			pq.pop();
			if(temp->next->next)
				pq.push(temp->next->next);
			temp = temp->next;
		}
		return ret.next;
    }
	struct CompNode{
		bool operator() (ListNode *l1,ListNode *l2){
			return l1->val > l2->val;
		}
	};
};