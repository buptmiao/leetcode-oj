/**
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
 */

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
	start := head
	for start != nil && start.Next != nil {
		if start.Val == start.Next.Val {
			start.Next = start.Next.Next
		} else {
			start = start.Next
		}
	}
	return head
}
