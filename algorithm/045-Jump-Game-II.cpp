/*

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

*/

class Solution {
public:
	//greedy
    int jump(int A[], int n) {
		int res = 1;
		if(n <= 1) return 0;
        for(int i = 1,range=A[0];range<n-1;res++)
			for(int lastmax = range;i <=lastmax;i++)
				range = max(range,A[i]+i);
		return res;
    }
};