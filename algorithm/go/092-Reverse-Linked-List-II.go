/**
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
 */
func reverseBetween(head *ListNode, m int, n int) *ListNode {
	res := &ListNode{0, head}
	var start, end *ListNode
	for i, cursor := 0, res; cursor.Next != nil; cursor = cursor.Next {
		i++
		if i == m {
			start = cursor
		}
		if i == n {
			end = cursor.Next
		}
	}

	for i := n - m; i > 0; i-- {
		move := start.Next
		start.Next = move.Next
		move.Next = end.Next
		end.Next = move
	}
	return res.Next
}
