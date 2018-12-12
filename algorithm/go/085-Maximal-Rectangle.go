
/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example:

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6
 */

func maximalRectangle(matrix [][]byte) int {
	if len(matrix) == 0 {
		return 0
	}
	res := largestRectangleArea(matrix[0])
	for i := 1; i < len(matrix); i++ {
		for j := 0; j < len(matrix[0]); j++ {
			if matrix[i][j] == 1 + 48 {
				matrix[i][j] = matrix[i - 1][j] + 1
			}
		}
		temp := largestRectangleArea(matrix[i])
		if temp > res {
			res = temp
		}
	}
	fmt.Println(matrix)
	return res
}

func largestRectangleArea(heights []byte) int {
	heights = append(heights, 0)
	list := list.New()
	res := 0
	for i, v := range heights {
		for list.Len() != 0 && v < heights[list.Back().Value.(int)] {
			top := int(heights[list.Back().Value.(int)]) - 48
			list.Remove(list.Back())
			var width int
			if list.Len() != 0 {
				width = i - 1 - list.Back().Value.(int)
			} else {
				width = i
			}
			if res < top * width {
				res = top * width
			}
		}
		list.PushBack(i)
	}
	return res
}
