/*
https://leetcode.com/problems/largest-rectangle-in-histogram/
 */
import "container/list"

func largestRectangleArea(heights []int) int {
	heights = append(heights, 0)
	list := list.New()
	res := 0
	for i, v := range heights {
		for list.Len() != 0 && v < heights[list.Back().Value.(int)] {
			top := heights[list.Back().Value.(int)]
			list.Remove(list.Back())
			var width int
			if list.Len() != 0 {
				width = i - 1 - list.Back().Value.(int)
			}  else {
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
