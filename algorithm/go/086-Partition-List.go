/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
 */
func partition(head *ListNode, x int) *ListNode {
	cursor := &ListNode{0, head}
	last := cursor
	root := last
	for cursor != nil && cursor.Next != nil {
		if cursor.Next.Val < x {
			temp := cursor.Next
			cursor.Next = cursor.Next.Next
			temp.Next = last.Next
			last.Next = temp
			last = temp
			if cursor.Val >= x {
				continue
			}
		}
		cursor = cursor.Next
	}
	return root.Next
}
