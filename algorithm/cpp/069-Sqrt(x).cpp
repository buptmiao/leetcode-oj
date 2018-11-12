/*
Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

Example 1:

Input: 4
Output: 2
Example 2:

Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.
*/

class Solution {
public:
    int sqrt(int x) {
		if(x == 0) return 0;
		return findtwo(x,1,65536);
    }
	int findtwo(unsigned int x,unsigned left,int right){
		auto mid = (left + right)>>1;
		if(mid*mid <= x && (mid+1)*(mid+1) > x)
			return mid;
		else if(mid*mid > x)
			return findtwo(x,left,mid);
		else
			return findtwo(x,mid,right);
			
	}
};
