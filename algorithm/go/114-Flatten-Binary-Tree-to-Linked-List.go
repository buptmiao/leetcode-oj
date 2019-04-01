/**
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
 */
func flatten(root *TreeNode) {
	for cursor := root; cursor != nil; cursor = cursor.Right {
		if cursor.Left != nil {
			right := cursor.Right
			left := cursor.Left
			cursor.Right = cursor.Left
			cursor.Left = nil
			for left.Right != nil {
				left = left.Right
			}
			left.Right = right
		}
	}
}
