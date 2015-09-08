/*
Determine whether an integer is a palindrome. Do this without extra space
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int p = x,q = 0;
        while(p>=10){ 
        	q += q*10+p%10;
        	p /= 10;
        }
        return q == x / 10 && p == x % 10;
    }
};