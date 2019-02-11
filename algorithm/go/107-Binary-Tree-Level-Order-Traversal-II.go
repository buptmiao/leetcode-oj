/**
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
 */
func levelOrderBottom(root *TreeNode) [][]int {
	q := list.New()
	if root != nil {
		q.PushBack(root)
	}
	res := make([][]int, 0)

	for q.Len() > 0 {
		level := make([]int, q.Len())
		for i := 0; i < len(level); i++ {
			element := q.Front()
			node := element.Value.(*TreeNode)
			level[i] = node.Val
			q.Remove(element)

			if node.Left != nil {
				q.PushBack(node.Left)
			}
			if node.Right != nil {
				q.PushBack(node.Right)
			}
		}
		res = append(res, level)
	}
	for i := 0; i < len(res) / 2; i++ {
		res[i], res[len(res) - i - 1] = res[len(res) - i - 1], res[i]
	}
	return res
}
