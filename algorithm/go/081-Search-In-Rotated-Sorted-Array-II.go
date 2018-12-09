/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).

You are given a target value to search. If found in the array return true, otherwise return false.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
Follow up:

This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
Would this affect the run-time complexity? How and why?
 */

func search(nums []int, target int) bool {
	if len(nums) == 0 {
		return false
	}
	return findTwo(nums, target, 0, len(nums) - 1)
}

func findTwo(nums []int, target, left, right int) bool {
	mid := left + (right - left) / 2

	if right - left < 2 {
		return nums[left] == target || nums[right] == target
	}

	if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
		return findTwo(nums, target, left, mid) || findTwo(nums, target, mid + 1, right)
	}

	if (nums[left] <= target && target <= nums[mid]) || (nums[left] > nums[mid] && (target <= nums[mid] || target >= nums[left])) {
		return findTwo(nums, target, left, mid)
	}
	return findTwo(nums, target, mid + 1, right)
}