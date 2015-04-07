/*

Implement pow(x, n).

*/

class Solution {
public:
    double pow(double x, int n) {
 		if(n == 0) return x != 0.0;
 		if(n < 0) return n != INT_MIN ? 1/pow(x,-n) : 1/(x*pow(x,-(n+1)));
 		if(n % 2) return x * pow(x,n-1);
 		double temp = pow(x,n/2);
 		return temp * temp;
    }
};