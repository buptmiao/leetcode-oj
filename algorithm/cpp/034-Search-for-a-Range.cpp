/*

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

*/

class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		int left = 0;
		int cnt = n;
		int i = 0;
		vector<int> res(2);
		res[0] = res[1] = -1;
		while(cnt > 0){ 
			int step = cnt/2;
			i = left + step;
			if(A[i] < target){ 
				left = ++i;
				cnt -= step+1;
			}
			else
				cnt = step;
		}
		if(A[left] != target) return res;
		res[0] = left++;
		cnt = n-left;
		while(cnt > 0){ 
			int step = cnt/2;
			i = left + step;
			if(!(target < A[i]))
			{ left = ++i;cnt-=step+1;}
			else
				cnt = step;
		}
		res[1] = left-1;
		return res;
	}
};