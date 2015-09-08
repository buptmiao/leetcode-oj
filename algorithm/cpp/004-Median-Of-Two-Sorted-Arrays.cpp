
/*
There are two sorted arrays A and B of size m and n respectively.
Find the median of the two sorted arrays. 
The overall run time complexity should be O(log (m+n)).
*/

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int k = m+n;
		if (k & 0x01)
			return findKth(A,m,B,n,k/2+1);
		else
			return (findKth(A,m,B,n,k/2) + findKth(A,m,B,n,k/2+1))/2;
    }
	double findKth(int A[],int m,int B[],int n,int k)
	{
			if(m < n)
				return findKth(B,n,A,m,k);
			if(n == 0)
				return A[k-1];
			if(k <= 1)
				return min(A[0],B[0]);
			int Bmid = min(k/2,n);
			int Amid = k - Bmid; 
			if(A[Amid-1] > B[Bmid-1])  //把B的前Bmid个元素排除
				return findKth(A,m,B+Bmid,n-Bmid,k-Bmid);
			else if(A[Amid-1] < B[Bmid-1]) //把A的前Amid个元素排除
				return findKth(A+Amid,m-Amid,B,n,k-Amid);
			else
				return A[Amid-1];  //相等的话就是第K个元素
				
	}
};