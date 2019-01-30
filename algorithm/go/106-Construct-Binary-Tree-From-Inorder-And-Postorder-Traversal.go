/**
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
 */
func buildTree(inorder []int, postorder []int) *TreeNode {
	if len(postorder) == 0 {
		return nil
	}
	root := &TreeNode{postorder[len(postorder) - 1], nil, nil}
	stack := list.New()
	stack.PushBack(root)
	for p, i := len(postorder) - 2, len(inorder) - 1; p >= 0; {
		top := stack.Back().Value.(*TreeNode)
		if top.Val != inorder[i] {
			top.Right = &TreeNode{postorder[p], nil, nil}
			p--
			stack.PushBack(top.Right)
		} else {

			stack.Remove(stack.Back())
			i--
			if stack.Len() > 0 && stack.Back().Value.(*TreeNode).Val == inorder[i] {
				continue
			}
			top.Left = &TreeNode{postorder[p], nil, nil}
			p--
			stack.PushBack(top.Left)
		}
	}
	return root
}
