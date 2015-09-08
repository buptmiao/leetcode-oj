/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/
class Solution {
public:
    int search(int A[], int n, int target) {
        return findtwo(A,0,n-1,target);
    }
    int findtwo(int A[],int left,int right,int target) { 
    	if(left +2 > right){
			if(target == A[left]) return left;
			if(target == A[right])return right;
    		return -1;
		}
    	int mid = (left+right) /2;
    	if(A[left]<=target && target <= A[mid] || A[mid] <= A[left] && (target <= A[mid] || target >= A[left]))
    		return findtwo(A,left,mid,target);
    	else
    		return findtwo(A,mid,right,target);
    }
};