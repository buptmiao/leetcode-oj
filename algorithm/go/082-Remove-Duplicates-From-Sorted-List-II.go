/**
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3

 */
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
	root := &ListNode{0, head}
	start := root
	for head != nil && head.Next != nil {
		if head.Next.Val == head.Val {
			for head.Next != nil && head.Next.Val == head.Val {
				head = head.Next
			}
			start.Next = head.Next
		} else {
			start.Next = head
			start = head
		}
		head = head.Next
	}
	return root.Next
}