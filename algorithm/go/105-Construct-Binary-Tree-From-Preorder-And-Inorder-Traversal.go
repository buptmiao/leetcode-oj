/**
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,6,20,15,7]
inorder = [9,6,3,15,20,7]
Return the following binary tree:

    3
   /  \
  9    20
   \   /  \
    6 15   7
*/

func buildTree(preorder []int, inorder []int) *TreeNode {
	if len(preorder) == 0 {
		return nil
	}
	root := &TreeNode{preorder[0], nil, nil}
	stack := list.New()
	stack.PushBack(root)
	for p, i := 1, 0; p < len(preorder); {
		top := stack.Back().Value.(*TreeNode)
		if top.Val != inorder[i] {
			top.Left = &TreeNode{preorder[p], nil, nil}
			p++
			stack.PushBack(top.Left)
		} else {
			stack.Remove(stack.Back())
			i++
			if stack.Len() > 0 && stack.Back().Value.(*TreeNode).Val == inorder[i] {
				continue
			}
			top.Right = &TreeNode{preorder[p], nil, nil}
			p++
			stack.PushBack(top.Right)
		}
	}
	return root
}
