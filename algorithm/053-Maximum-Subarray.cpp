/*

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

*/

class Solution {
public:
    //Solution 1
    int maxSubArray(int A[],int n){ 
    	int res = A[0];
    	int maxv = A[0];
    	for(int i = 1;i < n;i++){ 
    		maxv = maxv >= 0 ? maxv+A[i] : A[i];
    		res = max(res,maxv);
    	}
    	return res;
    }
};



