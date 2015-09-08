/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/

class Solution {
	typedef long long ll;
public:
    int divide(int dividend, int divisor) {
		ll ret=0,d1 = abs((ll)dividend),d2 = abs((ll)divisor);
		if(divisor == 0 || dividend == 0 || d1 < d2)
			return 0;
		while(d1 >= d2)
		{
			int m = binary(d1,d2);
			ret += ((ll)1<<m);
			d1 -= (d2 << m);
		}
		if((dividend > 0 && divisor <0) || (dividend < 0 && divisor > 0) )
			return -ret;
		if(ret == (ll)2147483648)
			return INT_MAX;
		return (int)ret;
    }
	int binary(long long div1,long long div2) // eg  div1 = 42,div2 = 5 ,return 8;div1 = 7,div2 = 2,return 2;
	{
		int i = 0;
		while(div2 <= div1){
			i ++;
			div2 <<= 1;
		}
		return i-1;
	}
};