/**
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
 */
func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}
	return isSymmetricBoth(root.Left, root.Right)
}

func isSymmetricBoth(left, right *TreeNode) bool {
	if left == nil || right == nil {
		return left == right
	}

	return left.Val == right.Val && isSymmetricBoth(left.Left, right.Right) && isSymmetricBoth(left.Right, right.Left)
}

// solution 2
func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}
	left, right := list.New(), list.New()

	left.PushBack(root.Left)
	right.PushBack(root.Right)

	for left.Len() > 0 && right.Len() > 0 {
		p, q := left.Front(), right.Front()
		left.Remove(p)
		right.Remove(q)

		pnode, qnode := p.Value.(*TreeNode), q.Value.(*TreeNode)

		if pnode == nil && qnode == nil {
			continue
		}

		if pnode == nil || qnode == nil || pnode.Val != qnode.Val {
			return false
		}

		left.PushBack(pnode.Left)
		left.PushBack(pnode.Right)
		right.PushBack(qnode.Right)
		right.PushBack(qnode.Left)
	}
	return true
}
