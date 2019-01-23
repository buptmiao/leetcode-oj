/**
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
 */
func zigzagLevelOrder(root *TreeNode) [][]int {
	q := list.New()
	if root != nil {
		q.PushBack(root)
	}
	res := make([][]int, 0)

	for j := 0; q.Len() > 0 ; j++ {
		level := make([]int, q.Len())

		for i := 0; i < len(level); i++ {
			element := q.Front()
			node := element.Value.(*TreeNode)
			index := i
			if j % 2 == 1 {
				index = len(level) - 1 - i
			}
			level[index] = node.Val
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
	return res
}
