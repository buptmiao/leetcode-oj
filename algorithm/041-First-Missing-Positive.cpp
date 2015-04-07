/*

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.

*/

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        for(int i = 0;i < n;){ 
        	if(A[i] > 0 && A[i] < n && A[i] != A[A[i]-1]){ //交换条件
        		int tmp = A[A[i]-1];
        		A[A[i]-1] = A[i];
        		A[i] = tmp;
        		if(A[i] > i) i++; //防止把后面小的提到前面，即，A[i]<=i,所以i不应该++.
        	}
			else i++;
        }
        int res = 1;
		for(int j = 0;j<n;j++){
			if(A[j] == res)
				res++;
		}
		return res;
    }
};
