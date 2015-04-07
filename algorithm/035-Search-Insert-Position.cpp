/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

class Solution {
public:
    int searchInsert(int A[], int n, int target) { 
        int cnt = n;
        int index = 0,i;
        while(cnt){  //perfect binary search
        	int step = cnt / 2;
        	i = index + step;
        	if(A[i] < target){     
        		index = ++i;
        		cnt -= step+1;
        	}
        	else
        		cnt = step;
        }
		return index;
    }
};
