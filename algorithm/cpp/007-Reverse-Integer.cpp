/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/
class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN)
        	return 0;
        if(x < 0)
        	return -reverse(-x);
        int num = x;
        long long ret = 0;
        while(num){ 
        	ret = ret*10+num%10;
        	num/=10;
        }
        if(ret > INT_MAX) 
        	return 0;
        return ret;
    }
};